#include <stdio.h>
#include "STCore/st_core_semaphore.h"
#include "st_core_semaphore_impl_t.h"

// namespace
namespace st_core {

Semaphore::Semaphore(int64_t iCount, int64_t iMaxCount) : m_pImpl(NULL)
{
    // Create an instance
    m_pImpl = new SemaphoreImpl(iCount, iMaxCount);
}

Semaphore::~Semaphore( void )
{
    if (m_pImpl != NULL)
    {
        delete m_pImpl;
        m_pImpl = NULL;
    }
}

/////////////////////////////////////////////////////////////////
///  \brief Acquire the Semaphore, continue if get the Semaphore
///
///  \param[in]    iTimeout: ms. -1 forever waitting; 0 no waitting;
///  \param[out]   None
///  \return       bool: true if get the semaphore;false if fail or timeout
///  \pre \e
/////////////////////////////////////////////////////////////////
bool Semaphore::Acquire(int64_t iTimeout)
{
    if (m_pImpl == NULL)
    {
        return false;
    }
    return m_pImpl->Acquire(iTimeout);
}

/////////////////////////////////////////////////////////////////
///  \brief Release the Semaphore
///
///  \param[in]    None
///  \param[out]   None
///  \return       None
///  \pre \e
/////////////////////////////////////////////////////////////////
bool Semaphore::Release( void )
{
    if (m_pImpl == NULL)
    {
        return false;
    }
    return m_pImpl->Release();
}

} // namespace
