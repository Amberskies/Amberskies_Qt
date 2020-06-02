#version 330

in vec4 v_Color;
in vec3 v_SurfaceNormal;
in vec3 v_ToLightVector;
in vec3 v_ToCameraVector;
in float v_Visibility;

uniform vec3 u_LightColor;
uniform float u_ShineDamper; // roughness of surface low = rough
uniform float u_Reflectivity; // cloth = low// metalicness med to high // water glass high //
uniform vec3 u_SkyColor;

out vec4 f_FinalColor;

void main(void)
{
    vec3 unitNormal = normalize(v_SurfaceNormal);
    vec3 unitLightVector = normalize(v_ToLightVector);
    vec3 unitVectorToCamera = normalize(v_ToCameraVector);

    // Phong Lighting Equations
    // Ambient lighting : background light
    vec3 ambientLight = vec3(0.05f, 0.02f, 0.01f);

    // diffuse Light : direct light from a Source.
    float lightIntensity = dot(unitLightVector, unitNormal);
    vec3 diffuseLight = lightIntensity * u_LightColor;

    // specular light : how much light is directly reflected to the camera.
    vec3 reflectedLightDirection = reflect(-unitLightVector, unitNormal);
    float specularFactor = dot(reflectedLightDirection, unitVectorToCamera);
    float dampedFactor = pow(specularFactor, u_ShineDamper);
    vec3 specularLight = dampedFactor * u_Reflectivity * u_LightColor;

    // Final Lighting
    vec4 lighting = vec4(clamp(specularLight, 0.01f, 1.0f) +
                         clamp(diffuseLight,  0.01f, 1.0f) +
                         clamp(ambientLight,  0.01f, 1.0f),
                         1.0f
                         );
    // maybe we should clamp the final lighting value ???
    // or leave to get a color saturasion ie Blinding light !

    f_FinalColor = mix(
        vec4(u_SkyColor, 1.0f),
        lighting * v_Color,
        v_Visibility
    );
}
