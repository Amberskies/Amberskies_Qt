
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


#include "DataProgram.h"
#include <QDebug>



DataProgram::DataProgram(QWidget *parent) : QTableWidget(parent)
{
    this->setRowCount(60);
    this->setColumnCount(10); 
}

void DataProgram::SaveData(QString fileName)
{
    
    qDebug("Save Started...");

    QFile data("Source/Data/" + fileName + ".dat");
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
                if (cell != nullptr) out << cell->text();
            }
        }
        out.flush();
    }       
    data.close();
    qDebug() << "Saved file to Source/Data/" + fileName + " file.";
}

void DataProgram::LoadData(QString fileName)
{
    qDebug("Load Started...");

    QFile data("Source/Data/" + fileName + ".dat");
    if (data.open(QFile::ReadOnly))
    {
        QTextStream in(&data);
        QString str = in.readAll();
        QStringList rows = str.split('\n');
            int numRows = rows.count();
        int numColumns = rows.first().count('\t') + 1;

        for (int i = 0; i < numRows; ++i) 
        {
            QStringList columns = rows[i].split('\t');
            for (int j = 0; j < numColumns; ++j) 
            {                   
                if (columns[j] != "")
                {
                    QTableWidgetItem *cellContents = new QTableWidgetItem();
                    cellContents->setText(columns[j]);
                    this->setItem(i,j,cellContents);
                }                    
            }
        }
    }
    data.close();
    qDebug() << "Loaded file from Source/Data/" + fileName + " file.";
}

////////////////////////////// Protected ///////////////////////////

void DataProgram::SetCell(QString value, int row, int column)
{
    QTableWidgetItem *cellContents = new QTableWidgetItem();
    cellContents->setText(value);
    this->setItem(row, column, cellContents);
}

QString DataProgram::GetCell(int row, int column)
{
    QString dataRetrived = "";

    QTableWidgetItem *cell = this->item(row, column);
    if (cell != nullptr) dataRetrived = cell->text();
    return dataRetrived;
}
