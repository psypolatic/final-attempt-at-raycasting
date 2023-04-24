//Helper functions yk

#include "helper.hpp"
#include <stdio.h>

SDL_Surface *load_surface(char const *path)
{
    SDL_Surface *image_surface = SDL_LoadBMP(path);
    printf("Image loaded at %s\n", path);

    if(!image_surface){
        printf("Failed to load image: %s\n", SDL_GetError());
        return 0;}

    return image_surface;
}