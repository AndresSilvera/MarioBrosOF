#include "plat.h"

//--------------------------------------------------------------
void Platform::setup(float x_in, float y_in) {
    // use current time as seed for random generator
    x = x_in + ((std::rand() % 100) * 80);
    y = y_in;
    collision = false;
    width = ((std::rand() % 200) + 30) * -1;
}

//--------------------------------------------------------------
void Platform::draw() {
    ofSetColor(127, 0, 0);
    ofDrawRectangle(x, y, width, height);
}

bool Platform::is_within_bounds(Mario M) {
    bool within_y = (M.y <= y && M.y + M.height > y + height);
    bool within_x = (M.x < x + width && M.x + M.width > x);
    if (within_x && within_y) {
        return true;
    }
    return false;
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
