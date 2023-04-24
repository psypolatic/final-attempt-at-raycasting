#pragma once
#include <SDL2/SDL.h>
#include "mathfunc.hpp"
class Player{
    public:
    double x;
    double y;
    Player();
    void draw(SDL_Surface *window_surface,SDL_Renderer *m_renderer);
    void update(double delta_time);
    void handle_events(SDL_Event const &event);

    void render_lines(SDL_Renderer *m_renderer,SDL_Surface *surf);

    bool colliding();

    private:
    SDL_Surface *m_image;

    SDL_Rect     m_image_position;
    int          rotation = 0;

    double       x_direction;
    double       y_direction;
    double       m_image_x;
    double       m_image_y;

    bool directional_held_down;
};