#pragma once

#include "ofMain.h"

class Mario {

  public:
    float y;
    float x;
    float width;
    float height;
    float jumpcount;
    bool tall;
    bool landed;
    float speed;
    bool is_fwd;
    bool is_collided;
    const float gravity = 1.5;
    const float lift = -25;
    float y_vel;
    bool alive;
    bool on_platform;
    void setup();
    void jump();
    void update();
    void draw();
};
