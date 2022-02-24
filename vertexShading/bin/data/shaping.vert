#version 150

//notes

//

uniform mat4 modelViewProjectionMatrix;
uniform float offset;
uniform float time;

float noiseScale  = 0.5;

float numOctaves = 2.;

in vec4 position;

mat4 rotation3d(vec3 axis, float angle) {
  axis = normalize(axis);
  float s = sin(angle);
  float c = cos(angle);
  float oc = 1.0 - c;

  return mat4(
        oc * axis.x * axis.x + c,           oc * axis.x * axis.y - axis.z * s,  oc * axis.z * axis.x + axis.y * s,  0.0,
    oc * axis.x * axis.y + axis.z * s,  oc * axis.y * axis.y + c,           oc * axis.y * axis.z - axis.x * s,  0.0,
    oc * axis.z * axis.x - axis.y * s,  oc * axis.y * axis.z + axis.x * s,  oc * axis.z * axis.z + c,           0.0,
        0.0,                                0.0,                                0.0,                                1.0
    );
}

void main(){
    // Simply apply the modelViewProjectionMatrix to all vertex positions
    // to calculate the position of the vertex in the display
      vec3 transformed = position.xyz;
      float stretch = 0.1;
//      transformed.xz *= sin(position.y + time + offset);
//    transformed.y += smoothstep(2., 0., abs(position.y - position.x))*5.;
    transformed.y += smoothstep(offset, 0., abs(position.z*2.))*3.;
    
//    float bulge = smoothstep(offset, 0., abs(position.z*2.))*3.;
    
    
    
    mat4 rotation = rotation3d(vec3(0.4, 0.2, 0.6), time);
    
      gl_Position = modelViewProjectionMatrix * rotation * vec4(transformed, 1.0);
}
