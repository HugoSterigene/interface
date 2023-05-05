
#ifndef USER_PROFILS_H
#define USER_PROFILS_H


#include <string>
#include <vector>

class user_profils
{
public:
    user_profils(std::string username, std::string password);
    std::vector<std::string> splitCSV(const std::string& line, char delimiter);
    std::string get_password();
    int create_profil(std::string status);
    int open_profil();
    std::string encrypt_password(const std::string password);
    std::string getStatus();
    bool file_exist(const std::string& filename);

private:
    std::string username;
    std::string password;
    std::string status;
    std::string filepath;
};

#endif // USER_PROFILS_H
