#ifndef _OBSERVER_DELEGATE_
#define _OBSERVER_DELEGATE_

#include "observable.h"


namespace SmartVision {

	// Delegates the process of the event to the actual observer(eventTarget) by assigning itself as an observer of the actual observable(eventSource)
	// This pattern ensures a loosely coupling between observer and observable : neither is aware about the link between them 
	// Delegate is the actual type of the actual observer 
    template <typename Event, typename Delegate>
    class observerDelegator : public observer<Event> {
        observable<Event> *eventSource;
        Delegate *eventTarget;
    public:
        observerDelegator(observable<Event> &obs,Delegate &delegate):eventSource(&obs),eventTarget(&delegate){
            eventSource->addObserver(*this);
        }
        ~observerDelegator(){
            eventSource->deleteObserver(*this);
        }
        void update(observable<Event> &obs,const Event &event){
            eventTarget->update(obs,event);
        }

    };

}

#endif
