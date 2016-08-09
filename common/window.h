#ifndef _WINDOW_
#define _WINDOW_
#include "opencv2/opencv.hpp"
#include "observable.h"

using namespace cv ;

namespace SmartVision {
	class window{
		string name ;
	public :
		window(string nname):name(nname){
			namedWindow(name);		
		}
		void update(observable<Mat> &obs , const Mat& im){
			imshow(name,im);
		}
	} ;
}


#endif


