#pragma once
#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_OXYGEN
    #define OXYGEN_PUBLIC __declspec(dllexport)
  #else
    #define OXYGEN_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_OXYGEN
      #define OXYGEN_PUBLIC __attribute__ ((visibility ("default")))
  #else
      #define OXYGEN_PUBLIC
  #endif
#endif

#include <cstdio>
#include <cstdlib>
#include <string>

namespace Discord {

  struct Color {
  public:
    std::string Black;
    std::string White;
    std::string Blue;
    std::string Red;
    std::string Green;
    std::string Yellow;
    std::string Magenta;
    std::string Cyan;

    Color() {
      Black = CBlack;
      White = CWhite;
      Blue = CBlue;
      Red = CRed;
      Green = CGreen;
      Yellow = CYellow;
      Magenta = CMagenta;
      Cyan = CCyan; 
    }
  private:
    std::string CBlack = "\u001b[30m";
    std::string CWhite = "\u001b[37m";
    std::string CBlue = "\u001b[34m";
    std::string CRed = "\u001b[31m";
    std::string CGreen = "\u001b[32m";
    std::string CYellow = "\u001b[33m";
    std::string CMagenta = "\u001b[35m";
    std::string CCyan = "\u001b[36m";
    std::string CResetColor = "\u001b[0m";
  };

  class Client {
  public:
  };
}
