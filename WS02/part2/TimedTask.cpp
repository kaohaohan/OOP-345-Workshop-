#include <iostream>
#include <chrono>
#include "TimedTask.h"
#include <cstring>
using namespace std;

namespace seneca{
     TimedTask::TimedTask(){

     }
    void TimedTask::startClock(){
        startTime = chrono::steady_clock::now();
      }

    void TimedTask::stopClock(){
        endTime =  chrono::steady_clock::now();

      }

    void TimedTask::addTask(const char* taskName){
      
      if (m_numTasks < MAXTASKS) {
        m_tasks[m_numTasks].taskName = taskName;
        m_tasks[m_numTasks].unitsTime = "nanoseconds";
        
        m_tasks[m_numTasks].duration = endTime - startTime;
        m_numTasks++;
      }
      

    }
    ostream& operator<<(ostream& os, const TimedTask& tt){
        os<<"--------------------------"<<endl;
        os << "Execution Times:" <<endl;
        os<<"--------------------------"<<endl;
        for (int i =0;i< tt.m_numTasks;i++){
            //taskName
            os.width(21);
            os.setf( ios::left ); 
            os << tt.m_tasks[i].taskName ;
            os.unsetf( ios::left );
            // duration
            os.width(13);
            os.setf( ios::right ); 
            os <<tt.m_tasks[i].duration.count();
            os.unsetf( ios::right );

            os << " " <<tt.m_tasks[i].unitsTime<<endl;
            
        }
         os<<"--------------------------"<<endl;
        return os;

    }



      

    
}