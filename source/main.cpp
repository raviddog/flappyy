#include "engine/engine.hpp"

extern void load_game();
extern void logic_game();
extern void draw_game();
extern void unload_game();


int main(int argv, char** args) {
    // engine::init("Flappy Aya", "./flappyy.ini");
    const int flags =   engine::ENGINE_INIT_RESIZEABLE | 
                        engine::ENGINE_INIT_FIXEDASPECT;
    engine::init("Flappy Aya", flags, 960, 720, "./flappyy.ini");

    load_game();

    while(!engine::quit) {
        engine::inputs();

        logic_game();
        draw_game();
        
        engine::flip();
    }
    unload_game();
    engine::close();
    return 0;
}