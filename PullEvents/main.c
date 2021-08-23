#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
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
            300,400,
            SDL_WINDOW_SHOWN
            );
    if (win == NULL)
    {
        SDL_Log("Can not Create Window, %s",SDL_GetError());
        return 1;
    }
    while (true)
    {
        //Create Event
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            //QUIT EVENTS
            if(event.type == SDL_QUIT)
            {
                break;
            }
        }
    }
    //Destroy WINDOW
    SDL_DestroyWindow(win);
    return 0;
}
