#include "STCore/st_core_mutex.h"

// namespace
namespace st_core {

CMutex::CMutex() : m_oMutex()
{
}

CMutex::~CMutex()
{
}

void CMutex::Lock()
{
    m_oMutex.Acquire();
}


void CMutex::UnLock()
{
    m_oMutex.Release();
}

}  // namespace

