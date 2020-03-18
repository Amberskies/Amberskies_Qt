
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



UserData::UserData(QWidget *parent) : QTableWidget(parent)
{
    this->setRowCount(60);
    this->setColumnCount(10); 
}

void UserData::SaveData()
{
    
    qDebug("Save Started...");

    QFile data("Source/Data/BaseData.dat");
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
    qDebug("Saved file to Source/Data/BaseData file.");
}

void UserData::LoadData()
{
    qDebug("Load Started...");

    QFile data("Source/Data/BaseData.dat");
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
    qDebug("Loaded file from Source/Data/BaseData file.");
}

void UserData::RefreshData()
{
    qDebug("Refresh Started...");

    // Fatigue : read value at 4,1 : place in 4,3
    {
        QTableWidgetItem *cell = this->item(4, 1);
        QString value = cell->text();
        if (value != "") SetCell(value, 7, 3);
    }
    // Thrust Damage : read value to int at 4,1 : table result to 4,5
    {
        QTableWidgetItem *cell = this->item(4, 1);
        int strength = cell->text().toInt();
        QString thrust = "";

        if (strength == 9)   thrust = "1d-2";
        if (thrust != "") SetCell(thrust, 4, 5);
    }
    // Swing Damage
    {
        QTableWidgetItem *cell = this->item(4, 1);
        int strength = cell->text().toInt();
        QString swing = "";

        if (strength == 9)   swing = "1d-1";
        if (swing != "") SetCell(swing, 4, 7);
    }
    // Psi Points
    {
        QTableWidgetItem *cell = this->item(5, 1);
        QString value = cell->text();
        if (value != "") SetCell(value, 5, 3);
    }
    // Hits Taken
    SetCell("0", 7, 3);
    //Base Move : (health + Dex) / 4 = 4.5
    {
        float move = 0;
        QTableWidgetItem *cell1 = this->item(7, 1);
        float health = cell1->text().toFloat();
        QTableWidgetItem *cell2 = this->item(6, 1);
        float dexterity = cell2->text().toFloat();
        move = (health + dexterity) / 4;

        SetCell(QString::number(move), 7, 5);
    }
    // Encumberance
    SetCell("0", 8, 1);
    // Armour Defence
    SetCell("0", 8, 3);
    // Shield Defence
    SetCell("0", 8, 5);
    //Passive Defence
    SetCell("0", 8, 7);
    // Dodge
    {
        QTableWidgetItem *cell = this->item(7, 5);
        QString value = cell->text();
        if (value != "") SetCell(value, 9, 1);
    }
    // Parry
    SetCell("0", 9, 3);
    // Block
    SetCell("0", 9, 5);
    // Abilities
    SetCell("0", 10, 1);
    // Skills
    SetCell("0", 10, 3);
    // Combat Skills
    SetCell("0", 10, 5);
    // Psi Skills
    SetCell("0", 10, 7);
    // Equipment
    SetCell("0", 11, 1);
    // Cash
    SetCell("0", 11, 3);
    // Bank
    SetCell("0", 11, 5);
    // Storage
    SetCell("0", 11, 7);
    // Properties
    SetCell("0", 12, 1);

    qDebug("Refreshed.");       
}
/////////////////// Private /////////////

void UserData::SetCell(QString value, int row, int column)
{
    QTableWidgetItem *cellContents = new QTableWidgetItem();
    cellContents->setText(value);
    this->setItem(row, column, cellContents);
}
