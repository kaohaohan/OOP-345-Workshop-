#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H
#include <chrono>
#include <iostream>

#define MAXTASKS 10

namespace seneca {


    struct Task
    {
         std::string taskName;
         std::string unitsTime; 
        std::chrono::steady_clock::duration duration;
    };
    
   
    
    class TimedTask {
        
        Task m_tasks[MAXTASKS];
        int m_numTasks{};
        std::chrono::steady_clock::time_point startTime;
        std::chrono::steady_clock::time_point endTime;
        public:
        TimedTask();

        void startClock();

        void  stopClock();

        void addTask(const char* name);

        friend std::ostream& operator<<(std::ostream& os, const TimedTask& tt);

    };

}

#endif 