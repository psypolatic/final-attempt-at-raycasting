#include "application.hpp"
#include <SDL2/SDL.h>
#include <iostream>//I code in c mostly so i prefer stdio.h but ¯\_(ツ)_/¯

//a
//the worlds most boring main function
//even a helloworld function is more exciting
int main() {
  Application app;

  app.loop();
  app.draw();
}