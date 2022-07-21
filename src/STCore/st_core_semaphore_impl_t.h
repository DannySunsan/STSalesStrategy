#ifndef ST_CORE_SEMAPHORE_IMPL_T_H_
#define ST_CORE_SEMAPHORE_IMPL_T_H_

#include "STCore/st_core_os_type.h"

#ifndef _STCORE_OS_LINUX_
#include <windows.h>
#else
#include <semaphore.h>
#endif


// namespace
namespace st_core {

class SemaphoreImpl
{
public:
    /////////////////////////////////////////////////////////////////
    ///  \brief Constructor, Create a instance of the ACE Semaphore Implementation
    ///
    ///  \param[in]    iCount: the times of the semaphore being acqired
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    SemaphoreImpl(int64_t iCount = 1, int64_t iMaxCount = 0x7FFFFFFF);

    /////////////////////////////////////////////////////////////////
    ///  \brief Deconstructor, Release the instance
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual ~SemaphoreImpl( void );

    /////////////////////////////////////////////////////////////////
    ///  \brief Acquire the ACE Semaphore, continue if get the semaphore
    ///
    ///  \param[in]    iTimeout: ms. -1 forever waitting; 0 no waitting;
    ///  \param[out]   None
    ///  \return       bool: true if get the semaphore;false if fail or timeout
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Acquire(int64_t iTimeout);

    /////////////////////////////////////////////////////////////////
    ///  \brief Release the Semaphore
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Release(void);

private:

#ifndef _STCORE_OS_LINUX_
    HANDLE m_oSemaphore; /**< Win semaphore*/
#else
    sem_t m_oSemaphore; /**< Posix semaphore*/
    int64_t m_iMaxCount;
    int64_t m_iCount;
#endif
};

} // namespace

#endif // UMR_SEMAPHORE_ACE_IMPL_H_
