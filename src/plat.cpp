#include "plat.h"

//--------------------------------------------------------------
void Platform::setup(float x_in, float y_in) {
    // use current time as seed for random generator
    x = x_in + ((std::rand() % 100) * 80);
    y = y_in;
    collision = false;
    width = ((std::rand() % 20) + 30) * 15;
}

//--------------------------------------------------------------
void Platform::draw() {
    ofSetColor(127, 0, 0);
    ofDrawRectangle(x, y, width, height);
}

bool Platform::is_within_boundsx(Mario M) {
    float next_M_x = M.x + M.speed;
    bool within_x = (next_M_x < x + width && next_M_x + M.width > x);
    return within_x;
}

bool Platform::is_within_boundsy(Mario M) {
    float next_M_y = M.y + M.y_vel;
    bool within_y = (next_M_y < y && next_M_y + M.height > y + height);
    return within_y;
}

//--------------------------------------------------------------
void Platform::update(float speed) {
    x -= speed;
    if (collision == true) {
    }
    if (x < -width) {
        // x = ofGetWidth();
        setup(ofGetWidth(), y);
    }
}
