
//********************************************************
//
//       FileName:      boost_thread1.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-01  10:38:48
//       Last Modified: 2016-12-01 10:38:48
//********************************************************
//

#include<iostream>
#include<sstream>
#include<string>
#include<boost/thread/thread.hpp>
#include<boost/thread/mutex.hpp>
#include<boost/bind.hpp>
#include<boost/thread/tss.hpp>

//using namespace std;
using namespace boost;
const int MAX_THREAD_NUM=5;

int gCount=0;
boost::mutex mutex;
boost::mutex io_mutex;
boost::thread_specific_ptr<string> ptr;

void hello(int iThreadId)
{
	{
	//boost::mutex::scoped_lock lock(io_mutex);
	std::cout << "thread " << iThreadId << ": " << "hello world boost thread."<< std::endl;
	std::cout << "thread " << iThreadId << ": " << "oh~, I am a little tired, give me 10 seconds, sleeping zzzzz..."<< std::endl;
	}

	ptr.reset(new string("hello"));

	for(int i=0; i<10; i++)
	{
		{
		//boost::mutex::scoped_lock lock(mutex);

			stringstream ss;
			ss << iThreadId;
			(*ptr) = "thread id: " + ss.str();
			std::cout << (*ptr) << std::endl;

			std::cout << "global count: " << ++gCount << std::endl;

		}
		sleep(1);
	}
}

int main()
{
	boost::thread* ths[MAX_THREAD_NUM]={NULL};
	for (int i=0; i<MAX_THREAD_NUM; i++)
	{
		ths[i] = new boost::thread(boost::bind(&hello, i+1));
	}

	for (int i=0; i<MAX_THREAD_NUM; i++)
	ths[i]->join();

	std::cout << "thread all finished." << std::endl;
	return 0;
}
