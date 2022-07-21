
#include "STCore/st_core_actor.h"
#include "st_core_actor_impl.h"

// namespace
namespace st_core {

CActor::CActor(const char * ptName) : m_pActorImpl(NULL)
{
    m_pActorImpl = new CActorImpl(ptName, this);
}

CActor::~CActor( void )
{
    delete m_pActorImpl;
    m_pActorImpl = NULL;
}

bool CActor::Start( void )
{
    if (m_pActorImpl == NULL)
    {
        return false;
    }
    return m_pActorImpl->Start();
}

void CActor::Terminate()
{
    if (m_pActorImpl == NULL)
    {
        return ;
    }
    return m_pActorImpl->Terminate();
}

const char* CActor::GetName()
{
    if (m_pActorImpl == NULL)
    {
        return NULL;
    }
    return m_pActorImpl->GetName();
}

const int64_t CActor::GetThreadId()
{
    if (m_pActorImpl == NULL)
    {
        return -1;
    }
    return m_pActorImpl->GetThreadId();
}

bool CActor::IsShutdown()
{
    if (m_pActorImpl == NULL)
    {
        return false;
    }
    return m_pActorImpl->IsShutdown();
}

}  // namespace

