#include "hill.h"

//--------------------------------------------------------------
void Hill::setup(float x_in, float y_in) {
    // use current time as seed for random generator
    x = x_in + ((std::rand() % 100) * 80);
    y = y_in;
    collision = false;
    height = ((std::rand() % 200) + 30) * -1;
    speed = 10;
}

//--------------------------------------------------------------
void Hill::draw() {
    ofSetColor(0, 127, 0);
    ofDrawRectangle(x, y, width, height);
}

bool Hill::is_within_bounds(Mario M) {
    bool within_y = (M.y <= y && M.y + M.height > y + height);
    bool within_x = (M.x < x + width && M.x + M.width > x);
    if (within_x && within_y) {
        return true;
    }
    return false;
}

//--------------------------------------------------------------
void Hill::update() {
    if (collision == false) {
        if (dir == -1) {
            x -= speed;
        } else if (dir == 1) {
            x += speed;
        } else {
            x += 0;
        }
    }
    if (x < -width) {
        // x = ofGetWidth();
        setup(ofGetWidth(), y);
    }
}
