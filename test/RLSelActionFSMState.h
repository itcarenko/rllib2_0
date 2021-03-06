#ifndef RLSELFACTIONFSMSTATE_H
#define RLSELFACTIONFSMSTATE_H

#include "RLFSMState.h"

namespace RLFSM_NMSPC
{
	/*in this state the action is selected */
	template<typename Ty1, typename Ty2>
	class RLSelActionFSMState : public RLFSMState<Ty1, Ty2>
	{
	public:
		RLSelActionFSMState(RLFSMStatesEnum);
		/*in this state the action is selected */

		virtual unsigned int Do(RLFSM<Ty1, Ty2>*) override;
	};

	template<typename Ty1, typename Ty2>
	RLSelActionFSMState<Ty1, Ty2>::RLSelActionFSMState(RLFSMStatesEnum stateName)
	{
		this->thisStateName = stateName;
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLSelActionFSMState<Ty1, Ty2>::Do(RLFSM<Ty1, Ty2>* rlfsm)
	{
		//returns a value to choose the next fsm state
		return rlfsm->GetRLEntity()->SelAction();
	}
}

#endif