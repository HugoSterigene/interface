
#include "user_profils.h"
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>

user_profils::user_profils(std::string username,std::string password)
{
    this->username = username;
    this->password = encrypt_password(password);
    this->filepath = "";
    this->filepath.append("./profil/");
    this->filepath.append(this->username);
    this->filepath.append(".csv");
}

std::vector<std::string> user_profils::splitCSV(const std::string& line, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;
    while(std::getline(ss,token,delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

std::string user_profils::encrypt_password(const std::string password)
{
    std::hash<std::string> hasher;
    size_t hash = hasher(password);
    return std::to_string(hash);
}

inline bool user_profils::file_exist(const std::string& filename)
{
    struct stat buffer;
    return (stat (filename.c_str(),&buffer) == 0);
}

int user_profils::create_profil(std::string status)
{
    if(file_exist(this->filepath))
    {
        return -1;
    }else
    {
        std::ofstream profil_file;
        profil_file.open(filepath);
        profil_file << username << "," << password << "," << status <<std::endl;
        profil_file.close();
        return 0;
    }
}

std::string user_profils::getStatus()
{
    std::ifstream file(this->filepath);

    std::string status;
    std::string line;
    std::getline(file,line);
    std::vector<std::string> elements = splitCSV(line,',');

    status = elements[2];
    return status;
}

std::string user_profils::get_password()
{
    std::ifstream file(this->filepath);

    std::string password;
    std::string line;
    std::getline(file,line);
    std::vector<std::string> elements = splitCSV(line,',');

    password = elements[1];
    return password;
}

int user_profils::open_profil()
{
    if(!file_exist(this->filepath))
    {
        return 1;
    }
    else
    {
        std::string check_password = get_password();
        if(check_password != this->password)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
}
