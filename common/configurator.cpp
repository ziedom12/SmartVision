

#include "configurator.h"
#include <sstream>
namespace SmartVision {
	void configurator::addKeys(string module ,const vector<string> & keys) {
		for(auto s : keys) properties[module][s]="";
	}
	void configurator::read(){
		fsr=new FileStorage(fileName , FileStorage::READ) ;
		// here we have the keys of the map (addKeys), now we are looking for the values
		for(auto it=properties.begin(); it != properties.end() ; it++){
			//m is a FileNode			
			auto m = (*fsr)[it->first];
			for(auto itt=it->second.begin(); itt != it->second.end() ; itt++){
				itt->second = static_cast<string>(m[itt->first]);				
			}
		}
		fsr->release();
		delete fsr;
	}	
	void configurator::write() {
		fsw=new FileStorage(fileName , FileStorage::WRITE) ;
		// writing on a buffer 
		for(auto it=properties.begin(); it != properties.end() ; it++){
			// the FileStorage understand that it's a mapping ...
			(*fsw) << it->first << "{";
			for(auto itt=it->second.begin(); itt != it->second.end() ; itt++){
				// ... So write the pair key-value this way :p 
				(*fsw)<< itt->first << itt->second;
			}
			(*fsw) << "}";
		}
		// flush the buffer in the file
		fsw->release();
		delete fsw;
	}
	bool configurator::removeProperty(string moduleName , string propertyName){
		return properties[moduleName].erase(propertyName);
	}
}

