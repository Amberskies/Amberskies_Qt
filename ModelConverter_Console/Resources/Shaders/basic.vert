#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec3 normals;
layout (location = 2) in vec4 color;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;
uniform vec3 u_LightPosition;


out vec4 v_color;
out vec3 v_SurfaceNormal;
out vec3 v_ToLightVector;
out vec3 v_ToCameraVector;

void main(void)
{
    vec3 worldPosition = vec3(u_Model * position);

    gl_Position = u_Projection * u_View * u_Model * position;
    v_color = color;

    // Lighting
    v_SurfaceNormal = vec3(u_Model * vec4(normals, 0.0f));
    v_ToLightVector = u_LightPosition - worldPosition;
    v_ToCameraVector = vec3(inverse(u_View) * vec4(0.0f, 0.0f, 0.0f, 1.0f)) - worldPosition;

}

