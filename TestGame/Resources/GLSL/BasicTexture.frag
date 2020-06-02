#version 330

in vec2 v_textureCoords;

uniform sampler2D textureSampler;

out vec4 f_FinalColor;

void main(void)
{
    f_FinalColor = texture(
        textureSampler,
        v_textureCoords
    );
}
