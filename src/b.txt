//
// Created by Alexander Farrell on 6/18/22.
//

#include "player.h"

Player::Player(const std::string& name) {
    this->window = new Window(name);
//    this->game_state_app = nullptr;
    this->is_running = false; //refactor to not create window until ready?
}

Player::~Player() {
//    delete game_state_app;
    delete this->window;
}

void Player::update(Input * input) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                this->is_running = false;
                break;
            case SDL_KEYDOWN:
                input->on_key_down((SDL_KeyboardEvent*) &event);
                break;
            case SDL_KEYUP:
                input->on_key_up((SDL_KeyboardEvent*) &event);
                break;
            case SDL_MOUSEMOTION:
                input->on_mouse_move((SDL_MouseMotionEvent*) &event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                input->on_mouse_down((SDL_MouseButtonEvent *) &event);
                break;
            case SDL_MOUSEBUTTONUP:
                input->on_mouse_up((SDL_MouseButtonEvent *) &event);
                break;
            case SDL_MOUSEWHEEL:
                input->on_mouse_wheel((SDL_MouseWheelEvent *) &event);
                break;
            case SDL_WINDOWEVENT_RESIZED:
                this->window->on_resize((SDL_WindowEvent*) &event);
                break;
            default:
                break;
        }
    }
}
