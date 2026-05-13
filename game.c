//gcc games.c -o game -lSDL2 -lm
#include <SDL2/SDL.h>
#include "SDLs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define True 1;
#define False 0;
#define true 1;
#define false 0;

int score=0;
int fire=0;
int live=0;
int lives=3;
int x=0;
int y=0;
int z=0;
int w=0;
int h=0;
int ends=False;
int camera=0;
int enemy=0;
int enemycount=3;
SDL_Window *window ;
SDL_Renderer *renderer;
SDL_Texture *texture;
int running = 1;
SDL_Event event;

int debugsa=true
char *files="log.txt";

#define tsleep 100000
void debugs(char *c){
    FILE *f1;
    if (debugsa){
        f1=fopen(files,"w");
        fprintf(f1,"%s\n",c);
        fclose(f1);
        printf("%s\n",files);
    }else{
        f1=fopen(files,"a");
        fprintf(f1,"%s\n",c);
        fclose(f1);
        //printf("%s\n",files);
    }
    debugsa=false
    usleep(tsleep);
}
void checkgameover(){
    //put you code here
    debugs("checkgameover\n\n");


}
void refreshscreen(){
    //put you code here
    debugs("refreshscreen");



}
void handlescore(){
    //put you code here
    debugs("handlescore");

}
void changenetwork(){
    //put you code here
    debugs("changenetwork");


}
void drawplayers(){
    //put you code here
    debugs("drawplayers");




}
void handlekeymouse(){
    //put you code here
    debugs("drawplayers");



}
void drawenemys(){
    //put you code here
    debugs("drawenemys");

}
void handlenemy(){
    //put you code here
    debugs("handlenemy");

}
void drawmain(){
    //put you code here
    debugs("drawmain");
}

int mainloop(){
    //put you code here
    debugs("mainloop");
    while(running){
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
        drawmain();
        handlenemy();
        drawenemys();
        handlekeymouse();
        drawplayers();
        changenetwork();
        handlescore();
        refreshscreen();
        checkgameover();
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
        if (ends)return ends;
    }
    return ends;
}

int setuploop(){
    //put you code here
    debugs("setuploop");
    while(running){
       if (mainloop())return ends;
    }
    
    
    // Cleanup
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return ends;
}
int main(int argc,char *argv[]){
    //put you code here
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("256 Colors", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }


    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Create a texture to render the 256 colors
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB332, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
    if (!texture) {
        printf("SDL_CreateTexture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    clears(0,0,0);
    SDL_UpdateTexture(texture, NULL, screen, WIDTH);
    debugs("main");
    setuploop();

    return 0;
}