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
        bool debugs;
        bool time;

        //Returns the current date and time as a std::string
        std::string getTime()
        {
            if (time)
            {
                std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                std::string timeString = std::ctime(&time);
                timeString.pop_back();

                return "[" + timeString + "]";
            }
            //Idk if this is necessary but it probably doesn't hurt
            return "";
        }
    public:
        //Chooses some options for the logging library
        LOG(bool showDebugs = true, bool STDoutErrors = false, bool displayTime = true)
        {
            properErrorOutput = !STDoutErrors;
            debugs = showDebugs;
            time = displayTime;
        }

        //Outputs an error message
        void Error(std::string ErrorMessage, std::string source = "ENGINE")
        {
            //Calculate what the output string is
            std::string outputString = getTime() + "[ERROR][" + source + "]: " + ErrorMessage;

            //Then send it to whichever output the user has selected
            if (properErrorOutput)
                std::cerr << outputString << std::endl;
            else
                std::cout << outputString << std::endl;
        }

        //Outputs a debug message
        void Debug(std::string DebugMessage, std::string source = "ENGINE")
        {
            if (debugs)
                std::cout << getTime() << "[DEBUG][" << source << "]: " << DebugMessage << std::endl;
        }
};
