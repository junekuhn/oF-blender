
#version 150

uniform mat4 modelViewProjectionMatrix;
uniform float offset;
uniform float time;

in vec4 position;

// how do I stretch on an arbitrary axis???
//mat4 ScaleOnAxis(float3 a)
//{
//    a = Norm3f(a);
//
//    if(a == x || (a.x == -1.0f && a.y == 0.0f && a.z == 0.0f))
//        return Scale(0.2f, 1.0f, 1.0f);
//
//    float3 axis = Cross(a, x);
//    float theta = acos(Dot(a, x));
//
//    if(theta > pi / 2)
//    {
//        axis = axis * -1.0f;
//        theta = pi - theta;
//    }
//
//    Quaternion ToRotation(axis.x, axis.y, axis.z, theta);
//    Quaternion FromRotation(axis.x, axis.y, axis.z, tau - theta);
//
//    return mat4(FromRotation) * (Scale(float3(0.2f, 1.0f, 1.0f)) * mat4(ToRotation));
//}

//mat4 stretchOnAxis(vec3 a, vec3 x) {
//        //normalize
//    a = normalize(a);
//
//    vec3 axis = cross(a, x);
//    float theta = acos(dot(a,x));
//
//
//    vec4 toRotation(vec3(axis), theta);
//    vec4 fromRotation(vec3(axis), tau - theta);
//
//    return mat4(fromRotation) * mat4(a.x, 0, 0, 0, 0, a.y, 0, 0, 0, 0, a.z, 0, 0, 0, 0, 1) * mat4(fromRotation);
//
//}

vec3 stretch(vec3 position, vec3 axis) {
    axis.x *= smoothstep(-1., 1., position.x)*5.;
    axis.y *= smoothstep(-1., 1., position.y)*5.;
    axis.z *= smoothstep(-1., 1., position.z)*5.;
    return axis;
}

void main(){
    // Simply apply the modelViewProjectionMatrix to all vertex positions
    // to calculate the position of the vertex in the display
    vec3 transformed = position.xyz;
    //smoothstep is min, max, x to be scaled
    
    //this one moves everything except a line across the z axis
    // if it's below the min, return 0
    // if it's above the max, return 1
    // if it's in between, interpolate
//        transformed.x += smoothstep(-5., 5., position.x)*5.;
//    transformed.x -= smoothstep(0., 5., -position.x)*5.;
    
    transformed += stretch(position.xyz, vec3(0.2, 0.3, 2));
    transformed *= sin(transformed) * atan(transformed.z) + 3.;
    
    
    
      gl_Position = modelViewProjectionMatrix * vec4(transformed, 1.0);
}
