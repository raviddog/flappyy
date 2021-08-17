#include "engine/engine.hpp"

int score;

float aya_x, aya_y, aya_y_speed;
const float aya_x_speed = 1.f, aya_y_accel = 1.f, aya_jump = 3.f;

engine::SpriteSheet *aya, *bg_objects, *onbashira;

int state = 0;

void logic_game() {
    if(state == 0) {
        //  menu
    } else if(state == 1) {
        //  transition from menu
    } else if(state == 2) {
        //  playing
        

        aya_x += aya_x_speed;
        aya_y_speed += aya_y_accel;
        aya_y += aya_y_speed;
    } else if(state == 3) {
        //  end
    }

    if(engine::checkKeyPressed(engine::jump)) {
        aya_dy += aya_jump;
    }





}

void draw_game() {

}

void load_game() {
    aya_x = 50.f;
    aya_y = 50.f;
    aya_y_speed = 3.f;

    aya = new engine::SpriteSheet("./data/aya.png", 9);
    onbashira = new engine::SpriteSheet("./data/onbashira.png", 2);
    // bg_objects = new engine::SpriteSheet("./data/bg.png", 4);

}

void unload_game() {
    delete aya;
    delete bg_objects;
}