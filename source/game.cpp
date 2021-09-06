#include "engine/engine.hpp"
#include <vector>
#include <ctime>

int score, aya_frame;
double launch_timer;

float aya_x, aya_y, aya_y_speed, pillar_x;
const float aya_x_speed = 480.f, aya_y_accel = 1800.f, aya_jump = -600.f;

engine::SpriteSheet *aya, *bg_objects, *onbashira;
std::vector<float> *pillar_height;


int state = 0;

void logic_game() {
    if(state == 0) {
        //  menu
        launch_timer = 0.;
        aya_x = 150.f;
        aya_y = 528.f;
        aya_y_speed = 0.f;
        aya_frame = 0;
        score = 0;



        if(engine::checkKey(engine::jump)) {
            state = 1;

            pillar_x = 1000.f;
            for(int i = 0; i < 4; i++) {
                float height = ((double)rand() / (double)RAND_MAX) * 600.f + 60.f;
                pillar_height->push_back(height);
            }
        }

    } else if(state == 1) {
        //  transition from menu
        launch_timer += engine::deltatime;
        if(launch_timer < .750) {
            aya_frame = (int)(launch_timer / .125);
        } else {
            aya_frame = 7;
            aya_y_speed = -600.f;
            state = 2;
        }
    } else if(state == 2) {
        //  playing

        pillar_x -= aya_x_speed * engine::deltatime / 2;
        if(pillar_x < aya_x - (aya_x_speed * 2)) {
            score++;
            float height = ((double)rand() / (double)RAND_MAX) * 540.f + 90.f;
            pillar_height->push_back(height);
            pillar_x += aya_x_speed;
        }

        if(engine::checkKeyPressed(engine::jump)) {
            aya_y_speed = aya_jump;
        }

        aya_y_speed += aya_y_accel * engine::deltatime;
        aya_y += aya_y_speed * engine::deltatime;



        //  if collision with pillar
        //  state 3
    } else if(state == 3) {
        //  end
        pillar_height->empty();
        score = 0;
    }






}

void draw_game() {
    if(state == 0) {
        aya->drawSpriteCentered(aya_frame, aya_x, aya_y, 0, 116, 256);
    } else if(state == 1) {
        aya->drawSpriteCentered(aya_frame, aya_x, aya_y, 0, 116, 256);
    } else if(state == 2) {
        aya->drawSpriteCentered(aya_frame, aya_x, aya_y, (-aya_y_speed / 50), 184, 184);
        for(int i = 0; i < 4; i++) {
            onbashira->drawSpriteCentered(0, pillar_x + aya_x_speed * i, pillar_height->at(score + i) + 360.f, 0.f, 240.f, 540.f);
            onbashira->drawSpriteCentered(1, pillar_x + aya_x_speed * i, pillar_height->at(score + i) - 360.f, 180.f, 240.f, 540.f);
        }
        onbashira->buffer();
        onbashira->draw();
    }


    aya->buffer();
    aya->draw();
    
}

void load_game() {
    srand(time(NULL));
    state = 0;
    aya_frame = 0;
    

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
    aya->setSprite(8, 515, 36, 92, 92);

    onbashira->setSprite(0, 0, 0, 80, 180);
    onbashira->setSprite(1, 80, 0, 80, 180);

    engine::SetDrawmode(engine::DrawmodeSprite);
    engine::setDrawsize(960, 720);

    pillar_height = new std::vector<float>();


    // bg_objects = new engine::SpriteSheet("./data/bg.png", 4);

}

void unload_game() {
    delete aya;
    delete onbashira;
}