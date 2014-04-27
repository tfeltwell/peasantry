#include <stdio.h>
#include "Field.h"


Field::Field(){
    x = 300;
    y = 0;
    setCrop(0); // No crop to start
    planted = false;
    age = 0;
    surface = NULL;
    printf("Blank constructor called for field\n");
    
}

Field::Field(int x, int y){
    this->x = x;
    this->y = y;
    setCrop(0); // No crop to start
    planted = false;
    age = 0;
    surface = NULL;
}

Field::~Field(){

}

void Field::update(){
    if(planted==true){
        printf("Field age: %i\n",age);
        if(age==270){
            printf("Crop ready\n");
            setCrop(0);
        }
        grow();
    }
    else{
        // Field not planted
    }
}

void Field::grow(){
    age++;
}

void Field::setCrop(int cropID){
    switch(cropID){
        case 0: 
            cropType = "None"; 
            planted = false; 
            age = 0; 
            printf("No crop set\n");
            break;
        case 1: 
            cropType = "Wheat"; 
            planted = true; 
            printf("Wheat planted\n");
            break;
        case 2: 
            cropType = "Rye";  
            planted = true; 
            printf("Rye planted\n");
            break;
        case 3: 
            cropType = "Barley"; 
            planted = true; 
            printf("Barley planted\n");
            break;
        default: ;
    }
}

int Field::getX(){
    return x;
}

int Field::getY(){
    return y;
}

std::string Field::getCrop(){
    return cropType;
}

int Field::getCropAge(){
    return age;
}

bool Field::isPlanted(){
    return planted;
}
