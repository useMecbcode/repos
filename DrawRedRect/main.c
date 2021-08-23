#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
const int WIDTH = 400;
const int HEIGHT = 300;
void event_loop();
int main() {
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Can not init video, %s",SDL_GetError());
        return 1;
    }
    //CREATE WINDOW
    SDL_Window *win = SDL_CreateWindow(
            "Hello World",SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WIDTH,HEIGHT,
            SDL_WINDOW_SHOWN
            );
    if (win == NULL)
    {
        SDL_Log("Can not Create Window, %s",SDL_GetError());
        return 1;
    }
    //memory data express pixel value from window,is renderer
    SDL_Surface *screen = SDL_GetWindowSurface(win);
    SDL_Rect rect = {0,0,WIDTH,HEIGHT};
    //color ARGB
    SDL_FillRect(screen,&rect,0xffffffff);
    //Update Window
    SDL_UpdateWindowSurface(win);
    // Draw squares
    SDL_Rect RedRect = {WIDTH/2,HEIGHT/2,100,100};
    SDL_FillRect(screen,&RedRect,0xffff0000);
    SDL_UpdateWindowSurface(win);
    event_loop();
    //Destroy WINDOW
    SDL_DestroyWindow(win);
    SDL_FreeSurface(screen);
    return 0;
}
void event_loop()
{
    while (true)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            break;
        }
    }
}
