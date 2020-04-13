#version 330

layout ( location = 0 ) in vec4 position;
layout ( location = 1 ) in vec2 textureCoord;
layout ( location = 2 ) in vec4 color = vec4(0.5f, 0.5f, 0.5f, 1.0f);

uniform mat4 u_mvp;

out vec2 v_TexCoord;
out vec4 v_color; 

void main()
{
    gl_Position = u_mvp * position;
    v_TexCoord = textureCoord;
    v_color = color;
}
