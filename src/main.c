#include <stdio.h>
#include <SDL2/SDL.h>

void on_delete(SDL_Window* window) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char const *argv[])
{
    // Width and height of the window
    int width = 1280;
    int height = 720;

    // Whether the window is resizable or not
    int windowFlags = SDL_WINDOW_RESIZABLE;

    char * windowTitle = "Name of Game";
7
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't initialize SDL: %s \n", SDL_GetError());
        exit(1);
    }

    SDL_Window* window = SDL_CreateWindow(
        windowTitle,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        windowFlags
    );

    if (!window) {
        printf("Failed to open %d x %d window: %s\n",
            width, height, SDL_GetError());
        exit(1);
    }

    SDL_ShowCursor(1);

    SDL_Event event;

    int running = 1;

    while (running) {
        while (SDL_PollEvent(&event)) {
        switch ((int)event.type) {
            case SDL_QUIT:
                exit(1);
                break;
            case SDL_KEYDOWN:
                break;
            default:
                break;
        }
        SDL_GL_SwapWindow(window);
        SDL_Delay(1000/60.0f);
    }
    }

    return 0;
}
