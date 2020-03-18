#version 330

in vec3 v_color;

void main(void)
{
    gl_FragColor = 
        vec4(
            v_color,
            1.00f
    );
}
