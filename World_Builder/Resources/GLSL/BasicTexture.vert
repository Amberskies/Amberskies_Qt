#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textureCoords;

uniform mat4 u_mvp;

out vec2 v_textureCoords;

void main()
{
    v_textureCoords = textureCoords;

    gl_Position = u_mvp * vec4(
        position,
        1.0f
    );
}
