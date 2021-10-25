#include "Auth.hpp"

#include <sstream>

#include <openssl/sha.h>

#define UUID_SYSTEM_GENERATOR
#include <uuid/uuid.hpp>

namespace
{
   std::string sha256(const std::string str)
   {
      unsigned char hash[SHA256_DIGEST_LENGTH];
      SHA256_CTX sha256;
      SHA256_Init(&sha256);
      SHA256_Update(&sha256, str.c_str(), str.size());
      SHA256_Final(hash, &sha256);
      std::stringstream ss;

      for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
         ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];

      return ss.str();
   }


}

std::string Auth::authenticate(std::string const& login, std::string const& password)
{
   authMutex.lock();

   std::string pwhash = sha256(password);


   authMutex.unlock();
}

