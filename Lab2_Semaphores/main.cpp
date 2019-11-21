/*!
   \file main.cpp
   \author brendan Mitchell
   \date 21/11/2019
   \Licence GNU									\
   \brief  This is the second lab which displays one message before another.
*/



#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>


/*! \class Signal
    \brief An Implementation of Threads Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement Semaphores in thread functions 

*/
/*! displays a message first*/


/*! \fn void taskOne
    \brief Description of void taskOne function
    \param theSemaphore share 
    \param int delay 
*/

void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){ 
  sleep(delay);
  theSemaphore->Signal();
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
 
  
}


/*! \fn void taskTwo
    \brief Description of void taskTwo function
    \param theSemaphore share 
*/
/*! displays a message second*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
 ;
}


/*! \fn int main
    \brief Description of main function
*/

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  int taskOneDelay=5;
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem,taskOneDelay);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}
