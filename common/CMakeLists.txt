
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(common  observable.h observerDelegator.h window.h configurator.cpp)
# link the library with c++ 
set_target_properties(common PROPERTIES LINKER_LANGUAGE CXX) 

