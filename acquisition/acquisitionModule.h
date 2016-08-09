// If the headerfile has been already loaded by the precompiler do not load it
#ifndef _ACQUISITION_MODULE_
#define _ACQUISITION_MODULE_
// <> system  libraries, ".h" other libraries
#include "observable.h"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;
namespace SmartVision{ 
	enum method_type {CAMERA , STREAM} ;
// enable polymorphic inheritance : use public key word after the inheritance symbol ":"
	class acquisitionModule :public observable<Mat> {
		VideoCapture* capture;	
	public :
		acquisitionModule(method_type m , int id = 0 , string file=""){
			switch(m){
				case CAMERA :
					capture =new VideoCapture(id) ;
				break ;
				case STREAM :
					capture =new VideoCapture(file) ;
			 }		
		}
		~acquisitionModule(){ 
			delete capture;
		}
		void acquire(){
			cout<< "Starting acquisitionModule ...\n";
			if(!capture->isOpened()){
				cout<<"You have no camera in your system\n";
				exit(-1);
			}
		   	 Mat img;
		   	 while(1){
				(*capture)>>img;
				this->notifyObservers(img);			
				if(waitKey(60)>=0){
				    cout<<"exit request \n";
				    break;
				}
		
			}
			cout<< "AcquisitionModule terminated!\n";	
		}

	};
}

#endif
