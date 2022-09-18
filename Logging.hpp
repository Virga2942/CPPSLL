#pragma once
//External libraries

//C++ standard libraries
#include <iostream>
#include <chrono>

//C standard libraries
#include <ctime>

//3rd party libraries
//None right now

//Internal libraries
//None right now

class LOG
{
    private:
        bool properErrorOutput;
        bool release;
        bool time;

        //Returns the current date and time as a std::string
        std::string getTime()
        {
            std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

            return std::ctime(&time);
        }
    public:
        //Chooses some options for the logging library
        LOG(bool showDebugs = false, bool STDoutErrors = false, bool displayTime = true)
        {
            properErrorOutput = !STDoutErrors;
            release = !showDebugs;
            time = displayTime;
        }

        //Outputs an error message
        void Error(std::string ErrorMessage, std::string source = "ENGINE")
        {
            //Calculate what the output string is
            std::string outputString = "[" + getTime() + "][ERROR][" + source + "]: " + ErrorMessage;

            //Then send it to whichever output the user has selected
            if (properErrorOutput)
                std::cerr << outputString << std::endl;
            else
                std::cout << outputString << std::endl;
        }

        //Outputs a debug message
        void Debug(std::string DebugMessage, std::string source = "ENGINE")
        {
            std::cout << "[" << getTime() << "][DEBUG][" << source << "]: " << DebugMessage;
        }
};