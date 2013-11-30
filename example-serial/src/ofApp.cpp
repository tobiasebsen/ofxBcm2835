#include "ofApp.h"

using namespace ofxBcm2835;

//--------------------------------------------------------------
void ofApp::setup(){

    ofxBcm2835::init();
    
    Serial.begin(57600);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    unsigned char buffer[32];
    buffer[0] = 0x80;
    buffer[1] = 0x84;
    buffer[2] = 0x00;
    for (int i=3; i<31; i++) buffer[i] = 0x7F;
    buffer[31] = 0x8F;

    Serial.write(buffer, 32);
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
