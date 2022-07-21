#include "STCore/st_core_return_code.h"
#include "STCore/st_core_semaphore.h"

// namespace
namespace st_core {

CSemaphore::CSemaphore() : m_oSemaphore(0, 1)
{
}

CSemaphore::~CSemaphore()
{
}

int32_t CSemaphore::Wait(int32_t iMilliseconds)
{
    if ( !m_oSemaphore.Acquire(iMilliseconds) )
    {
        return STCORE_FAILED;
    }
    return STCORE_OK;
}

void CSemaphore::Trigger()
{
    m_oSemaphore.Release();
}

}  // namespace
