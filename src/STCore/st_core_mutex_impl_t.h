#ifndef UMR_MUTEX_IMPL_H_
#define UMR_MUTEX_IMPL_H_

#include "STCore/st_core_os_type.h"

#ifndef _STCORE_OS_LINUX_
#include <windows.h>
#else
#include <pthread.h>
#endif

// namespace
namespace st_core {

class MutexImpl
{
public:
    /////////////////////////////////////////////////////////////////
    ///  \brief Constructor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    MutexImpl(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Deconstructor, Release the instance
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual ~MutexImpl(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Acquire the mutex
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Acquire(void);

    bool TryAcquire(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Relase the mutex
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Release( void );

private:
#ifndef _STCORE_OS_LINUX_
    CRITICAL_SECTION m_oMutex; /**< Window mutex */
#else
    pthread_mutex_t m_oMutex; /**< posix mutex */
#endif
    bool m_bLocked;
};

} // namespace

#endif // UMR_MUTEX_ACE_IMPL_H_
