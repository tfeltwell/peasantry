#include "NameGenerator.h"
#include <ctime>
#include <cstdlib>
#include <string>

const char* const NameGenerator::firstNamesM[] = {"Patrick","Claude","Guillem","Phillipe","Jean","Patrick","Claude","Guillem","Phillipe","Jean"};
const char* const NameGenerator::firstNamesF[] = {"Adelina","Camille","Emmaline","Damica","Chenelle","Honore","Georgine","Francina","Gisella","Jacqueline"};
const char* const NameGenerator::lastNames[] = {"Burgundy","Capucina","Chablis","Esmee","Fantina","Fayette","Isabeau","Margeuax","Maiya","Jenette","Nanette","Adalyn","Brigitte"};

NameGenerator::NameGenerator(){

    std::srand(time(0));
}

NameGenerator::~NameGenerator(){

}

std::string NameGenerator::generateFirst(bool gender){
    int rNum = rand() % 10;
    char* selection;
    if(gender==true){
        selection = const_cast<char*>(firstNamesF[rNum]);
    }
    else{
        selection = const_cast<char*>(firstNamesM[rNum]);
    } 
    std::string returnString(selection);
    return returnString;
}

std::string NameGenerator::generateLast(){
    int rNum = rand() % 10;
    char* selection;
    selection = const_cast<char*>(lastNames[rNum]);
    std::string returnString(selection);
    return returnString;
}