//
// Created by Alexander Farrell on 6/18/22.
//

#include "window.h"
#include <iostream>

Window::Window(const std::string& name) {
    this->width = WINDOW_WIDTH_DEFAULT;
    this->height = WINDOW_HEIGHT_DEFAULT;

    int windowFlags = SDL_WINDOW_RESIZABLE;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout
            << "Couldn't initialize SDL: "
            << SDL_GetError()
            << std::endl;
        exit(1);
    }

    this->sdl_window = SDL_CreateWindow(
            name.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            this->width,
            this->height,
            windowFlags
            );

    if (!this->sdl_window) {
        printf("Failed to open %d x %d window: %s\n",
               this->width,
               this->height,
               SDL_GetError());
        exit(1);
    }

    //    if (Mix_OpenAudio(AUDIO_QUALITY,
//                      MIX_DEFAULT_FORMAT,
//                      2,
//                      1024) == -1) {
//        printf("Couldn't initialize SDL Mixer\n");
//        exit(1);
//    }
//
//    Mix_AllocateChannels(MAX_SND_CHANNELS);
//
//    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG); // Initializes SDL Image: loads PNGs and JPGs.

//    SDL_ShowCursor(0);
}

Window::~Window() {
    SDL_DestroyWindow(this->sdl_window);
    SDL_Quit();
}

void Window::on_resize(SDL_WindowEvent *event) {

}

int Window::getWidth() const {
    return width;
}

int Window::getHeight() const {
    return height;
}

FullscreenState Window::getFullscreenState() const {
    return fullscreen_state;
}

void Window::set_fullscreen_state(FullscreenState state) {
    this->fullscreen_state = state;
    switch (state) {
        case Fullscreen:
            SDL_SetWindowFullscreen(this->sdl_window, SDL_WINDOW_FULLSCREEN);
            break;
        case Windowed:
            SDL_SetWindowFullscreen(this->sdl_window, 0);
            break;
    }
}
