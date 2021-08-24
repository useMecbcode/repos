#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
const int WIDTH = 400;
const int HEIGHT = 300;
int x = 0;
void event_loop(SDL_Surface * screen, SDL_Window*win);
void draw(SDL_Surface * screen, SDL_Window*win);
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
    SDL_Surface *screen = SDL_GetWindowSurface(win);

    event_loop(screen,win);
    //Destroy WINDOW
    SDL_DestroyWindow(win);
    SDL_FreeSurface(screen);
    return 0;
}
void draw(SDL_Surface * screen, SDL_Window*win)
{
    x++;
    //memory data express pixel value from window,is renderer
    SDL_Rect rect = {0,0,WIDTH,HEIGHT};
    //color ARGB
    SDL_FillRect(screen,&rect,0xffffffff);
    // Draw squares
    SDL_Rect RedRect = {x,0,100,100};
    SDL_FillRect(screen,&RedRect,0xffff0000);
    SDL_UpdateWindowSurface(win);
}
void event_loop(SDL_Surface * screen, SDL_Window*win)
{
    while (true)
    {
        draw(screen,win);
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            break;
        }
        SDL_Delay(20);
    }
}
