#include <iostream>
#include "SDL.h"

#include "resource_path.hpp"

// Ensure SDL is setup properly.
int main(int, char **) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  std::cout << "Resource path is: " << getResourcePath() << std::endl;
  SDL_Quit();
  return 0;
}

