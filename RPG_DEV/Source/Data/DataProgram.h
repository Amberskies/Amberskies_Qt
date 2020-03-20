
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 20th
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
//#include <QStringList>
#include <QString>
#include <QFile>
#include <QTextStream>


class DataProgram : public QTableWidget
{
    QString m_fileName;

    public:
        DataProgram(QWidget *parent = nullptr);

        void SaveData(QString fileName);
        void LoadData(QString fileName);
    
    protected:
        virtual void RefreshData() {}
    
        void SetCell(QString value, int row, int column);
        QString GetCell(int row, int column);
};
 