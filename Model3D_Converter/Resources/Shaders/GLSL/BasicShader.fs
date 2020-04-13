#version 330

in vec2 v_TexCoord;
in vec4 v_color;

uniform bool u_hasTexture = false;
uniform sampler2D u_Texture;

void main()
{
    vec4 theColor
    if ( u_hasTexture )
    {
        theColor = texture(u_Texture, v_TexCoord);
    }
    else
    {
        theColor = v_color;
    }
    
    glFragColor = theColor;
}
