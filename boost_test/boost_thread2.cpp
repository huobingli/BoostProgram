
//********************************************************
//
//       FileName:      boost_thread2.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-01  11:09:27
//       Last Modified: 2016-12-01 11:09:27
//********************************************************
//
#include <iostream>

#include <boost/thread.hpp> 
using namespace boost;

void wait(int seconds) 
{ 
  boost::this_thread::sleep(boost::posix_time::seconds(seconds)); 
} 

void gothread() 
{ 
  for (int i = 0; i < 5; ++i) 
  { 
    wait(1); 
    std::cout << i << std::endl; 
  } 
} 

int main() 
{ 
  boost::thread t(&gothread); 
  t.join(); 
} 
