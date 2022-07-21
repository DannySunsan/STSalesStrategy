#include "STCore/st_core_mutex.h"

#include <stdio.h>

#include "st_core_mutex_impl_t.h"

// namespace
namespace st_core {

Mutex::Mutex( void ) : m_pImpl(NULL)
{
    // Create an instance of boost implmentation
    m_pImpl = new MutexImpl();
}

Mutex::~Mutex( void )
{
    if (m_pImpl != NULL)
    {
        delete m_pImpl;
        m_pImpl = NULL;
    }
}

/////////////////////////////////////////////////////////////////
///  \brief Acquire the mutex, continue if get the mutex
///
///  \param[in]    None
///  \param[out]   None
///  \return       None
///  \pre \e
/////////////////////////////////////////////////////////////////
bool Mutex::Acquire( void )
{
    if (m_pImpl != NULL)
    {
        return m_pImpl->Acquire();
    }

    return false;
}


bool Mutex::TryAcquire( void )
{
    if (m_pImpl != NULL)
    {
        return m_pImpl->TryAcquire();
    }

    return false;
}

/////////////////////////////////////////////////////////////////
///  \brief Release the mutex
///
///  \param[in]    None
///  \param[out]   None
///  \return       None
///  \pre \e
/////////////////////////////////////////////////////////////////
bool Mutex::Release( void )
{
    if (m_pImpl != NULL)
    {
        return m_pImpl->Release();
    }
    return false;
}

} // namespace
