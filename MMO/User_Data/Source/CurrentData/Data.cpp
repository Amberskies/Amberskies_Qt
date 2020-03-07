
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 3rd
 *
 *      Amber 3D - Qt C++ Version Research 0.1
 *
 * Contact email  : amberskies@virginmail.com
 * Website        : www.amberskies.org.uk
 * Twitch         : FrazorBladezSharp
 * Youtube        : Amberskies
 *
 * All code is free to use as you please
 * Please be aware of the Open Source Licence
 * given by Qt    : doc.qt.io/qt-5/opensourcelicence.html
 *
 * ---------------------------------------------------*/


#include "Data.h"
#include <QDebug>
#include <iostream>

namespace AmberData
{
    UserData::UserData(QWidget *parent) : QTableWidget(parent)
    {
        this->setRowCount(50);
        this->setColumnCount(10); 
    }

    UserData::~UserData()
    {
        // Empty
    }

    void UserData::SaveData()
    {
    
        qDebug("Save Started...");

        QFile data("Source/CurrentData/BaseData.dat");
        if (data.open(QFile::WriteOnly | QFile::Truncate))  
        {
           QTextStream out(&data);
            for (int i = 0; i < this->rowCount(); ++i) 
            {
                if (i > 0)  out << '\n';
                for (int j = 0; j < this->columnCount(); ++j) 
                {
                    if (j > 0)  out << '\t';
                    QTableWidgetItem *cell = this->item(i, j);
                    if (cell != nullptr)
                    {
                        qDebug() << i << "," << j << " " << cell->text();
                        out << cell->text();
                    }
                }
            }
            out.flush();
        }
        
        data.close();
        qDebug("Saved file to Source/CurrentData/BaseData file.");
    }

    void UserData::LoadData()
    {
        qDebug("Load Started...");

        qDebug("Load file from Source/CurrentData/BaseData file.");
    }

    void UserData::RefreshData()
    {
        qDebug("Refresh Started...");

        qDebug("Refreshed.");
    }
}

/*
***********************************************************

QTextStream out(&file);
for (int i = 0; i < rowCount(); ++i) {
    if (i > 0)
    out << '\n';
    for (int j = 0; j < columnCount(); ++j) {
       if (j > 0)
          out << '\t';
       QTableWidgetItem *cell = item(i, j);
       out << cell->text();
    }
}

*********************************************************

QTextStream in(&file);
QString str = in.readAll();
QStringList rows = str.split('\n');
 
int numRows = rows.count();
int numColumns = rows.first().count('\t') + 1;
setRowCount(numRows);
setColumnCount(numColumns);
 
for (int i = 0; i < numRows; ++i) {
    QStringList columns = rows[i].split('\t');
    for (int j = 0; j < numColumns; ++j) {
       QTableWidgetItem *cell = item(i, j);
       cell->setText(columns[j]);
    }
}

*******************************************************
*/