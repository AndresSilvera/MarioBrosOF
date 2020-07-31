#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    M.setup();
    for (int i = 0; i < num_hills; i++) {
        Hills[i].setup(ofGetWidth(), 0.8 * ofGetHeight());
    }
    // Hills[0].setup(ofGetWidth(), ofGetHeight());
    // Hills[1].setup(ofGetWidth() * 1.5, ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update() {

    M.update();
    // checks is_within_bounds for all the hills
    for (int i = 0; i < num_hills; i++) {
        Hills[i].update();
        if (Hills[i].is_within_bounds(M)) {
            M.alive = false;
            // turns off all the hills
            for (int j = 0; j < num_hills; j++) {
                Hills[j].collision = true;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {

    M.draw();
    ofSetColor(0, 200, 0);
    ofDrawRectangle(0, ofGetHeight() * 0.8, ofGetWidth(), ofGetHeight() * 0.2);

    for (int i = 0; i < num_hills; i++) {
        Hills[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

#define OF_KEY_SPACE 32
    if (key == OF_KEY_SPACE) {
        M.jump();
    }

    if (key == 'r') {
        M.setup();
        for (int i = 0; i < num_hills; i++) {
            Hills[i].setup(ofGetWidth(), 0.8 * ofGetHeight());
        }
    }

    if (key == 'd') {
        for (int i = 0; i < num_hills; i++) {
            Hills[i].dir = -1;
        }
    }

    if (key == 'a') {
        for (int i = 0; i < num_hills; i++) {
            Hills[i].dir = 1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    if (key == 'd' || key == 'a') {
        for (int i = 0; i < num_hills; i++) {
            Hills[i].dir = 0;
        }
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
