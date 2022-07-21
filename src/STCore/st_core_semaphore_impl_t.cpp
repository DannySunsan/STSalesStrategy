#include "st_core_semaphore_impl_t.h"

#ifdef _STCORE_OS_LINUX_
#include<time.h>
#endif

// namespace
namespace st_core {

    /////////////////////////////////////////////////////////////////
    ///  \brief Constructor, Create a instance of the ACE Semaphore Implementation
    ///
    ///  \param[in]    iCount: the times of the semaphore being acqired
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    SemaphoreImpl::SemaphoreImpl(int64_t iCount, int64_t iMaxCount)
#ifdef _STCORE_OS_LINUX_
    : m_iCount(iCount)
#endif
{
#ifndef _STCORE_OS_LINUX_
    m_oSemaphore = CreateSemaphore(0, (LONG)iCount, (LONG)iMaxCount, 0);
#else
    m_iMaxCount = iMaxCount;
    sem_init(&m_oSemaphore, 0, iCount);
#endif
}

SemaphoreImpl::~SemaphoreImpl( void )
{
#ifndef _STCORE_OS_LINUX_
    CloseHandle(m_oSemaphore);
#else
    sem_destroy(&m_oSemaphore);
#endif
}

/////////////////////////////////////////////////////////////////
///  \brief Acquire the ACE Semaphore, continue if get the semaphore
///
///  \param[in]    iTimeout: ms. -1 forever waitting; 0 no waitting;
///  \param[out]   None
///  \return       bool: true if get the semaphore;false if fail or timeout
///  \pre \e
/////////////////////////////////////////////////////////////////
bool SemaphoreImpl::Acquire(int64_t iTimeout)
{
    bool bRet = false;

#ifndef _STCORE_OS_LINUX_
    switch (iTimeout)
    {
        // Wait forever
    case -1:
        bRet = WaitForSingleObject(static_cast<HANDLE>(m_oSemaphore), INFINITE) == 0x00000000L;
        break;

        // No wait
    case 0:
        bRet = WaitForSingleObject(static_cast<HANDLE>(m_oSemaphore), 0) == 0x00000000L;
        break;

        // wait for timeout
    default:
        bRet = (WAIT_TIMEOUT != WaitForSingleObject(m_oSemaphore, (DWORD)iTimeout));
        break;
    }
#else
    struct timespec oTimeSpec;
    switch (iTimeout)
    {
        // Wait forever
    case -1:
        bRet = sem_wait(const_cast<sem_t*>(&m_oSemaphore)) == 0;
        break;

        // No wait
    case 0:
        bRet = sem_trywait(const_cast<sem_t*>(&m_oSemaphore)) == 0;
        break;

        // wait for timeout
    default:
        if (clock_gettime(CLOCK_REALTIME, &oTimeSpec) == 0)
        {
            // Calc the timeout time
            int64_t iTime = oTimeSpec.tv_nsec + iTimeout * 1000000;
            oTimeSpec.tv_sec += iTime / 1000000000;
            oTimeSpec.tv_nsec = iTime % 1000000000;
            bRet = (0 == sem_timedwait(&m_oSemaphore, &oTimeSpec));
        }
        break;
    }
    if (bRet)
    {
        -- m_iCount;
    }
#endif

    return bRet;
}

/////////////////////////////////////////////////////////////////
///  \brief Release the Semaphore
///
///  \param[in]    None
///  \param[out]   None
///  \return       None
///  \pre \e
/////////////////////////////////////////////////////////////////
bool SemaphoreImpl::Release( void )
{
#ifndef _STCORE_OS_LINUX_
    return ReleaseSemaphore(static_cast<HANDLE>(m_oSemaphore), 1, 0) != 0;
#else
    bool bRet = false;
    if (m_iCount < m_iMaxCount)
    {
        ++ m_iCount;
        bRet = sem_post(&m_oSemaphore) == 0;
    }
    return bRet;
#endif
}

} // namespace
