
#version 150

uniform mat4 modelViewProjectionMatrix;
uniform float offset;

in vec4 position;

void main(){
    // Simply apply the modelViewProjectionMatrix to all vertex positions
    // to calculate the position of the vertex in the display
      vec3 transformed = position.xyz;
        float stretch = 0.1;
        transformed.xz *= sin(position.y*0.3 + offset);
      gl_Position = modelViewProjectionMatrix * vec4(transformed, 1.0);
}
