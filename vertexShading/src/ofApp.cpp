#include "ofApp.h"

using namespace glm;
// workflow

// draw the shader object first, end the shader, then draw the rest of the scene

//--------------------------------------------------------------
void ofApp::setup(){
    //load the shader
    starterShader.load("starter");
    guiShader.load("gui");
    
    currentShader = guiShader;
    // Settings for the 3D camera
    myCamera.setPosition(vec3(0.0, 8.0, 24.0));
    myCamera.setTarget(vec3(0.0, 4.0, 0.0));
    myCamera.setFov(32.0);
    myCamera.setNearClip(0.05);
    myCamera.setFarClip(100.0);
    myCamera.setAutoDistance(false);
    
    myMesh.setRadius( 10);
    
    myGui.setup();
    
    myGui.add(offset.setup("Offset", 0.5, 0., 1., 200, 20));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    // Setup rendering in 3D
    ofEnableDepthTest();
    myCamera.begin();
    
    currentShader.begin();
    
    // Draw a rectangle that fills the display window
    //necessary to draw the shader
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    currentShader.setUniform1f("offset", offset);
    
    myMesh.setPosition(0,5,0);
    myMesh.drawWireframe();

    currentShader.end();
    
    // Draw a grid (which will be drawn using the default openFrameworks shader)
    ofDrawGrid(2.0, 10, false, false, true, false);
    
    myCamera.end();
    ofDisableDepthTest();
    
    myGui.draw();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
