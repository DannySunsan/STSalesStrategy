#ifndef __ST_CORE_MUTEX_H__
#define __ST_CORE_MUTEX_H__

#include "STCore/st_core_mutex_t.h"

// namespace
namespace st_core {

class STCORE_EXPORT CMutex
{

public:
    virtual ~CMutex();

    CMutex();
    void Lock();
    void UnLock();

private:
    st_core::Mutex m_oMutex;

};

}  // namespace

#endif // __ST_CORE_MUTEX_H__

