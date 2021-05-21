#include "engine/engine.hpp"

int score;

float aya_x, aya_y, aya_dy;
const float aya_dx = 1.f, aya_d2y = 1.f, aya_jump = 3.f;

engine::SpriteSheet *aya, *bg_objects;

int logic_game() {
    if(engine::checkKeyPressed(engine::kb::Escape)) {
        return 0;
    }

    if(engine::checkKeyPressed(engine::kb::Space)) {
        aya_dy += aya_jump;
    }

    aya_dy += aya_d2y;
    aya_y += aya_dy;

    aya_x += aya_dx;




    return -1;
}

void draw_game() {

}

void load_game() {
    aya_x = 50.f;
    aya_y = 50.f;
    aya_dy = 3.f;

    aya = new engine::SpriteSheet("./data/aya.png", 1);
    bg_objects = new engine::SpriteSheet("./data/bg.png", 4);

}

void unload_game() {
    delete aya;
    delete bg_objects;
}