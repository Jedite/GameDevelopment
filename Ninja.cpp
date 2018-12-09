//
//  Mario.cpp
//  Mario
//
//  Created by Jeremy on 12/5/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Ninja.hpp"
#include "SpriteComponent.hpp"
#include <vector>

Ninja::Ninja(class Game* mGame) {
    std::vector<SDL_Texture*> anims = {
        mGame->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Mario/Mario/Assets/Run__000.png"),
        mGame->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Mario/Mario/Assets/Run__001.png"),
        mGame->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Mario/Mario/Assets/Run__002.png"),
        mGame->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Mario/Mario/Assets/Run__003.png"),
        mGame->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Mario/Mario/Assets/Run__004.png"),
        mGame->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Mario/Mario/Assets/Run__005.png"),
        mGame->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Mario/Mario/Assets/Run__006.png"),
        mGame->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Mario/Mario/Assets/Run__007.png"),
        mGame->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Mario/Mario/Assets/Run__008.png"),
        mGame->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Mario/Mario/Assets/Run__009.png")
    };
    SetAnimTexture(anims);
}

void Ninja::Update() {
    int count = 0;
    if (mAnimTextures.size() > 0) {
        SetTexture(mAnimTextures[count]);
        count ++;
    }
}

void Ninja::SetAnimTexture(const std::vector<SDL_Texture*>& tempTexture) {
    mAnimTextures = tempTexture;
}

void Ninja::SetTexture(SDL_Texture* tempTexture) {
    mTexture = tempTexture;
}

void Ninja::Draw(SDL_Renderer* renderer) {
    SDL_Rect r;
    r.h = 50;
    r.w = 50;
    r.x = 240;
    r.y = 240;
    SDL_RenderCopy(renderer, mTexture, nullptr, &r);
}

//void Ninja::ProcessKeyboard(const uint8_t* state) {
//    
//}
