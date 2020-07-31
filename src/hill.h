#pragma once

#include "ofMain.h"
#include "mario.h"
class Hill {
  public:
    float x, y;
    float height;
    bool collision;
    const float width = 75;
    float speed;
    int dir = 0;
    void setup(float x_in, float y_in);
    void update();
    void draw();
    bool is_within_bounds(Mario M);
};
