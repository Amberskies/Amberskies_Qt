
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Apr 21st
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
#pragma once

#include <iostream>

#include <QString>
#include <QFile>
#include <QTextStream>


namespace Dev
{

    // All of the data that we have Read into our Arrays can now be
    // stored out to Hard Drive

    // decide which arrays to store and in which order.
    // NB we also have a couple of variables ie bool hasTexture
    // these also need to be stored.

    // possible methods
    
    // diffrent array types uint int float QString
    // num Indices tells us how many items of data we have.

    static inline void  ArrayDump(float* address, int size)
    {

    }

    static inline void SaveConvertedData(
        QString saveFilename,
        bool hasTexture,
        QString textureFilename,
        int numIndices,
        bool hasNormals,
        float* positions,
        int numPositions,
        float* normals,
        int numNormals,
        float* colors,
        int numColors,
        float* texCoords,
        int numTexCoords)
    {
        system("dir");
        // open a file to write out to
        QFile data("/Resources/AmberObjects/" + saveFilename + ".amb");
        if (data.open(QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream out(&data);
            
            // write data to file
            out << "# " << saveFilename << "\n";
            out << "#  .obj convertor file for Amberskies 3D";

            // close file
            out.flush();
            data.close();

            std::cout << "\n\n File Saved to : " << 
                "/Resources/AmberObjects/" + saveFilename.toStdString() + ".amb" <<
                std::endl;
        }
        else
        {
            std::cout << "\n\n [ERROR] File did NOT Save !.\n\n";
        }
    }

    // data on disk reads :

    // # comment
    // hasTexture 0 = false 1 = true
    // textureFileName = "0" or "Name.png"

    // no ArrayDump for indices as we do not try to compress our data
    // ie serach for duplicated index data.
    // numIndices = int
    // hasNormals 0 = false 1 = true

    // ArrayDump float positions 3 
    // ArrayDump float normals 3 (not in use)
    // ArrayDump float colors 3 (RGB)
    // ArrayDump float texture coords 2











}