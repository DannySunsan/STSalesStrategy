#ifndef __ST_CORE_SEMAPHORE_H__
#define __ST_CORE_SEMAPHORE_H__

#include "STCore/st_core_semaphore_t.h"
#include "STCore/st_core_os_type.h"

// namespace
namespace st_core {

/// \class CSemaphore STCORE_semaphore.h
/// \brief define CSemaphore
class STCORE_EXPORT CSemaphore
{

public:
    virtual ~CSemaphore();

    CSemaphore();
    int32_t Wait(int32_t iMilliseconds);
    void Trigger();

private:
    Semaphore m_oSemaphore;

};

}  // namespace

#endif // __ST_CORE_SEMAPHORE_H__

