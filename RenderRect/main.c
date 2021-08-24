#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

const int WIDTH = 400;
const int HEIGHT = 300;
const int FrameRate = 30;


SDL_Renderer *renderer;
SDL_Window *win;
void event_loop();
void draw();
int main() {
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Can not init video, %s",SDL_GetError());
        return 1;
    }
    //CREATE WINDOW
    win = SDL_CreateWindow(
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
    renderer = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        SDL_Log("Can't create renderer %s",SDL_GetError());
    }
    SDL_Surface *screen = SDL_GetWindowSurface(win);
    event_loop();
    //Destroy WINDOW
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_FreeSurface(screen);
    return 0;
}
void draw()
{
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);

    SDL_Rect r = {0,0,100,100};
    SDL_SetRenderDrawColor(renderer,255,0,0,100);
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
    SDL_RenderFillRect(renderer,&r);

    SDL_RenderPresent(renderer);
}
void event_loop()
{
    while (true)
    {
        uint32_t start = SDL_GetTicks();
        draw();
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
