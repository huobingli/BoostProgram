
//********************************************************
//
//       FileName:      boost_thread.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-11-30  21:06:46
//       Last Modified: 2016-11-30 21:06:46
//********************************************************
// 
#include <iostream>
#define BOOST_DATE_TIME_SOURCE
#define BOOST_THREAD_NO_LIB
#include <boost/thread.hpp>


//链接时没有 tss_cleanup_implemented(void)函数会发生link错误
//所以嵌入编译需要自行定义该函数组织link错误
#ifdef _MSC_VER
extern "C" void tss_cleanup_implemented(void) {}
#include <libs/thread/src/win32/thread.cpp>
#include <libs/thread/src/win32/tss_dll.cpp>
#include <libs/thread/src/win32/tss_pe.cpp>
#else
#include "../../boost/boost/libs/thread/src/pthread/thread.cpp"
#include "../../boost/boost/libs/thread/src/pthread/once.cpp"
#endif

using namespace std;
using namespace boost;

int main(void) {

//	this_thread::sleep_for(chrono::seconds(2));
//	cout<<"sleep 2 seconds"<<endl;

	return 0;
}

