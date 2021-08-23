#include <stdio.h>
#include <SDL2/SDL.h>
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
    SDL_Delay(3000);
    //Destroy WINDOW
    SDL_DestroyWindow(win);
    return 0;
}
