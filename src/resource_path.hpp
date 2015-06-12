#ifndef RESOURCE_PATH_HPP_
#define RESOURCE_PATH_HPP_

// Get the resource path. This assumes the binary is in a sane place.

// This is inspired by a famous SDL tutorial.

#include <iostream>
#include <string>
#include "SDL.h"

std::string getResourcePath(std::string const &subDir = "") {
  // First, the path separator character. MSVC does not behave the same way.
#ifdef MSC_VER
  char const PATH_SEP = '\\';
#else
  char const PATH_SEP = '/';
#endif

  // give the base path static since it should only be called once.
  static std::string baseRes;
  if (baseRes.empty()) {
    char *basePath = SDL_GetBasePath();
    if (basePath) {
      baseRes = basePath;
      SDL_free(basePath);
    }
    else {
      std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
      return "";
    }

    // Find the last bin, replace with res.
    size_t pos = baseRes.rfind("bin");
    baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
  }

  if (subDir.empty()) {
    return baseRes;
  }

  return baseRes + subDir + PATH_SEP;
}

#endif

