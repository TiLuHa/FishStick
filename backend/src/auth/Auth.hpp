#ifndef AUTH_HPP
#define AUTH_HPP

#include <string>
#include <mutex>
#include <chrono>

struct Session
{
   std::size_t Id;
   std::string Token;
   std::chrono::system_clock::time_point Expiry;
};

class Auth
{
public:
   std::string authenticate(std::string const& login, std::string const& password);
   bool isValid(std::string const& token);
   Session getSessionByToken(std::string const& token);
   bool authorize(std::size_t id, std::string const& token);
private:
   std::mutex authMutex;
};

#endif
