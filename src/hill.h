#pragma once

#include "ofMain.h"
#include "mario.h"
class Hill {
  public:
    float x, y;
    float height;
    bool collision;
    const float width = 75;
    void setup(float x_in, float y_in);
    void update(float speed);
    void draw();
    bool is_within_boundsx(Mario M);
    bool is_within_boundsy(Mario M);
};
