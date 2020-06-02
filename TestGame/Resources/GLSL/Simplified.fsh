#version 330

in vec3 v_color;

out vec4 f_FinalColor;

void main(void)
{
    f_FinalColor = 
        vec4(
            v_color,
            1.00f
    );
}
