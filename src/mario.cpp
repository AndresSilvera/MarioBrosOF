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
    speed = 0;
    is_fwd = true;
    is_collided = false;
}

//--------------------------------------------------------------
void Mario::draw() {
    if (tall == true) {
        height = 80;
    } else {
        height = 40;
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

    // applies gravity when in the air
    if (!landed) {
        y_vel += gravity;
    }
    y += terminalVelocity(y_vel);
    // updates landing on the ground
    if (y + height > ofGetHeight() * 0.8) {
        y = (ofGetHeight() * 0.8) - height;
        y_vel = 0;
        landed = true;
    } else {
        if (!on_platform) {
            landed = false;
        }
    }
    // resets jump count when landed
    if (landed == true) {
        jumpcount = 0;
    }
}

//--------------------------------------------------------------
void Mario::jump() {
    if ((alive == true) && (jumpcount < 2)) {
        jumpcount += 1;
        y_vel += lift;
        landed = false;
    }
}
