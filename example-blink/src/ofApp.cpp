#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofxBcm2835::init();
    ofxBcm2835::pinMode(11, OUTPUT);
}

//--------------------------------------------------------------
void ofApp::update(){

    ofxBcm2835::digitalWrite(11, HIGH);
    ofSleepMillis(100);
    ofxBcm2835::digitalWrite(11, LOW);
    ofSleepMillis(100);
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
