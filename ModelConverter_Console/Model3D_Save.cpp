
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Apr 23rd
 *
 *      Amber3D 3D Model Converter - Qt C++
 *
 * Contact email  : amberskies@virginmail.com
 * Website        : www.amberskies.org.uk
 * Twitch         : FrazorBladezSharp
 * Youtube        : Amberskies
 * Github         : https://github.com/Amberskies
 *
 * All code is free to use as you please
 * Please be aware of the Open Source Licence
 * given by Qt    : doc.qt.io/qt-5/opensourcelicence.html
 *
 * ---------------------------------------------------*/
#include "Model3D_Save.h"

namespace Dev
{
    SaveModel3D::SaveModel3D(QObject* parent) : QObject(parent)
    {
        // Empty
    }

    void SaveModel3D::ArrayDump(
        QTextStream &buffer,
        float* data, 
        int numData,
        int tupleSize)
    {
        int count = 0;
        buffer << "# Array Start :\n";
        while (count < numData)
        {
            for (int i = 0; i < tupleSize; i++)
            {
                buffer << data[count] << " ";
                count++;
            }

            buffer << "\n";
        }
        buffer << "# Array End :\n";
    }

    void SaveModel3D::SaveConvertedData(QString saveFilename, bool hasTexture, 
        QString textureFilename, int numIndices, bool hasNormals, 
        float* positions, int numPositions, 
        float* normals, int numNormals, 
        float* colors, int numColors, 
        float* texCoords, int numTexCoords)
    {
        std::cout << "\nSave attempt to : " <<
            "Resources/AmberObjects/" + saveFilename.toStdString() + ".amb" <<
            std::endl;

        // open a file to write out to
        QFile data("Resources/AmberObjects/" + saveFilename + ".amb");
        
        
        if (!data.exists())
        {
            std::cout << "File does not exist.\n";
            data.open(QFile::NewOnly | QFile::Text);
        }
        else
        {
            data.open(QFile::WriteOnly | QFile::Text);
        }

        if (data.isOpen())
        {
            QTextStream out(&data);

            // write data to file
            out << "\n";
            out << "# " << saveFilename << "\n";
            out << "#  .obj convertor file for Amberskies 3D \n";

            out << "# Data Start :\n";
            out << "hasTexture: " << hasTexture << "\n";
            out << "textureFilename: " << textureFilename << "\n";
            out << "numIndices: " << numIndices << "\n";
            out << "hasNormals: " << hasNormals << "\n";

            ArrayDump(
                out,
                positions,
                numPositions,
                3
            );

            if (hasNormals)
            {
                ArrayDump(
                    out,
                    normals,
                    numNormals,
                    3
                );
            }

            if (hasTexture)
            {
                ArrayDump(
                    out,
                    texCoords,
                    numTexCoords,
                    2
                );
            }
            else
            {
                ArrayDump(
                    out,
                    colors,
                    numColors,
                    3
                );
            }

            out << "# Data End :\n";

            // close file
            out.flush();
            data.close();

            std::cout << "File Saved to : " <<
                "Resources/AmberObjects/" + saveFilename.toStdString() + ".amb" <<
                std::endl;
        }
        else
        {
            std::cout << "[ERROR] File did NOT Save !.\n\n";
        }
    }
}
