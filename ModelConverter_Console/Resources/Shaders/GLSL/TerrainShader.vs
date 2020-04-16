#version 330

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 textureCoord;
layout(location = 2) in vec3 normal;

out vec2 v_TexCoord;
out vec3 v_SurfaceNormal;
out vec3 v_ToLightVector;
out vec3 v_ToCameraVector;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

uniform vec3 u_LightPosition;

void main()
{
    vec3 worldPosition = vec3(u_Model * position);

    gl_Position = u_Projection * u_View * vec4(worldPosition, 1.0f); 

    v_TexCoord = textureCoord;

    // Lighting
    v_SurfaceNormal = vec3(u_Model * vec4(normal, 0.0f));
    v_ToLightVector = u_LightPosition - worldPosition;
    v_ToCameraVector = vec3(inverse(u_View) * vec4(0.0f, 0.0f, 0.0f, 1.0f)) - worldPosition;
}