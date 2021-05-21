#ifdef _MSC_VER
#define SDL_MAIN_HANDLED
#endif

#include "engine/engine.hpp"
#include "states.hpp"

const int scrWidth = 640;
const int scrHeight = 480;

int state = 0;

//TODO MOVE THESE TO HEADER
//in next projects, dump the state functions in arrays and replace the switch

int main(int argv, char** args) {
    // engine::init("Flappy Aya", "./flappyy.ini");
    engine::init("Flappy Aya", 0, true, 640, 480);
    //  load initial state
    load_menu();


    while(!engine::quit) {
        engine::inputs();

        int newstate = -1;
        switch(state) {
            case 0:
            default:
                newstate = logic_menu();
                break;
            case 1:
                newstate = logic_game();
                break;
        }
        
        if(newstate > -1) {
            //unload
            //switch to new state
            switch(state) {
                case 0:
                default:
                    unload_menu();
                    break;
                case 1:
                    unload_game();
                    break;
            }

            state = newstate;

            switch(state) {
                case 0:
                default:
                    load_menu();
                    break;
                case 1:
                    load_game();
                    break;
            }
        }

        switch(state) {
            case 0:
            default:
                draw_menu();
                break;
            case 1:
                draw_game();
                break;
        }
        
        engine::flip();
    }
    engine::close();
    return 0;
}