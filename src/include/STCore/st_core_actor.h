#ifndef __ST_CORE_ACTOR_H__
#define __ST_CORE_ACTOR_H__

#include "STCore/st_core_os_type.h"

namespace st_core {

class CActorImpl;

class STCORE_EXPORT CActor
{
public:
    CActor(const char* ptName);
    virtual ~CActor();
    bool Start();
    virtual void Terminate();
    virtual void svc() = 0;
    const char* GetName();
    const int64_t GetThreadId();
    bool IsShutdown();

private:
    CActorImpl* m_pActorImpl;
};

}  // namespace

#endif // __ST_CORE_ACTOR_H__

