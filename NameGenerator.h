#ifndef NAME_GEN_H
#define NAME_GEN_H

// Dependencies
#include <string>

class NameGenerator
{
    static const char* const firstNamesM[];
    static const char* const firstNamesF[];
    static const char* const lastNames[];
    
    public:
        NameGenerator();
        ~NameGenerator();
        std::string generateFirst(bool gender);
        std::string generateLast();
        

};

#endif