#include <iostream>
#include <stdlib.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string>

#include "GameWorld.h"
#include "Player.h"
#include "Field.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;
const int MSPERFRAME = 32;

// Screen surface
SDL_Surface *screen = NULL;   
  
// Other surfaces
SDL_Surface *background = NULL;
SDL_Surface *image = NULL;
SDL_Surface *playerSurf = NULL;


// Other engine stuff
TTF_Font *font = NULL;
SDL_Color textColor = {255,255,255};
SDL_Event event;
SDL_Rect clip[4];

// Game stuff
GameWorld world;
Player player(140,140);
Field field[2] = {
    Field(300,200),
    Field(500,500)
};


// Load image function
SDL_Surface *load_image( std::string filename ){
    // Temp storage for image
    SDL_Surface* loadedImage = NULL;
    
    // Optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    
    // Load the image
    loadedImage = IMG_Load( filename.c_str() );
    
    // If nout went wrong
    if ( loadedImage != NULL ){
        // Create optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface(loadedImage);
        if(optimizedImage!=NULL){
            Uint32 colorkey = SDL_MapRGB(optimizedImage->format,0,0xFF,0xFF);
            SDL_SetColorKey(optimizedImage,SDL_SRCCOLORKEY,colorkey);
        }
    }  
    else{
        printf("SDL failed to load image: %s\n", SDL_GetError());
    }      
    return optimizedImage;
}

// Screen update function
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip=NULL){
    SDL_Rect offset;
    
    offset.x = x;
    offset.y = y;
    
    SDL_BlitSurface( source, clip, destination, &offset);
}
bool init(){
    // Init all SDL subsystems
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
        printf("SDL failed to initialise: %s\n",SDL_GetError());
        return false;
    }
    
    // Set screen up
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    
    if (screen == NULL){
        printf("SDL failed to initialise screen: %s\n",SDL_GetError());
        return false;
    }
    
    if(TTF_Init()==-1){return false;}
    
    SDL_WM_SetCaption( "Sixteen Hundred", NULL );
    
    // Init game world & other stuff
    world.init();
    
    return true;
}

bool load_files(){
//    image = load_image("dots.png");
//    if(image==NULL){return false;}

    background = load_image("assets/grass.png");
    if(background==NULL){return false;}
    
    playerSurf = load_image("assets/player.png");
    if(playerSurf==NULL){return false;}
    
    for(int i=0;i<(sizeof(field)/sizeof(field[0]));i++){
        field[i].surface = load_image("assets/field.png");
        if(field[i].surface==NULL){return false;}
    }
    
//    Disabled font until needed    
//    font = TTF_OpenFont("lazy.ttf",28);
//    if(font==NULL){printf("SDL failed to initialise font: %s\n",SDL_GetError());return false;}
    
    return true;
}

void cleanup(){
    // Free surfaces and quit
    SDL_FreeSurface(image);
    SDL_FreeSurface(background);
    SDL_FreeSurface(playerSurf);
    for(int i=0;i<(sizeof(field)/sizeof(field[0]));i++){
        //printf("%i field cleaned up\n",i); // Debug
        SDL_FreeSurface(field[i].surface);
    }
    
//    Disabled until needed    
//    TTF_CloseFont(font);
    TTF_Quit();
    
    SDL_Quit(); 
}

int main( int argc, char* args[] ){
    bool quit = false;
    Uint32 oldTime = SDL_GetTicks();
    Uint32 newTime = 0;
    
    if(init()==false){return 1;}
    if(load_files()==false){return 1;}
    
    apply_surface(0,0,background,screen);
    
    while(quit==false){
    
        // Debug stuff with output here
//        printf("%s: %s\n",world.getSeasonStr().c_str(),world.getTimeDayStr().c_str());
    
        // Event polling
        if (SDL_PollEvent(&event)){
        
            // Check for single events
            if(event.type==SDL_KEYDOWN){
                switch(event.key.keysym.sym){
                    case SDLK_i: 
                        printf("%s, S:%i I:%i C:%i L:%i\n",player.getName().c_str(),player.getSkill(0),player.getSkill(1),player.getSkill(2),player.getSkill(3));
                        break;
                    case SDLK_t:
                        printf("%i on %i/%i/%i\n",world.getHour(),world.getDay(),world.getMonth(),world.getYear());
                        break;
                    case SDLK_p:
                        field[1].setCrop(C_RYE);
                        break;
                    default: ;
                }       
            }
            else if(event.type==SDL_QUIT){
                quit = true;
            }
        }
        
        // Check for keystates (pressed or not)
        Uint8 *keystates = SDL_GetKeyState(NULL);
        if(keystates[SDLK_UP]){player.setY(player.getMoveAmount(-1));}
        if(keystates[SDLK_DOWN]){player.setY(player.getMoveAmount(1));}
        if(keystates[SDLK_LEFT]){player.setX(player.getMoveAmount(-1));}
        if(keystates[SDLK_RIGHT]){player.setX(player.getMoveAmount(1));}
        
        // Update objects
        if((newTime - oldTime)>1000){
            printf("Running update\n");
            printf("%s - Time: %i (%s) on %i/%i/%i\n",world.getSeasonStr().c_str(),world.getHour(),world.getTimeDayStr().c_str(),world.getDay(),world.getMonth(),world.getYear());
            world.update();
            for(int i=0;i<(sizeof(field)/sizeof(field[0]));i++){
                field[i].update();
            oldTime = SDL_GetTicks();
            }   
        }
        newTime = SDL_GetTicks();
        
        // Drawing
        apply_surface(0,0,background,screen);
        for(int i=0;i<(sizeof(field)/sizeof(field[0]));i++){
            apply_surface(field[i].getX(),field[i].getY(),field[i].surface,screen);
        }
        apply_surface(player.getX(),player.getY(),playerSurf,screen);
        
        
        if(SDL_Flip(screen) == -1){
            printf("SDL unable to flip screen: %s\n",SDL_GetError());
            return 1;
        }
        SDL_Delay(MSPERFRAME);
    }
    cleanup();
    return 0;
}
