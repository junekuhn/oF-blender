#include "ofApp.h"

using namespace glm;
// workflow

// draw the shader object first, end the shader, then draw the rest of the scene

//--------------------------------------------------------------
void ofApp::setup(){
    //load the shader
    starterShader.load("starter");
    guiShader.load("gui");
    shapingShader.load("shaping");
    embroiderShader.load("embroider");
    
    currentShader = embroiderShader;
    // Settings for the 3D camera
    myCamera.setPosition(vec3(0.0, 8.0, 24.0));
    myCamera.setTarget(vec3(0.0, 4.0, 0.0));
    myCamera.setFov(32.0);
    myCamera.setNearClip(0.05);
    myCamera.setFarClip(300.0);
    myCamera.setAutoDistance(false);
    
    myMesh.setRadius( 10);
    ofDisableArbTex();
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
    currentShader.setUniform1f("time", ofGetElapsedTimef());
    
    myMesh.setPosition(0,0,0);
    myMesh.draw();

    currentShader.end();
    
    // Draw a grid (which will be drawn using the default openFrameworks shader)
//    ofDrawGrid(2.0, 10, false, false, true, false);
//    ofDrawRotationAxes(10);
    ofDrawAxis(20);
    // red is x, green is y, and blue is z
    
    myCamera.end();
    ofDisableDepthTest();
    
    myGui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    myMesh.getMesh().save(std::string("vertices") + std::to_string(ofGetElapsedTimeMillis()) + std::string(".ply"), false);
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
