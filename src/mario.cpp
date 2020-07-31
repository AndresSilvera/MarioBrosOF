#include "mario.h"

//--------------------------------------------------------------
void Mario::setup() {
    x = (ofGetWidth() * 0.5) - 15;
    y = ofGetHeight() * 0.8;
    y_vel = 0;
    width = 30;
    height = 40;
    tall = false;
    alive = true;
    jumpcount = 0;
    landed = true;
}

//--------------------------------------------------------------
void Mario::draw() {
    if (tall == true) {
        height = 80;
    } else {
        height = 40;
    }
    if (alive == true) {
        ofSetBackgroundColor(135, 206, 235);
    } else {
        ofSetBackgroundColor(127, 0, 0);
    }
    ofSetColor(255, 0, 0);
    ofDrawRectangle(x, y, width, height);
}
float terminalVelocity(float y_vel) {
    const float maxvel = -20;
    if (y_vel < maxvel) {
        return maxvel;
    }
    return y_vel;
}
//--------------------------------------------------------------
void Mario::update() {

    y_vel += gravity;
    y += terminalVelocity(y_vel);

    if (y + height > ofGetHeight() * 0.8) {
        y = (ofGetHeight() * 0.8) - height;
        y_vel = 0;
        landed = true;
    } else {
        landed = false;
    }

    if (landed == true) {
        jumpcount = 0;
    }
}

//--------------------------------------------------------------
void Mario::jump() {
    if ((alive == true) && (jumpcount < 10)) {
        jumpcount += 1;
        y_vel += lift;
    }
}
