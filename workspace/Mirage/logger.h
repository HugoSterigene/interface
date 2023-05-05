
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class logger
{
public:
    void write_warning(std::string message);
    void write_log(std::string& log);
    void write_error(std::string message);
    void write_logging(std::string message);
    void lock();
    void unlock();
    std::string getCurrentTime();
    logger();
    ~logger();

private:
    std::string log_file;
    std::ofstream file;
};


#endif // LOGGER_H
