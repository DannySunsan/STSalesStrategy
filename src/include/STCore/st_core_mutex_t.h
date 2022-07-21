#ifndef ST_CORE_MUTEX_T_H_
#define ST_CORE_MUTEX_T_H_

#include "STCore/st_core_os_type.h"

// namespace
namespace st_core {

class MutexImpl;

class STCORE_EXPORT Mutex
{
public:
    /////////////////////////////////////////////////////////////////
    ///  \brief Constructor, Create a instance of the Mutex Implementation
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    Mutex(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Deconstructor, Release the instance
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual ~Mutex(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Acquire the mutex, continue if get the mutex
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
    MutexImpl* m_pImpl;
};

} // namespace

#endif // UMR_MUTEX_H_
