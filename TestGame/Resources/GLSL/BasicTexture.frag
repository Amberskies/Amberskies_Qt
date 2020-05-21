#version 330

in vec2 v_textureCoords;

uniform sampler2D textureSampler;

void main(void)
{
    gl_FragColor = texture(
        textureSampler,
        v_textureCoords
    );
}
