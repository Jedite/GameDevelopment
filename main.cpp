//
//  main.cpp
//  Mario
//
//  Created by Jeremy on 11/24/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Game.hpp"

int main(int argc, const char * argv[]) {
    Game mGame;
    if (mGame.Init()) {
        mGame.Update();
    }
    return 0;
}
