#version 330

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;
in vec3 v_SurfaceNormal;
in vec3 v_ToLightVector;
in vec3 v_ToCameraVector;


uniform sampler2D u_Texture;
uniform vec3 u_LightColor;
uniform float u_ShineDamper;
uniform float u_Reflectivity;

void main()
{
    vec3 unitNormal = normalize(v_SurfaceNormal);
    vec3 unitLightVector = normalize(v_ToLightVector);
    vec3 unitVectorToCamera = normalize(v_ToCameraVector);

    // Phong Lighting equations.
    
    // ambient lighting : background light.
    vec3 ambientLight = vec3(0.1f, 0.05f, 0.025f);

    // diffuse lighting : direct from light source.
    float lightIntensity = dot(unitLightVector, unitNormal);
    vec3 diffuseLight = lightIntensity * u_LightColor;  

    // specular lighting : how much you see reflected.
    vec3 reflectedLightDirection = reflect(-unitLightVector, unitNormal);
    float specularFactor = dot(reflectedLightDirection, unitVectorToCamera);
    float dampedFactor = pow(specularFactor, u_ShineDamper);
    vec3 specularLight = dampedFactor * u_Reflectivity * u_LightColor;

    // Final Lighting
    vec4 lighting = vec4(clamp(specularLight, 0.0f, 1.0f) +
                         clamp(diffuseLight, 0.0f, 1.0f) +  
                         clamp(ambientLight, 0.0f, 1.0f), 1.0f); 
    
    // Final fragment out color
    color = lighting * texture(u_Texture, v_TexCoord);
}
