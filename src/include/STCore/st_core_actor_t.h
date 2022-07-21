#ifndef ST_CORE_ACTOR_T_H_
#define ST_CORE_ACTOR_T_H_

#include <stdio.h>
#include <stdint.h>

#include "STCore/st_core_os_type.h"

// namespace
namespace st_core {

class ActorImpl;

class STCORE_EXPORT Actor
{
public:
    /////////////////////////////////////////////////////////////////
    ///  \brief constructor
    ///
    ///  \param[in]    ptName: the name of the Actor
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    Actor(const char * ptName = NULL);

    /////////////////////////////////////////////////////////////////
    ///  \brief deconstructor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual ~Actor();

    /////////////////////////////////////////////////////////////////
    ///  \brief Start a thread
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       bool: the resulte of starting the thread
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Start();

    /////////////////////////////////////////////////////////////////
    ///  \brief Start a thread
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    void Terminate();

    /////////////////////////////////////////////////////////////////
    ///  \brief get name of actor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       const char* name
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    const char* GetName();

    /////////////////////////////////////////////////////////////////
    ///  \brief The main loop of the Actor. The method should be overload
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       void
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual void svc() = 0;

private:
    ActorImpl* m_pImpl;
};

} // namespace

#endif // UMR_ACTOR_H_
