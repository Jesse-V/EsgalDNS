
#ifndef UTILS
#define UTILS

#include <cstdint>
#include <string>

class Utils
{
    public:
        static uint32_t arrayToUInt32(const uint8_t*, int32_t);
        static char* getAsHex(const uint8_t*, int);
        static bool isPowerOfTwo(unsigned int);
        static void stringReplace(std::string&, const std::string&,
            const std::string&);
};

#endif