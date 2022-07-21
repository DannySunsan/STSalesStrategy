#ifndef ST_CORE_CONDITION_SYNC_H_
#define ST_CORE_CONDITION_SYNC_H_

#include "STCore/st_core_os_type.h"
#include "STCore/st_core_semaphore_t.h"
#include "STCore/st_core_mutex_t.h"

// namespace
namespace st_core {

class STCORE_EXPORT ConditionSync
{
public:
    /////////////////////////////////////////////////////////////////
    ///  \brief constructor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    ConditionSync(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief deconstructor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual ~ConditionSync(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Start a thread
    ///
    ///  \param[in]    iTimeout: -1 - wait forever, other wait for the time
    ///  \param[out]   None
    ///  \return       bool: the resulte of starting the thread
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Wait(int64_t iTimeout = -1);

    /////////////////////////////////////////////////////////////////
    ///  \brief Signal a waitting client
    ///
    ///  \param[in]    bCondition:
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    void Signal(bool bCondition = true);

    /////////////////////////////////////////////////////////////////
    ///  \brief Signal all the waitting clients
    ///
    ///  \param[in]    bCondition:
    ///  \param[out]   None
    ///  \return       int32_t: the number of the clients released
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    int64_t Broadcast(bool bCondition = true);

private:

    bool m_bCondition;
    int64_t m_iNumOfPendings;
    Semaphore m_oSemaphore;
    Mutex m_oMutex;
};

} // namespace

#endif // UMR_CONDITION_SYNC_H_
