
#include "logger.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

/**
 * @brief logger::logger this object will be used to log every aspect of the application
 */
logger::logger():log_file(),file()
{
    // the destination of the logs
    this->log_file = "./log/logs.txt";
    // we open the file to append text in it
    this->file.open(log_file,std::ios_base::app);
}

logger::~logger()
{
    this->file.close();
}

/**
 * @brief logger::getCurrentTime
 * Function that will return the current date and time formatted to be used later
 * @return the formatted date and time
 */
std::string logger::getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);

    // Creating a string with the formatted date/time
    std::stringstream ss;
    ss << std::put_time(std::localtime(&current_time), "%Y-%m-%d_%H-%M-%S");
    std::string datetime_str = ss.str();

    return datetime_str;
}

/**
 * @brief logger::write_warning
 * This function will be in charge of creating a warning message for the logging system
 * @param message : the message we want to write in the warning
 */
void logger::write_warning(std::string message)
{
    std::string data;
    data.append("[warning]: ");
    data.append(message);

    write_log(data);
}

/**
 * @brief logger::write_error
 * This function will be in charge of creating an error message for the logging system
 * @param message : the message we want to write in the error
 */
void logger::write_error(std::string message)
{
    std::string data;
    data.append("[error]: ");
    data.append(message);

    write_log(data);
}

/**
 * @brief logger::write_logging
 * This function will create the string to create a log and log it
 * @param message : the message we want to log
 */
void logger::write_logging(std::string message)
{
    std::string data;
    data.append("[log]: ");
    data.append(message);

    write_log(data);
}

/**
 * @brief logger::write_log
 * This function willbe used to write every type of log in the file
 * @param log : the string we will write in the file
 */
void logger::write_log(std::string& log)
{
    file << getCurrentTime() << " " << log << std::endl;
}


