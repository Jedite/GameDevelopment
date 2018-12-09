//
//  Game.hpp
//  Mario
//
//  Created by Jeremy on 11/24/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>

using namespace std;
class Game {
public:
    Game();
    bool Init();
    void Update();
    void Events();
    void IterateCSV();
    SDL_Texture* GetTexture(const std::string& FILENAME);
    void SetBGTexture(SDL_Texture* tempTexture);
private:
    bool mIsRunning;
    SDL_Texture* bgTexture;
    SDL_Renderer* mRenderer;
    SDL_Window* mWindow;
    int count = 0;
    int instVar;
    class Ninja* mNinja;
    class SpriteComponent* sc;
};
