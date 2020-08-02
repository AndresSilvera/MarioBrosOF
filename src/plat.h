#pragma once

#include "ofMain.h"
#include "mario.h"

class Platform {
  public:
    float x, y;
    float width;
    bool collision;
    const float height = 50;
    void setup(float x_in, float y_in);
    void update(float speed);
    void draw();
    bool is_within_bounds(Mario M);
};
