//////////////////////////////////////////////////////////////////////////
///
///  Copyright, (c) Shanghai United Imaging Health_care Inc., 2011
#ifndef ST_CORE_ACTOR_IMPL_T_H_
#define ST_CORE_ACTOR_IMPL_T_H_

#include "STCore/st_core_os_type.h"

#ifndef _STCORE_OS_LINUX_
#include <windows.h>
#include <process.h>
#else
#include <pthread.h>
#endif

// namespace
namespace st_core {

class Actor;

class ActorImpl
{
public:
    ActorImpl(const char * ptName, Actor * pActor);

    virtual ~ActorImpl( void );

    /////////////////////////////////////////////////////////////////
    ///  \brief  Start the thread
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       bool: true - successful  false - fail
    ///
    /////////////////////////////////////////////////////////////////
    bool Start(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Start a thread
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    void Terminate(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief get name of actor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       const char* name
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    const char* GetName();

    /////////////////////////////////////////////////////////////////
    ///  \brief  The main loop of the actor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///
    /////////////////////////////////////////////////////////////////
    virtual void svc( void );

protected:
    ///< The pointer of the Actor
    Actor* m_pActor;

private:
    ///< If the thread being started
    bool m_bStarted;

#ifndef _STCORE_OS_LINUX_
    HANDLE m_hThread;
#else
    pthread_t m_Thread;
#endif
    char acName[64];
};

} // namespace

#endif // UMR_ACTOR_IMPL_H_
