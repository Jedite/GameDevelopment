//
//  Mario.hpp
//  Mario
//
//  Created by Jeremy on 12/5/18.
//  Copyright © 2018 Jeremy. All rights reserved.

#include "Game.hpp"
#include <vector>

class Ninja: public Game {
public:
    Ninja(class Game* mGame);
    void Draw(SDL_Renderer* renderer);
    void SetAnimTexture(const std::vector<SDL_Texture*>& tempTexture);
    void Update();
    //    void ProcessKeyboard(const uint8_t* state);
private:
    std::vector<SDL_Texture*> mAnimTextures;
    SDL_Texture* mTexture;
};
