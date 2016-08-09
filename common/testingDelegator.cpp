#include "observerDelegator.h"
#include <iostream>

using namespace SmartVision;

class someModule : public observable<int> {

};

class someOtherModule {
public:


    void update(observable<int> &obs,const int &event){
        std::cout<<"Recieved event:"<<event<< " from unkown source"<<std::endl;
    }

};

int main(){
    someModule source;
    someOtherModule target;
    observerDelegator<int,someOtherModule> delgator(source,target);
    int x = 5;
    source.notifyObservers(x);
}
