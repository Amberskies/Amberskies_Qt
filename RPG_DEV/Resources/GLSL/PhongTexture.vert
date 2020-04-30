#version 330

layout (location = 0) in vec4 position;
layout (location = 1) in vec2 textureCoords;
layout (location = 2) in vec3 normal;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

uniform vec3 u_LightPosition;

const float density = 0.007f;
const float gradient = 1.5f;

out vec2 v_TextureCoords;
out vec3 v_SurfaceNormal;
out vec3 v_ToLightVector;
out vec3 v_ToCameraVector;
out float v_Visibility;


void main()
{
    vec3 worldPosition = vec3(u_Model * position);
    vec4 deltaCamera = u_View * vec4(worldPosition, 1.0f);
    gl_Position = u_Projection * deltaCamera;

    v_TextureCoords = textureCoords;

        // Lighting
    v_SurfaceNormal = vec3(u_Model * vec4(normal, 0.0f));
    v_ToLightVector = u_LightPosition - worldPosition;
    v_ToCameraVector = vec3(
        inverse(u_View)  
        * vec4(0.0f, 0.0f, 0.0f, 1.0f)
    )   - worldPosition;

    // Fog
    float distanceToCamera = length(deltaCamera.xyz);
    v_Visibility = exp(-pow((distanceToCamera * density), gradient));
    v_Visibility = clamp(v_Visibility, 0.0f, 1.0f);

}
