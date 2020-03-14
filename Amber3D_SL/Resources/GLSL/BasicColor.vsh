#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

uniform mat4 u_mvp;

out vec4 v_color;

void main()
{
    gl_Position = u_mvp * vec4(position, 1.0f);
    v_color = color;
}
