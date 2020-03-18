#version 330

layout (location = 0) in vec3 position;

out vec3 v_color;

void main()
{
    gl_Position = 
        vec4(
            position,
            1.0f
    );

    v_color =
        vec3(
            position.x + 0.5f,
            1.0f,
            position.y + 0.5f
    );
}

