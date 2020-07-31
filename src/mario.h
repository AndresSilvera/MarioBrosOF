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
    const float gravity = 1.5;
    const float lift = -20;
    float y_vel;
    bool alive;
    void setup();
    void jump();
    void update();
    void draw();
};
