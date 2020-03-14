#include <QOpenGLShaderProgram>
#include <QString>

namespace Shaders
{
    enum ShaderName
    {
        Simplified = 0,
        BasicColor
    };

    static QString shader[] =
    {
        "Simplified", // shader 0
        "BasicColor"
    };

    QOpenGLShaderProgram* CreateShader(ShaderName name)
    {
        QOpenGLShaderProgram* l_program = new QOpenGLShaderProgram();

        l_program->create();

        l_program->addShaderFromSourceFile(
                    QOpenGLShader::Vertex,
                    shader[name] + ".vsh"
        );

        l_program->addShaderFromSourceFile(
                    QOpenGLShader::Fragment,
                    shader[name] + ".fsh"
        );

        l_program->link();
        l_program->bind();

        return l_program;
    }
}
