
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


#include <QTableWidget>
#include <QString>
#include <QFile>
#include <QTextStream>

namespace AmberData
{
    class UserData : public QTableWidget
    {
        QString cellValues[50][10] = {0};

        public:
            UserData(QWidget *parent = nullptr);
            ~UserData();

            void SaveData();
            void LoadData();
            void RefreshData();
    };
}

/**
 * 
 * Character Name
 * Player Name
 * 
 * Charaters Title
 * 
 * Ambernet Address : build your own 3D homepage
 * 
 * ********************************
 * Physical Strength    * Physical Attack Damage
 * Mental Strength      * Magic Points              * Mental Fatigue
 * Physical Dexterity   * To Hit chance  
 * Physical Health      * Hit Points
 * 
 * Encumberance Limits
 * Movement Speed
 * 
 * **********************************
 * 
 * Abilities (Both +ve and -ve)
 * 
 * **********************************
 * 
 * Skills :
 * Research Tech Level
 * 
 * **********************************
 * 
 * Combat Skills :
 * Hand To Hand
 * 
 * **********************************
 * 
 * Psion / Magic :
 * 
 * **********************************
 * Equipment List
 * Equipment in use     * Resists ( ie physical armor)
 * Cash
 * 
 * **********************************
 *  
 * Bank or storage should be held seperate.
 * properties etc held seperate
 * 
 * 
 **/ 