#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include <SDL2/SDL.h>

int main(int argc, char **argv)
{
    // Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *xWindow = SDL_CreateWindow("Whorl test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 192, 192, 0);
    SDL_Renderer *xRender = SDL_CreateRenderer(xWindow, -1, SDL_RENDERER_ACCELERATED);
    
    // Wait for quit
    SDL_Event xEvent;
    while(1)
    {
        SDL_PollEvent(&xEvent);
        if(xEvent.type == SDL_QUIT)
            break;
    }
    
    // Cleanup SDL
    SDL_DestroyRenderer(xRender);
    SDL_DestroyWindow(xWindow);
    SDL_Quit();
    return 0;
}
