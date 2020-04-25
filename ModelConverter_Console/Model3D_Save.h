
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
#pragma once

#include <iostream>

#include <QObject>
#include <QString>
#include <QIODevice>
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
    class SaveModel3D : public QObject
    {
        Q_OBJECT

    public:
        SaveModel3D(QObject* parent = nullptr);

        void  ArrayDump(
            QTextStream &buffer,
            float* data,
            int numData,
            int tupleSize
        );

        void SaveConvertedData(
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
            int numTexCoords
        );

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
    };
}
