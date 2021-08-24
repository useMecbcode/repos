#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

const int WIDTH = 1234;
const int HEIGHT = 512;
const int FrameRate = 120;
SDL_Surface *image ;

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
    image = SDL_LoadBMP("BtSnake.bmp");
    event_loop(screen,win);
    //Destroy WINDOW
    SDL_FreeSurface(image);
    SDL_DestroyWindow(win);
    SDL_FreeSurface(screen);
    return 0;
}
void draw(SDL_Surface * screen, SDL_Window*win)
{
    SDL_Rect src = {0,0,image->w,image->h};
    SDL_BlitSurface(image,&src,screen,&src);// copy to screen
    SDL_UpdateWindowSurface(win);
}
void event_loop(SDL_Surface * screen, SDL_Window*win)
{
    while (true)
    {
        uint32_t start = SDL_GetTicks();
        draw(screen,win);
        SDL_Event event;
        SDL_PollEvent(&event);
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT)
            {
                return;
            }
        }
        uint32_t current = SDL_GetTicks(); // get time
        uint32_t cost = current - start; // draw time

        uint32_t frame = 1000/FrameRate; // per animation time

        int64_t delay = (int64_t)(frame - cost); // get delay time

        if (delay > 0)
        {
            SDL_Delay(delay);
        }
    }
}
