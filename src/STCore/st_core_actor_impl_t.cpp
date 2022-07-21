#include <stdio.h>
#include <string.h>

#include "st_core_actor_impl_t.h"
#include "STCore/st_core_actor_t.h"

// namespace
namespace st_core {

// WIN32 system
#ifndef _STCORE_OS_LINUX_
static unsigned __stdcall ThreadFunc(void * ptr)
{
    ActorImpl * pImpl = (ActorImpl *)ptr;
    pImpl->svc();
    return 0;
}
#else // Linux system
static void * ThreadFunc(void * ptr)
{
    ActorImpl * pImpl = (ActorImpl *)ptr;
    pImpl->svc();
    return NULL;
}
#endif


ActorImpl::ActorImpl(const char * ptName, Actor * pActor) :
    m_pActor(NULL),
    m_bStarted(false)
{
    m_pActor = pActor;
    memset(acName, 0, sizeof(acName));
    if ( ptName )
    {
        snprintf(acName, sizeof(acName), "%s", ptName);
    }
}

ActorImpl::~ActorImpl( void )
{
}

/////////////////////////////////////////////////////////////////
///  \brief  Start the thread via the ACE component
///
///  \param[in]    None
///  \param[out]   None
///  \return       bool: true - successful  false - fail
///
/////////////////////////////////////////////////////////////////
bool ActorImpl::Start( void )
{
#ifdef _STCORE_OS_LINUX_
    if ( 0!=pthread_create(&m_Thread, NULL, ThreadFunc, this) )
    {
        return false;
    }
#else
    m_hThread = (HANDLE)_beginthreadex( 0, 0, ThreadFunc, this, 0, 0 );
    if( 0==m_hThread )
    {
        return false;
    }
#endif
    m_bStarted = true;
    return true;
}

void ActorImpl::Terminate( void )
{

    if (m_bStarted)
    {
        m_bStarted = false;
#ifdef _STCORE_OS_LINUX_
        void* thread_result;
        pthread_cancel(m_Thread);
        pthread_join(m_Thread, &thread_result);
#else
        ::WaitForSingleObject(m_hThread, INFINITE);
        ::CloseHandle(m_hThread);
#endif
    }
}

const char* ActorImpl::GetName()
{
    return acName;
}

/////////////////////////////////////////////////////////////////
///  \brief  The main loop of the actor
///
///  \param[in]    None
///  \param[out]   None
///  \return       None
///
/////////////////////////////////////////////////////////////////
void ActorImpl::svc( void )
{
    if (m_pActor != NULL)
    {
        m_pActor->svc();
    }
}

} // namespace
