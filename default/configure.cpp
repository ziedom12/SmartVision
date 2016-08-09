#include "acquisitionModule.h"
#include "acquisitionModule.h"
#include "observerDelegator.h"
#include "window.h"
#include "configurator.h"

using namespace SmartVision ;
void configure(char *filename){
	string fileName(filename);
	configurator conf(fileName);
	conf.addProperty(string("acquisition"),string("method"),STREAM);
	conf.addProperty(string("acquisition"),string("cameraId"),0);
	conf.addProperty(string("acquisition"),string("filePath"),string("/home/ziedom/Desktop/test.mp4"));
	conf.write();
}


int main(int argc, char** argv)
{
	if(argc!=2) {
		cout << "Usage:"<<endl << argv[0] <<" path_to_configuration_file"<<endl ;	
		return -1;
	}

	configure(argv[1]);
    return 0;
}
