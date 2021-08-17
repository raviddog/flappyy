#include "engine/engine.hpp"

const int scrWidth = 640;
const int scrHeight = 480;


int main(int argv, char** args) {
    // engine::init("Flappy Aya", "./flappyy.ini");
    engine::init("Flappy Aya", 0, true, 640, 480);

    while(!engine::quit) {
        engine::inputs();

        
        engine::flip();
    }
    engine::close();
    return 0;
}