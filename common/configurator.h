#ifndef _CONFIGURATOR_
#define _CONFIGURATOR_

#include "opencv2/core/core.hpp"
#include <map>
#include <string>
#include <cstddef>

using namespace std;
using namespace cv;

namespace SmartVision {
    class configurator {
	string fileName;
	FileStorage *fsr,*fsw;
	map<string,map<string,string> > properties;
	public :
        configurator(string name):fileName(name),fsr(nullptr),fsw(nullptr){}
	// populate the map properties with dummy values in order to prepare the read operation
	void addKeys(string module ,const vector<string> & keys) ;
	// read all properties from the configuration file
	void read() ;	
	// write all properties in the configuration file
	void write() ;	
	// template method must be defined in the header file to avoid linker problems
	template<typename T> 
	void addProperty(string moduleName , string propertyName , T value){
		stringstream ss;
		ss << value;
		ss >> properties[moduleName][propertyName] ;
	}
	bool removeProperty(string moduleName , string propertyName);
	// template method must be defined in the header file to avoid linker problems	
	template<typename T> 
	void getProperty(string moduleName , string propertyName ,T& ret){		
		stringstream ss(properties[moduleName][propertyName]) ;
		ss >> ret ;
	}
    };

}

#endif
