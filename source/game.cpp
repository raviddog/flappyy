#include "engine/engine.hpp"

int score;

float aya_x, aya_y, aya_y_speed;
const float aya_x_speed = 1.f, aya_y_accel = -1.f, aya_jump = 3.f;

engine::SpriteSheet *aya, *bg_objects, *onbashira;

int state = 0;

void logic_game() {
    if(state == 0) {
        //  menu


        if(engine::checkKey(engine::jump)) {
            aya_y_speed += aya_jump;
        }

        aya_y_speed += aya_y_accel;




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






}

void draw_game() {
    aya->drawSprite(8, 0.f, 0.f, aya_y_speed, 600.f, 600.f);
    aya->buffer();
    aya->draw();
}

void load_game() {
    aya_x = 50.f;
    aya_y = 50.f;
    aya_y_speed = 3.f;

    aya = new engine::SpriteSheet("./data/aya.png", 9);
    onbashira = new engine::SpriteSheet("./data/onbashira.png", 2);


    aya->setSprite(0, 0, 0, 58, 128);
    aya->setSprite(1, 58, 0, 58, 128);
    aya->setSprite(2, 116, 0, 54, 128);
    aya->setSprite(3, 170, 0, 60, 128);
    aya->setSprite(4, 230, 0, 58, 128);
    aya->setSprite(5, 292, 0, 58, 128);
    aya->setSprite(6, 348, 0, 72, 128);
    aya->setSprite(7, 424, 36, 92, 92);
    aya->setSprite(8, 516, 36, 92, 92);

    onbashira->setSprite(0, 0, 0, 80, 180);
    onbashira->setSprite(1, 80, 0, 80, 180);

    engine::SetDrawmode(engine::DrawmodeSprite);



    // bg_objects = new engine::SpriteSheet("./data/bg.png", 4);

}

void unload_game() {
    delete aya;
    delete onbashira;
}