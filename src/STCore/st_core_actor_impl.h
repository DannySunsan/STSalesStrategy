#ifndef __ST_CORE_ACTOR_IMPL_H__
#define __ST_CORE_ACTOR_IMPL_H__

#include "STCore/st_core_os_type.h"
#include "STCore/st_core_semaphore.h"

#ifdef _STCORE_OS_WIN_
#include <windows.h>
#include <process.h>
#else
#include <pthread.h>
#endif

namespace st_core {

class CActor;

class CActorImpl
{
public:
    CActorImpl(const char* ptName, CActor * pActor);
    virtual ~CActorImpl();
    bool Start();
    virtual void Terminate();
    virtual void svc( void );
    const char* GetName();
    const int64_t GetThreadId();
    void SetThreadId(int64_t iThreadId);
    CSemaphore& GetSemExit();
    bool IsShutdown();

protected:
    CActor* m_pActor;

private:
    bool m_bShutdown;
    CSemaphore m_SemExit;
    bool m_bStarted;
#ifdef _STCORE_OS_WIN_
    HANDLE m_Thread;
#else
    pthread_t m_Thread;
#endif
    int64_t m_iThreadId;
    char m_strName[64];
};

}  // namespace

#endif // __ST_CORE_ACTOR_IMPL_H__

