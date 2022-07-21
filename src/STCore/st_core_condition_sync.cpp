#include "STCore/st_core_condition_sync.h"

// namespace
namespace st_core {

ConditionSync::ConditionSync( void )
: m_bCondition(false), m_iNumOfPendings(0), m_oSemaphore(0)
{

}

ConditionSync::~ConditionSync( void )
{

}

/////////////////////////////////////////////////////////////////
///  \brief Start a thread
///
///  \param[in]    iTimeout: -1 - wait forever, other wait for the time
///  \param[out]   None
///  \return       bool: the resulte of starting the thread
///  \pre \e
/////////////////////////////////////////////////////////////////
bool ConditionSync::Wait(int64_t iTimeout)
{
    m_oMutex.Acquire();

    bool bWait = !m_bCondition;

    if (bWait)
    {
        ++ m_iNumOfPendings;
    }

    m_oMutex.Release();

    bool bRet = true;

    if (bWait)
    {
        bRet = m_oSemaphore.Acquire(iTimeout);

        if (! bRet)
        {
            m_oMutex.Acquire();
            -- m_iNumOfPendings;
            m_oMutex.Release();
        }
    }

    return bRet;
}

/////////////////////////////////////////////////////////////////
///  \brief Signal a waitting client
///
///  \param[in]    bCondition:
///  \param[out]   None
///  \return       None
///  \pre \e
/////////////////////////////////////////////////////////////////
void ConditionSync::Signal(bool bCondition)
{
    m_oMutex.Acquire();

    m_bCondition = bCondition;
    if (m_bCondition)
    {
        if (m_iNumOfPendings > 0)
        {
            //if there is thread pending, release it
            //NOTE: if there are more than one thread, the sequence of release rely on OS schedule scheme
            m_oSemaphore.Release();
            -- m_iNumOfPendings;
        }
    }

    m_oMutex.Release();
}

/////////////////////////////////////////////////////////////////
///  \brief Signal all the waitting clients
///
///  \param[in]    bCondition:
///  \param[out]   None
///  \return       int32_t: the number of the clients released
///  \pre \e
/////////////////////////////////////////////////////////////////
int64_t ConditionSync::Broadcast(bool bCondition)
{
    int64_t iNumOfPendings = m_iNumOfPendings;

    m_oMutex.Acquire();

    m_bCondition = bCondition;
    if (m_bCondition)
    {
        for (; m_iNumOfPendings > 0; -- m_iNumOfPendings)
        {
            m_oSemaphore.Release();
        }
    }

    m_oMutex.Release();

    return iNumOfPendings;
}

} // namespace
