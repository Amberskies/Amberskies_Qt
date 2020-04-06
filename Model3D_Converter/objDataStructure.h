#pragma once

#include <QString>



namespace Model
{
    /*Lines beginning with a hash character(#) are comments.
    # this is a comment

    Do nothing for a comment


    Relative and absolute indices[edit]
    OBJ files, due to their list structure, are able to reference vertices, normals, etc.either by their absolute position(1 represents the first defined vertex, N representing the Nth defined vertex), or by their relative position(-1 represents the latest defined vertex).However, not all software supports the latter approach, and conversely some software inherently writes only the latter form(due to the convenience of appending elements without needing to recalculate vertex offsets, etc.), leading to occasional incompatibilities.

    An OBJ file may contain vertex data, free - form curve / surface attributes, elements, free - form curve / surface body statements, connectivity between free - form surfaces, grouping and display / render attribute information.The most common elements are geometric vertices, texture coordinates, vertex normals and polygonal faces :

    # List of geometric vertices, with(x, y, z[, w]) coordinates, w is optional and defaults to 1.0.
    v 0.123 0.234 0.345 1.0
    v ...
        Geometric vertex[edit]
    A vertex can be specified in a line starting with the letter v.That is followed by(x,y,z[,w]) coordinates.W is	optional and defaults to 1.0.Some applications support vertex colors, by putting red, green and blue values		after x	   y and z.The color values range from 0 to 1.[1]
    */

    struct Vertex
    {
        float m_x, m_y, m_z; //, m_w; w is handled by the shader

        Vertex(float x, float y, float z) :
            m_x(x), m_y(y), m_z(z) {}
    };

    /*# List of texture coordinates, in(u, [v, w]) coordinates, these will vary between 0 and 1, v and w are optional and	default to 0.
    vt 0.500 1[0]
    vt ...
    */

    struct TextureCoordinate
    {
        float m_u, m_v, m_w;

        TextureCoordinate(float u, float v = 0.0f, float w = 0.0f) :
            m_u(u), m_v(v), m_w(w) {}
    };

    /* # List of vertex normals in(x, y, z) form; normals might not be unit vectors.
        vn 0.707 0.000 0.707
        vn ...
    */

    struct VertexNormals
    {
        float m_x, m_y, m_z;

        VertexNormals(float x, float y, float z) :
            m_x(x), m_y(y), m_z(z) {}
    };

    /* # Parameter space vertices in(u[, v][, w]) form; free form geometry statement(see below)
        vp 0.310000 3.210000 2.100000
        vp ...
    Parameter space vertices[edit]
    A free - form geometry statement can be specified in a line starting with the string vp.Define points in parameter space of a curve or surface.u only is required for curve points, u and v for surface points and control points of non - rational trimming curves, and u, v and w(weight) for control points of rational trimming curves.
    */

    struct VertexParameter
    {
        float m_u, m_v, m_w;

        VertexParameter(float u, float v = 0.0f, float w = 0.0f) :
            m_u(u), m_v(v), m_w(w) {}
    };

    /*# Polygonal face element(see below)
        f 1 2 3
        f 3/1 4/2 5/3
        f 6/4/1 3/5/3 7/6/ 5
        f 7//1 8//2 9//3
        f ...
    Face elements[edit]
    Faces are defined using lists of vertex, texture and normal indices.Polygons such as quadrilaterals can be defined by using more than three vertex / texture / normal indices.
    OBJ files also support free - form geometry which use curves and surfaces to define objects, such as NURBS surfaces.
    Vertex indices[edit]
    A valid vertex index matches the corresponding vertex elements of a previously defined vertex list.If an index is positive then it refers to the offset in that vertex list, starting at 1. If an index is negative then it relatively refers to the end of the vertex list, -1 referring to the last element.
    Each face can contain three or more vertices.
        f v1 v2 v3 ....
        Vertex texture coordinate indices[edit]
    Optionally, texture coordinate indices can be used to specify texture coordinates when defining a face.To add a texture coordinate index to a vertex index when defining a face, one must put a slash immediately after the vertex index and then put the texture coordinate index.No spaces are permitted before or after the slash.A valid texture coordinate index starts from 1 and matches the corresponding element in the previously defined list of texture coordinates.Each face can contain three or more elements.
        f v1 / vt1 v2 / vt2 v3 / vt3 ...
    Vertex normal indices[edit]
    Optionally, normal indices can be used to specify normal vectors for vertices when defining a face.To add a normal index to a vertex index when defining a face, one must put a second slash after the texture coordinate index and then put the normal index.A valid normal index starts from 1 and matches the corresponding element in the previously defined list of normals.Each face can contain three or more elements.
        f v1 / vt1 / vn1 v2 / vt2 / vn2 v3 / vt3 / vn3 ...
    Vertex normal indices without texture coordinate indices[edit]
    As texture coordinates are optional, one can define geometry without them, but one must put two slashes after the vertex index before putting the normal index.
        f v1//vn1 v2//vn2 v3//vn3 ...
    */

    /*
    Update Struct to construct with bool values for isQuad, hasTextures, hasNormals, so it can
    be fully automated from the file reader/dataStore classes. */

    struct FaceElement
    {
        int m_vertexIndex[4];
        int m_textureIndex[4];
        int m_normalIndex[4];
        int m_currentColor = -1;
        bool m_hasTextures, m_hasNormals;


        FaceElement(int vertex0, int texture0, int normal0,
                    int vertex1, int texture1, int normal1,
                    int vertex2, int texture2, int normal2,
                    int currentColor, bool hasTextures, bool hasNormals)
        {
            m_vertexIndex[0] = vertex0;
            m_vertexIndex[1] = vertex1;
            m_vertexIndex[2] = vertex2;

            m_textureIndex[0] = texture0;
            m_textureIndex[1] = texture1;
            m_textureIndex[2] = texture2;

            m_normalIndex[0] = normal0;
            m_normalIndex[1] = normal1;
            m_normalIndex[2] = normal2;

            m_currentColor = currentColor;
            m_hasTextures = hasTextures;
            m_hasNormals = hasNormals;
        }
// glDrawElements does not support GL_QUADS
//        FaceElement(int vertex0, int texture0, int normal0,
//            int vertex1, int texture1, int normal1,
//            int vertex2, int texture2, int normal2,
//            int vertex3, int texture3, int normal3,
//            int currentColor, bool hasTextures, bool hasNormals)
//        {
//            m_vertexIndex[0] = vertex0;
//            m_vertexIndex[1] = vertex1;
//            m_vertexIndex[2] = vertex2;
//            m_vertexIndex[3] = vertex3;

//            m_textureIndex[0] = texture0;
//            m_textureIndex[1] = texture1;
//            m_textureIndex[2] = texture2;
//            m_textureIndex[3] = texture3;

//            m_normalIndex[0] = normal0;
//            m_normalIndex[1] = normal1;
//            m_normalIndex[2] = normal2;
//            m_normalIndex[3] = normal3;

//            m_currentColor = currentColor;
//            m_hasTextures = hasTextures;
//            m_hasNormals = hasNormals;
//        }
    };

    /* # Line element(see below)
        l 5 8 1 2 4 9

    Line elements[edit]
    Records starting with the letter "l" specify the order of the vertices which build a polyline.
        l v1 v2 v3 v4 v5 v6 ...
    */

    struct LineElement
    {
        int m_lineElement;

        LineElement(int lineElement) :
            m_lineElement(lineElement) {}
    };

    /*Other geometry formats[edit]
    Obj files support higher - order surfaces using several different kinds of interpolation, such as Taylor and B - splines, although support for those features in third party file readers is far from universal.Obj files also do not support mesh hierarchies or any kind of animation or deformation, such as vertex skinning or mesh morphing.
    Referencing materials[edit]
    Materials that describe the visual aspects of the polygons are stored in external.mtl files.More than one external MTL material file may be referenced from within the OBJ file.The.mtl file may contain one or more named material definitions.
    */

    /*mtllib[external.mtl file name]
    //	...
    */

    struct MaterialFileName
    {
        QString m_fileName;

        MaterialFileName(QString fileName) :
            m_fileName(fileName) {}
    };

    /*	This tag specifies the material name for the element following it.The material name matches a named material definition in an external.mtl file.
    usemtl[material name]
    */

    struct UseMaterial
    {
        QString m_useMaterialName;

        UseMaterial(QString useMaterialName) :
            m_useMaterialName(useMaterialName) {}
    };

    /*Named objects and polygon groups are specified via the following tags.
        o[object name]
        ...
        g[group name]
        ...
    */

    struct ObjectName
    {
        QString m_objectName;

        ObjectName(QString objectName) :
            m_objectName(objectName) {}
    };

    struct GroupName
    {
        QString m_groupName;

        GroupName(QString groupName) :
            m_groupName(groupName) {}
    };

    /*Smooth shading across polygons is enabled by smoothing groups.
        s 1
        ...
        # Smooth shading can be disabled as well.
        s off
        ...
    */

    struct SmoothShading
    {
        QString m_smoothShading;

        SmoothShading(QString smoothShading) :
            m_smoothShading(smoothShading) {}
    };

    ///////////////////////////// MTL File //////////////////////////////////

    /*    Material template library[edit]
        MTL material format
        Filename extension
        .mtl
        Developed by
        Wavefront Technologies
        Type of format
        3D texture format
        The Material Template Library format(MTL) or .MTL File Format is a companion file format to.OBJ, also defined by Wavefront Technologies, that describes surface shading(material) properties of objects within one or more.OBJ files.A.OBJ file references one or more.MTL files(called "material libraries"), and from there, references one or more material descriptions by name..MTL files are ASCII text that define the light reflecting properties of a surface for the purposes of computer rendering, and according to the Phong reflection model.The standard has widespread support among different computer software packages, making it a useful format for interchange of materials.
        The MTL format, although still widely used, is outdated and does not fully support later technologies such as specular maps and parallax maps.However, due to the open and intuitive nature of the format, these can easily be added with a custom MTL file generator.
        The MTL format defines a number of formats.[2][3] - see wiki
        Basic materials[edit]
        A single.mtl file may define multiple materials.Materials are defined one after another in the file, each starting with the newmtl command :
    */

    /*
# define a material named 'Colored'
    newmtl Colored
    */

    struct MaterialName
    {
        QString m_materialName;

        MaterialName(QString materialName) :
            m_materialName(materialName) {}
    };


    /*The ambient color of the material is declared using Ka.Color definitions are in RGB where each channel's value is between 0 and 1.
        Ka 1.000 1.000 1.000     # white
    */

    struct AmbientColor
    {
        float m_red, m_green, m_blue;

        AmbientColor(float red, float green, float blue) :
            m_red(red), m_green(green), m_blue(blue) {}
    };

    /*Similarly, the diffuse color is declared using Kd.
        Kd 1.000 1.000 1.000     # white
    */

    struct DiffuseColor
    {
        float m_red, m_green, m_blue;
        DiffuseColor(float red, float green, float blue) :
            m_red(red), m_green(green), m_blue(blue) {}
    };

    /*The specular color is declared using Ks, and weighted using the specular exponent Ns.
        Ks 0.000 0.000 0.000     # black(off)
    */

    struct SpecularColor
    {
        float m_red, m_green, m_blue;

        SpecularColor(float red, float green, float blue) :
            m_red(red), m_green(green), m_blue(blue) {}
    };

    /* Specular Highlight Component
    The specular color is declared using Ks, and weighted using the specular exponent Ns
    Ns 10.000                # ranges between 0 and 1000
    */

    struct SpecularHighlightComponent  // **************** this is NOT a Color *****************************
    {
        float m_specularHighlightComponent; // change to float specularHighlight

        SpecularHighlightComponent(float specularHighlightComponent) :
            m_specularHighlightComponent(specularHighlightComponent) {}
    };

    /*
    Ke stands for emissive coeficient. It goes together with ambient, diffuse and specular and represents the amount of light emitted by the material. If you also have a defined emission color the material will irradiate light.
    */
    struct EmissiveCoeficient
    {
        float m_red, m_green, m_blue;

        EmissiveCoeficient(float red, float green, float blue) :
            m_red(red), m_green(green), m_blue(blue) {}
    };

    /*
    Ni = Refraction index. A value of 1 will cause no refraction.
    */

    struct RefractionIndex
    {
        float m_refractionIndex;

        RefractionIndex(float refractionIndex) :
            m_refractionIndex(refractionIndex) {}
    };

    /*Materials can be transparent.This is referred to as being dissolved.Unlike real transparency, the result does not depend upon the thickness of the object.A value of 1.0 for "d" is the default and means fully opaque, as does a value of 0.0 for "Tr".
        d 0.9                    # some implementations use 'd'
        Tr 0.1                   # others use 'Tr' (inverted: Tr = 1 - d)
    */

    struct Transparency
    {
        float m_transparency;

        Transparency(float transparency) :
            m_transparency(transparency) {}
    };

    /*Multiple illumination models are available, per material.These are enumerated as follows :
        0. Color on and Ambient off
        1. Color on and Ambient on
        2. Highlight on
        3. Reflection on and Ray trace on
        4. Transparency : Glass on, Reflection : Ray trace on
        5. Reflection : Fresnel on and Ray trace on
        6. Transparency : Refraction on, Reflection : Fresnel off and Ray trace on
        7. Transparency : Refraction on, Reflection : Fresnel on and Ray trace on
        8. Reflection on and Ray trace off
        9. Transparency : Glass on, Reflection : Ray trace off
        10. Casts shadows onto invisible surfaces
        illum 2
    */

    struct Illumination
    {
        int m_illumination;

        Illumination(int illumination) :
            m_illumination(illumination) {}
    };

    /*Texture maps[edit]
        Textured materials use the same properties as above, and additionally define texture maps.Below is an example of a common material file.See the full wavefront file format reference for more details.
        newmtl Textured
        Ka 1.000 1.000 1.000
        Kd 1.000 1.000 1.000
        Ks 0.000 0.000 0.000
        d 1.0
        illum 2
        map_Ka lemur.tga           # the ambient texture map
    */

    struct AmbientTextureMap
    {
        QString m_ambientTextureMap;

        AmbientTextureMap(QString ambientTextureMap) :
            m_ambientTextureMap(ambientTextureMap) {}
    };

    /*map_Kd lemur.tga           # the diffuse texture map(most of the time, it will
        # be the same as the ambient texture map)
    */

    struct DiffuseTextureMap
    {
        QString m_diffuseTextureMap;

        DiffuseTextureMap(QString diffuseTextureMap) :
            m_diffuseTextureMap(diffuseTextureMap) {}
    };

    //map_Ks lemur.tga           # specular color texture map

    struct SpecularColorTextureMap
    {
        QString m_specularColorTextureMap;

        SpecularColorTextureMap(QString specularColorTextureMap) :
            m_specularColorTextureMap(specularColorTextureMap) {}
    };

    //    map_Ns lemur_spec.tga      # specular highlight map

    struct SpecularHighlightMap
    {
        QString m_specularHighlightMap;

        SpecularHighlightMap(QString specularHighlightMap) :
            m_specularHighlightMap(specularHighlightMap) {}
    };

    //    map_d lemur_alpha.tga      # the alpha texture map

    struct AlphaTextureMap
    {
        QString m_alphaTextureMap;

        AlphaTextureMap(QString alphaTextureMap) :
            m_alphaTextureMap(alphaTextureMap) {}
    };

    /*    map_bump lemur_bump.tga    # some implementations use 'map_bump' instead of 'bump' below
          bump lemur_bump.tga        # bump map(which by default uses luminance channel of the image)
    */

    struct BumpMap
    {
        QString m_bumpMap;

        BumpMap(QString bumpMap) :
            m_bumpMap(bumpMap) {}
    };

    //    disp lemur_disp.tga        # displacement map

    struct DisplacementMap
    {
        QString m_displacementMap;

        DisplacementMap(QString displacementMap) :
            m_displacementMap(displacementMap) {}
    };

    //    decal lemur_stencil.tga    # stencil decal texture(defaults to 'matte' channel of the image)

    struct StencilMap
    {
        QString m_stencilMap;

        StencilMap(QString stencilMap) :
            m_stencilMap(stencilMap) {}
    };


/*    File format[edit]


        Texture map statements may also have option parameters(see full spec).
        map_Ka - o 1 1 1 ambient.tga            # texture origin(1, 1, 1)
        refl - type sphere clouds.tga           # spherical reflection map
        Texture options[edit]
        - blendu on | off                       # set horizontal texture blending(default on)
        - blendv on | off                       # set vertical texture blending(default on)
        - boost float_value                     # boost mip - map sharpness
        - mm base_value gain_value              # modify texture map values(default 0 1)
        #     base_value = brightness, gain_value = contrast
        - o u[v[w]]                           # Origin offset(default 0 0 0)
        - s u[v[w]]                           # Scale(default 1 1 1)
        - t u[v[w]]                           # Turbulence(default 0 0 0)
        - texres resolution                     # texture resolution to create
        - clamp on | off                        # only render texels in the clamped 0 - 1 range(default off)
        #   When unclamped, textures are repeated across a surface,
        #   when clamped, only texels which fall within the 0 - 1
        #   range are rendered.
        - bm mult_value                         # bump multiplier(for bump maps only)

        - imfchan r | g | b | m | l | z         # specifies which channel of the file is used to
        # create a scalar or bump texture.r:red, g : green,
        # b : blue, m : matte, l : luminance, z : z - depth..
# (the default for bump is 'l' and for decal is 'm')
        bump - imfchan r bumpmap.tga            # says to use the red channel of bumpmap.tga as the bumpmap
        For reflection maps...
        - type sphere                           # specifies a sphere for a "refl" reflection map
        - type cube_top | cube_bottom | # when using a cube map, the texture file for each
        cube_front | cube_back | # side of the cube is specified separately//        cube_left | cube_right
        Vendor specific alterations[edit]
        Because of the ease in parsing the files, and the unofficial spreading of the file format, files may contain vendor specific alterations.
        According to the spec, options are supposed to precede the texture filename.However, at least one vendor generates files with options at the end.
        bump texbump.tga - bm 0.2               # bump multiplier of 0.2

        Physically - based Rendering[edit]
        The creators of the online 3D editing and modeling tool, Clara.io, proposed extending the MTL format to contain the following parameters to represent the physically - based rendering parameters : [4]
        Pr / map_Pr     # roughness
        Pm / map_Pm     # metallic
        Ps / map_Ps     # sheen
        Pc            # clearcoat thickness
        Pcr           # clearcoat roughness
        Ke / map_Ke     # emissive
        aniso         # anisotropy
        anisor        # anisotropy rotation
        norm          # normal map, same format as "bump" parameter
*/
}
