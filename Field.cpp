#include <stdio.h>
#include "Field.h"


Field::Field(){
    x = 300;
    y = 0;
    setCrop(C_GRASS);
    surface = NULL;
    printf("Blank constructor called for field\n");
    
}

Field::Field(int x, int y){
    this->x = x;
    this->y = y;
    setCrop(C_GRASS);
    surface = NULL;
}

Field::~Field(){

}

void Field::update(){
    if(planted==true){
        printf("Field age: %i\n",age);
        if(age==60){
            setState(F_GROWING);
            printf("Field now growing");
            }
        if(age==200){
            printf("Crop ready\n");
            setState(F_MATURE);
        }
        if(age>300){
            printf("Crop died\n");
            setState(F_DEAD);
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

void Field::setCrop(CROP_TYPE newCrop){
    switch(newCrop){
        case 0: 
            cropType = C_GRASS; 
            setState(F_FALLOW); 
            printf("No crop set\n");
            break;
        case 1: 
            cropType = C_WHEAT; 
            setState(F_PLANTED); 
            printf("Wheat planted\n");
            break;
        case 2: 
            cropType = C_RYE;  
            setState(F_PLANTED); 
            printf("Rye planted\n");
            break;
        case 3: 
            cropType = C_BARLEY; 
            setState(F_PLANTED); 
            printf("Barley planted\n");
            break;
        default: ;
    }
}

void Field::setState(FIELD_STATE newState){
    switch(newState){
        case F_FALLOW:
            state = newState;
            age = 0;
            planted = false;
            break;
        case F_PLANTED:
            state = newState;
            age = 0;
            planted = true;
            break;
        case F_GROWING:
            state = newState;
            break;
        case F_MATURE:
            state = newState;
            break;
        case F_STUBBLE:
            state = newState;
            age = 0;
            planted = false;
            break;
        case F_DEAD:
            state = newState;
            age = 0;
            planted = false;
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

void Field::setXY(int x, int y){
    this->x = x;
    this->y = y;
}

CROP_TYPE Field::getCrop(){
    return cropType;
}

int Field::getCropAge(){
    return age;
}

FIELD_STATE Field::getState(){
    return state;
}

bool Field::isPlanted(){
    return planted;
}
