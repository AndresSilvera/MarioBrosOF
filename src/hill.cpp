#include "hill.h"

//--------------------------------------------------------------
void Hill::setup(float x_in, float y_in) {
    // use current time as seed for random generator
    x = x_in + ((std::rand() % 100) * 75);
    y = y_in;
    collision = false;
    height = ((std::rand() % 200) + 30) * -1;
}

//--------------------------------------------------------------
void Hill::draw() {
    ofSetColor(0, 127, 0);
    ofDrawRectangle(x, y, width, height);
}

bool Hill::is_within_boundsx(Mario M) {
    float next_M_x = M.x + M.speed;
    bool within_x = (next_M_x < x + width && next_M_x + M.width > x);
    return within_x;
}

bool Hill::is_within_boundsy(Mario M) {
    float next_M_y = M.y + M.y_vel;
    bool within_y = (next_M_y < y && next_M_y + M.height > y + height);
    return within_y;
}

//--------------------------------------------------------------
void Hill::update(float speed) {
    x -= speed;

    // if (x < -width) {
    //     // x = ofGetWidth();
    //     setup(ofGetWidth(), y);
    // }
}
