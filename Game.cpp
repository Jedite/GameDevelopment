//
//  Game.cpp
//  Mario
//
//  Created by Jeremy on 11/24/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Game.hpp"
#include "Ninja.hpp"
#include "SpriteComponent.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

Game::Game():mIsRunning(true) {
    
}

bool Game::Init() {
    SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
    mWindow = SDL_CreateWindow("Window", 100, 100, 480, 480, 0);
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED |SDL_RENDERER_PRESENTVSYNC);
    IMG_Init(IMG_INIT_PNG);
    mNinja = new Ninja(this);
//    sc = new SpriteComponent();
    return true;
}

void Game::Events() {
    SDL_Event mEvent;
    while (SDL_PollEvent(&mEvent)) {
        switch (mEvent.type) {
            case SDL_QUIT:
                mIsRunning = false;
        }
    }
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE]) {
        mIsRunning = false;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        count += 1;
    }
    else if (state[SDL_SCANCODE_LEFT]) {
        count -= 1;
    }
}


void Game::Update() {
    while (mIsRunning) {
        Events();
        SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255);
        SDL_RenderClear(mRenderer);
        IterateCSV();
        mNinja->Draw(mRenderer);
        SDL_RenderPresent(mRenderer);
    }
}

SDL_Texture* Game::GetTexture(const std::string& FILENAME) {
    SDL_Surface* tempSurface = IMG_Load(FILENAME.c_str());
    SDL_Texture* permTexture = SDL_CreateTextureFromSurface(mRenderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return permTexture;
}

void Game::IterateCSV() {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), 16));
    float deltaTime = SDL_GetTicks() / 1000.0f;
    if (deltaTime > 0.25f) {
        deltaTime = 0.25f;
    }
    string line;
    ifstream myFile;
    SDL_Rect src;
    src.h = 32;
    src.w = 32;
    src.x = 32 * count * deltaTime;
    src.y = 0;
    SDL_Rect dst;
    dst.h = 32;
    dst.w = 32;
    dst.x = 0;
    dst.y = 0;
    SDL_Texture* tempTex = GetTexture("/Users/Jeremy/Desktop/C++/SDL/Mario/Mario/biggerMap.png");
    SetBGTexture(tempTex);
  //  int numArr[1];
    ifstream in("/Users/Jeremy/Desktop/C++/SDL/Mario/Mario/biggerMap.csv");
    vector<vector<double>> fields;
    if (in) {
        string line;
        while (getline(in, line)) {
            stringstream sep(line);
            string field;
            fields.push_back(vector<double>());
            while (getline(sep, field, ',')) {
                fields.back().push_back(stod(field));
            }
        }
    }
    for (auto row : fields) {
        for (auto field : row) {
           SDL_RenderCopy(mRenderer, bgTexture, &src, &dst);
            dst.x += 32;
            src.x += 32;
        }
        src.x = 32 * count * deltaTime;
        src.y += 32;
        dst.x = 0;
        dst.y += 32;
    }
}

void Game::SetBGTexture(SDL_Texture* tempTexture) {
    bgTexture = tempTexture;
}
