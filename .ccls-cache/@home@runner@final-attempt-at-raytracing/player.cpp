#include "player.hpp"
#include "helper.hpp"
#include "mathfunc.hpp"
#include <stdio.h>
#include <memory>


//im doing something wayyyyy wrong there is no reason this code should even exits
#define left_max(rota) rotate_x(x-100,y-100,DEG_TO_RAD(rota),x,y),rotate_y(x-50,y-50,DEG_TO_RAD(rota),x,y)
#define right_max rotate_y(x+50,y-50,DEG_TO_RAD(rotation),x,y),rotate_y(x+50,y-50,DEG_TO_RAD(rotation),x,y)

//fuck it im going to implament hitting rays here i dont care ima make another raytracer with actual working later

void render_section(int section,int distance,SDL_Surface *screenSurface){
    SDL_Rect rect;
    rect.x = section * 8;
    rect.y = 0;
    rect.w = 8;
    rect.h=600;

    SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 200 - distance, 200 - distance, 200 - distance));
}


Player::Player(){
    m_image = load_surface("assets/test.bmp");

    m_image_position.x = 100;
    m_image_position.y = 100;
    x =100;
    y=100;
    m_image_position.w = 32;
    m_image_position.h = 32;

    x_direction = 100;
    y_direction =100;

    m_image_x =100.0;
    m_image_y =100.0;

    directional_held_down = false;

}
void Player::render_lines(SDL_Renderer *m_renderer ,SDL_Surface *surf){
    int block[2] = {30,30};
    double slope;
    coordinate bah;
    
    for(int i = 0; i<75;i++){
        bah.xy(left_max(rotation+i));

        slope = bah.y - y/bah.x - x;
        

        if (distance(30,30,x,y) <= 200){
            std::unique_ptr<int[]> xyy = findIntersection(30, 50, 50, slope);
            SDL_RenderDrawLine(m_renderer,x,y,xyy[0],xyy[1]);
            //wow i forget im using c++ and I have to fix memory issues
            //render_section(i, distance(x,y,xyy[0],xyy[1]), surf);
        }
        
        //SDL_RenderDrawLine(m_renderer,x,y,left_max(rotation+i));
    }
    //SDL_RenderDrawLine(m_renderer,x,y,left_max);
    //SDL_RenderDrawLine(m_renderer,x,y,right_max);
}

void Player::handle_events(SDL_Event const &event){
    switch(event.type){
        case SDL_KEYDOWN:
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);
            
            if (keys[SDL_SCANCODE_LEFT]){

                directional_held_down = true;
                x_direction = -5;
            }
            else if(keys[SDL_SCANCODE_RIGHT]){
                directional_held_down = true;
                x_direction = 5;
            }
    
            if (keys[SDL_SCANCODE_UP]){
                directional_held_down = true;
                y_direction = -5;
            }
            else if(keys[SDL_SCANCODE_DOWN]){
                directional_held_down = true;
                y_direction = 5;
            }

            if (keys[SDL_SCANCODE_A]){
                rotation += 20;
            }
            else if (keys[SDL_SCANCODE_D]){
                rotation -= 20;
            }
            if (keys[SDL_SCANCODE_G]){
                printf("PLayer at (%i , %i)", (int)x , (int)y);
            }
            break;


    }
}


void Player::draw(SDL_Surface *window_surface,SDL_Renderer *m_renderer)
{
    SDL_BlitSurface(m_image, nullptr, window_surface, &m_image_position);
    render_lines(m_renderer,window_surface);
    
}

void Player::update(double delta_time){

    
    //moves player
    if(directional_held_down){
    Uint8 const *keys = SDL_GetKeyboardState(nullptr);
    if (!(keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_RIGHT] || keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_DOWN])){
        directional_held_down  = false;
    }
    
    m_image_x  = m_image_x + (x_direction * delta_time);
    m_image_position.x = m_image_x;
    x = m_image_x;
    m_image_y  = m_image_y + (y_direction * delta_time);
    m_image_position.y = m_image_y;
    y = m_image_y;
    }
    else{
        x_direction = 0;
        y_direction =0;
    }

    
}