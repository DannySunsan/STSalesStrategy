#include "STCore/st_core_actor_t.h"

#include "st_core_actor_impl_t.h"

// namespace
namespace st_core {

Actor::Actor(const char * ptName)
{
    // Create an instance
    m_pImpl = new ActorImpl(ptName, this);
}

Actor::~Actor( void )
{
    // Delete the implemtation instance
    if (m_pImpl != NULL)
    {
        delete m_pImpl;
        m_pImpl = NULL;
    }
}

bool Actor::Start( void )
{
    if (m_pImpl == NULL)
    {
        return false;
    }
    // Call the interface of the implemtation instance
    return m_pImpl->Start();
}

void Actor::Terminate( void )
{
    if (m_pImpl == NULL)
    {
        return ;
    }
    // Call the interface of the implemtation instance
    return m_pImpl->Terminate();
}

const char* Actor::GetName()
{
    if (m_pImpl == NULL)
    {
        return NULL;
    }
    // Call the interface of the implemtation instance
    return m_pImpl->GetName();
}

} // namespace
