#ifndef _OBSERVABLE_
#define _OBSERVABLE_

#include <set>
#include <iostream>
using namespace std;

namespace SmartVision {
    template <typename T>
    class observable; //forward declaration of Observable class

    template <typename T>
    class observer { //declaration and definition of the Observer interface
    public:
        virtual ~observer(){} //virtual destruction
        virtual void update(observable<T> &,const T &) = 0; // The observable and the event (the image in the case of acquisition)
    }; //end of Observer interface

    template <typename T>
    class observable {//declaration and definition of Observable class
    private:
        std::set<observer<T>*>  observers; 
        bool			isChanged;
    protected:
        void setChanged(){
            isChanged = true;
        }
        void clearChanged(){
            isChanged = false;
        }
    public:
        observable():isChanged(false){}
        bool hasChanged(){
            return isChanged;
        }
        void addObserver(observer<T> &o){
            observers.insert(&o);
        }
        void deleteObserver(observer<T> &o){
            observers.erase(&o);
        }
        unsigned long countObservers(){
            return observers.size();
        }
        void deleteObservers(){
            observers.clear();
        }
        void notifyObservers(){
            notifyObservers(nullptr);
        }
        void notifyObservers(const T &arg){
            clearChanged();
            for(auto obs : observers){
                obs->update(*this,arg);
            }
        }
    };//end of class Observable

}//end of namespace

#endif
