#ifndef RLOBSRVCURRENTFSMSTATE_H
#define RLOBSRVCURRENTFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state the current rlstate is observed */
	template<typename Ty1, typename Ty2>
	class RLObsrvCurrentFSMState : public RLFSMState<Ty1, Ty2>
	{
	public:
		RLObsrvCurrentFSMState(RLFSMStatesEnum);
		/*in this state the current rl_state is fetched from the environment
		and stored in the rl_agent*/

		virtual unsigned int Do(RLFSM<Ty1, Ty2>*) override;
	};

	template<typename Ty1, typename Ty2>
	RLObsrvCurrentFSMState<Ty1, Ty2>::RLObsrvCurrentFSMState(RLFSMStatesEnum stateName)
	{
		this->thisStateName = stateName;
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLObsrvCurrentFSMState<Ty1, Ty2>::Do(RLFSM<Ty1, Ty2>* rlfsm)
	{
		//returns a value to choose the next fsm state
		return rlfsm->GetRLEntity()->ObsrvCurrState();
	}
}

#endif