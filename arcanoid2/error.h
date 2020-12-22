#pragma once
#include <iostream>
#include "SDL_error.h"
using namespace std;
class Exception {
private:
    int warning;
public:
    Exception() {
        warning = 0;
    };
    Exception(int error) {
        warning = error;
    }
    void Print()
    {
        if (this->warning == 2)
        {
            std::cout << "There isn't scene" <<std::endl<< "Going to the first scene" << std::endl;
        }
        if (this->warning == 3)
        {
            cout << "Can't play music " << SDL_GetError() << endl;
        }
        if (this->warning == 4)
        {
            cout << "SDL_MiXER error " << SDL_GetError() << endl;
        }
        if (this->warning == 5)
        {
            cout << "There is no music" << endl;
        }
        if (this->warning == 6)
        {
            cout << "Can't read music" << endl;
        }
        if (this->warning == 7)
        {
            cout << "There is no sound" << endl;
        }
        if (this->warning == 8)
        {
            cout << "Can't read sound" << endl;
        }
    }
};
