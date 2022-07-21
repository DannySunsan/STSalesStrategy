#include <string>
#include "st_core_actor_impl.h"
#include "STCore/st_core_actor.h"
#include "STCore/st_core_utils.h"

// namespace
namespace st_core {

#ifdef _STCORE_OS_WIN_
static unsigned __stdcall ThreadFunc(void * ptr)
{
    CActorImpl* pActor = (CActorImpl*)ptr;
    pActor->SetThreadId(CUtils::GetCurrentThreadId());
    pActor->svc();
    pActor->GetSemExit().Trigger();
    return 0;
}
#else
static void * ThreadFunc(void * ptr)
{
    CActorImpl* pActor = (CActorImpl*)ptr;
    pActor->SetThreadId(CUtils::GetCurrentThreadId());
    pActor->svc();
    pActor->GetSemExit().Trigger();
    return NULL;
}
#endif

CActorImpl::CActorImpl(const char* ptName, CActor * pActor) : m_pActor(pActor), m_bShutdown(false), m_SemExit(), m_bStarted(false), m_Thread(0), m_iThreadId(-1)
{
    memset(m_strName, 0, sizeof(m_strName));
    memcpy(m_strName, ptName, sizeof(m_strName)-1);
}

CActorImpl::~CActorImpl()
{
}

bool CActorImpl::Start()
{
    if ( m_bStarted )
    {
        return true;
    }

#ifdef _STCORE_OS_LINUX_
    if ( 0!=pthread_create(&m_Thread, NULL, ThreadFunc, this) )
    {
        return false;
    }
#else
    m_Thread = (HANDLE)_beginthreadex( 0, 0, ThreadFunc, this, 0, 0 );
    if( 0==m_Thread )
    {
        return false;
    }
#endif

    m_bStarted = true;
    return true;
}

void CActorImpl::Terminate()
{
    m_bShutdown = true;

    if (m_bStarted)
    {
        m_bStarted = false;
        m_SemExit.Wait(600000); // wait until user's job done
#ifdef _STCORE_OS_LINUX_
        void* thread_result;
        pthread_cancel(m_Thread);
        pthread_join(m_Thread, &thread_result);
#else
        ::WaitForSingleObject(m_Thread, INFINITE);
        ::CloseHandle(m_Thread);
        m_Thread = 0;
#endif
    }
}

const char* CActorImpl::GetName()
{
    return m_strName;
}

const int64_t CActorImpl::GetThreadId()
{
    return m_iThreadId;
}

void CActorImpl::SetThreadId(int64_t iThreadId)
{
    m_iThreadId = iThreadId;
}

CSemaphore& CActorImpl::GetSemExit()
{
    return m_SemExit;
}

bool CActorImpl::IsShutdown()
{
    return m_bShutdown;
}

void CActorImpl::svc( void )
{
    if ( m_pActor )
    {
        m_pActor->svc();
    }
}

}  // namespace

