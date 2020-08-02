#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    M.setup();
    for (int i = 0; i < num_hills; i++) {
        Hills[i].setup(ofGetWidth(), 0.8 * ofGetHeight());
    }
    P.setup(ofGetWidth(), 300);
    // Hills[0].setup(ofGetWidth(), ofGetHeight());
    // Hills[1].setup(ofGetWidth() * 1.5, ofGetHeight());
}
float limiter(float x, float min, float max) {
    if (x > max) {
        return max;
    } else if (x < min) {
        return min;
    } else {
        return x;
    }
}
//--------------------------------------------------------------
void ofApp::update() {

    M.update();
    // checks is_within_bounds for all the hills
    for (int i = 0; i < num_hills; i++) {
        if (Hills[i].is_within_boundsx(M)) {
            if (!Hills[i].is_within_boundsy(M)) {
                // controls when mario is on top of the hills
                if (M.y + M.y_vel * 2 + M.gravity + M.height >
                    Hills[i].y + Hills[i].height) {
                    M.landed = true;
                    M.y_vel = limiter(M.y_vel, -10, 0);
                    M.y = Hills[i].y + Hills[i].height - M.height;
                }
                // M.is_collided = true;
            } else {
                // controls when mario is on either side (L/R) of the  hills
                if (M.is_fwd) {
                    M.speed = limiter(M.speed, -10, 0);
                } else {
                    M.speed = limiter(M.speed, 0, 10);
                }
                M.is_collided = true;
                // M.x = Hills[i].x - M.width;
            }
            // turns off all the hills
            for (int j = 0; j < num_hills; j++) {
                Hills[j].collision = true;
            }
        }
    }
    for (int i = 0; i < num_hills; i++) {
        Hills[i].update(M.speed);
    }
    P.update(M.speed);
    if (P.is_within_bounds(M)) {
        P.collision = true;
    }
}

//--------------------------------------------------------------
void ofApp::draw() {

    M.draw();
    if (M.alive == true) {
        ofSetBackgroundColor(135, 206, 235);
    } else {
        ofSetBackgroundColor(127, 0, 0);
    }
    ofSetColor(0, 200, 0);
    ofDrawRectangle(0, ofGetHeight() * 0.8, ofGetWidth(), ofGetHeight() * 0.2);
    for (int i = 0; i < num_hills; i++) {
        Hills[i].draw();
    }
    P.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

#define OF_KEY_SPACE 32
    if (key == OF_KEY_SPACE) {
        M.jump();
        M.is_collided = false;
    }

    if (key == 'r') {
        M.setup();
        for (int i = 0; i < num_hills; i++) {
            Hills[i].setup(ofGetWidth(), 0.8 * ofGetHeight());
        }
    }

    if (key == 'd' && !(M.is_collided && M.is_fwd)) {
        M.speed = 10;
        M.is_fwd = true;
        M.is_collided = false;
    }

    if (key == 'a' && !(M.is_collided && !M.is_fwd)) {
        M.speed = -10;
        M.is_fwd = false;
        M.is_collided = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    if (key == 'd' || key == 'a') {
        M.speed = 0;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}
