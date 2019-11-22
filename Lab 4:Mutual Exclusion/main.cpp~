/*!
 \file main 
 \author Brendan Mitchell
 \date 21/11/2019
 \Project CDD Lab 4 Mutual Exclusion
 \License GNU
 \brief Description:Mutual exclusion using a semaphore
 */





#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

/*! \var static const int num_threads=100
    \brief The number of threads we intend to create

    \var int shared variables = 0;
    \brief The shared variable to be used iniatialised to 0 
*/


static const int num_threads = 100;
int sharedVariable=0;





/*! \fn updateTask
    \brief An Implementation of Mutual Exclusion using Semaphores

   Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads
   @return updates the value of shared variable 
   @param firstSem is a Semaphore 
   @param numUpdates is a shared variable that is updated.
   

*/
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates){
  

 
  for(int i=0;i<numUpdates;i++){
    //UPDATE SHARED VARIABLE HERE!
    sharedVariable++;
  }

 

}

/*! \fn int main()
    \brief The eponymous main function
    
    This function creates threads and then launches them, It then
    joins each thread with the main thread and exits. 
   
*/


int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Semaphore> aSemaphore( new Semaphore);
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(updateTask,aSemaphore,1000);
  }
  std::cout << "Launched from the main\n";
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
