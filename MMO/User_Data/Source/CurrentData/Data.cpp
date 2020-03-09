
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

        QFile data("Source/CurrentData/BaseData.dat");
        if (data.open(QFile::ReadOnly))
        {
            qDebug("File Open");

            QTextStream in(&data);
            QString str = in.readAll();
            QStringList rows = str.split('\n');
    
            int numRows = rows.count();
            int numColumns = rows.first().count('\t') + 1;
            //setRowCount(numRows);
            //setColumnCount(numColumns);

            qDebug() << "rows = " << numRows;
            qDebug() << "columns = " << numColumns;

            for (int i = 0; i < numRows; ++i) 
            {
                QStringList columns = rows[i].split('\t');
                for (int j = 0; j < numColumns; ++j) 
                {                   
                    if (columns[j] != "")
                    {
                        //QTableWidgetItem *cell = this->item(i, j);
                        //cell->setText(columns[j]);

                        QTableWidgetItem *cellContents = new QTableWidgetItem();
                        cellContents->setText(columns[j]);
                        this->setItem(i,j,cellContents);

                        qDebug() << j << " : " << columns[j];
                    }                       
                }
            }
        }
        data.close();
        qDebug("Loaded file from Source/CurrentData/BaseData file.");
    }

    void UserData::RefreshData()
    {
        qDebug("Refresh Started...");

        // Fatigue : read value at 4,1 : place in 4,3
        {
            QTableWidgetItem *cell = this->item(4, 1);
            if (cell != nullptr)
            {
                QTableWidgetItem *cellContents = new QTableWidgetItem();
                *cellContents = *cell;
                this->setItem(4,3,cellContents);
            }
        }
        // Thrust Damage : read value to int at 4,1 : table result to 4,5
        {
            QTableWidgetItem *cell = this->item(4, 1);
            int strength = cell->text().toInt();
            QString thrust = "";

            if (strength == 9)   thrust = "1d-2";
            if (thrust != "")
            {
                QTableWidgetItem *cellContents = new QTableWidgetItem();
                cellContents->setText(thrust);
                this->setItem(4,5,cellContents);
            }
        }

        // Swing Damage
                {
            QTableWidgetItem *cell = this->item(4, 1);
            int strength = cell->text().toInt();
            QString swing = "";

            if (strength == 9)   swing = "1d-1";
            if (swing != "")
            {
                QTableWidgetItem *cellContents = new QTableWidgetItem();
                cellContents->setText(swing);
                this->setItem(4,7,cellContents);
            }
        }


        // Psi Points
        {
            QTableWidgetItem *cell = this->item(5, 1);
            if (cell != nullptr)
            {
                QTableWidgetItem *cellContents = new QTableWidgetItem();
                *cellContents = *cell;
                this->setItem(5,3,cellContents);
            }
        }


        // Hits Taken
        {
            QString hitsTaken = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(hitsTaken);
            this->setItem(7,3,cellContents);
        }

        //Base Move : (health + Dex) / 4 = 4.5
        {
            float move = 0;
            QTableWidgetItem *cell1 = this->item(7, 1);
            float health = cell1->text().toFloat();
            QTableWidgetItem *cell2 = this->item(6, 1);
            float dexterity = cell2->text().toFloat();

            move = (health + dexterity) / 4;
            QString baseMove = QString::number(move);

            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(baseMove);
            this->setItem(7,5,cellContents);

        }

        // Encumberance
        {
            QString encumberance = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(encumberance);
            this->setItem(8,1,cellContents);
        }


        // Armour Defence
        {
            QString ad = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(ad);
            this->setItem(8,3,cellContents);
        }


        // Shield Defence
        {
            QString sd = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(sd);
            this->setItem(8,5,cellContents);
        }


        //Passive Defence
        {
            QString pd = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(pd);
            this->setItem(8,7,cellContents);
        }

        // Dodge
        {
            QTableWidgetItem *cell = this->item(7, 5);
            if (cell != nullptr)
            {
                QTableWidgetItem *cellContents = new QTableWidgetItem();
                *cellContents = *cell;
                this->setItem(9,1,cellContents);
            }
        }

        // Parry
        {
            QString parry = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(parry);
            this->setItem(9,3,cellContents);
        }

        // Block
        {
            QString block = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(block);
            this->setItem(9,5,cellContents);
        }

        // Abilities
        {
            QString abilities = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(abilities);
            this->setItem(10,1,cellContents);
        }

        // Skills
        {
            QString skills = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(skills);
            this->setItem(10,3,cellContents);
        }

        // Combat Skills
        {
            QString combatSkills = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(combatSkills);
            this->setItem(10,5,cellContents);
        }

        // Psi Skills
        {
            QString psi = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(psi);
            this->setItem(10,7,cellContents);
        }

        // Equipment
        {
            QString equipment = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(equipment);
            this->setItem(11,1,cellContents);
        }

        // Cash
        {
            QString cash = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(cash);
            this->setItem(11,3,cellContents);
        }

        // Bank
        {
            QString bank = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(bank);
            this->setItem(11,5,cellContents);
        }

        // Storage
        {
            QString storage = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(storage);
            this->setItem(11,7,cellContents);
        }

        // Properties
        {
            QString properties = "0";
            QTableWidgetItem *cellContents = new QTableWidgetItem();
            cellContents->setText(properties);
            this->setItem(12,1,cellContents);
        }

        qDebug("Refreshed.");
    }
}
