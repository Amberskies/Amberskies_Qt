
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


#include "UserData.h"
#include <QDebug>



UserData::UserData(QWidget *parent) : DataProgram(parent)
{
    this->LoadData("BaseData");
}

void UserData::RefreshData()
{
    qDebug("Refresh Started...");

    // Fatigue : read value at 4,1 : place in 4,3
    QString fatigue = GetCell(4, 1);
    if (fatigue != "") SetCell(fatigue, 7, 3);
    
    // Thrust Damage : read value to int at 4,1 : table result to 4,5
    int strength = GetCell(4,1).toInt();
    QString thrust = "";
    if (strength == 9)   thrust = "1d-2";   // this is a table
    if (thrust != "") SetCell(thrust, 4, 5);
    
    // Swing Damage
    QString swing = "";
    if (strength == 9)   swing = "1d-1";    // this is a table
    if (swing != "") SetCell(swing, 4, 7);
    
    // Psi Points
    QString psi = GetCell(5, 1);
    if (psi != "") SetCell(psi, 5, 3);
    
    //Base Move : (health + Dex) / 4 = 4.5
    float move = 0;
    float health = GetCell(7, 1).toFloat();
    float dexterity = GetCell(6, 1).toFloat();
    move = (health + dexterity) / 4;
    SetCell(QString::number(move), 7, 5);
    
    // Dodge
    QString dodge = GetCell(7, 5);
    if (dodge != "") SetCell(dodge, 9, 1);

    qDebug("Refreshed.");       
}


