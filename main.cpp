#include <QtCore/QCoreApplication>
#include <QMap>
#include <QString>
#include <QRandomGenerator>
#include <QDebug>
#include <QFile>
#include <QDir>

QString generateErase();
QString generateProgram();

QMap <int, QList <int> > usedCH;
QMap <int, QList <int> > usedCHProg;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QString fileName = QString(argv[1]);

    QString fileName = "test.rst";
    QString currDir = QDir::currentPath();
    QString filePath = currDir + "/" + fileName;


    QMap <int, int> map; // <Error code, Count>
    QFile file(filePath);


    
    // Remove old report if it exists
    file.remove();

    // Write to CS from input
    if (file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);

        stream << "SigNAS3 Ver1.8\r\n";
        stream << "Script Execution Result\r\n";
        stream << "\r\n";
        stream << "Lane : 0\r\n";
        stream << "Channel : CH0 CH1 CH2 CH3 CH4 CH5 CH6 CH7 CH8 CH9 CH10 CH11 CH12 CH13 CH14 CH15\r\n";
        stream << "Enable(Erase Program Read Dump Compare ErrorCount) : True True True True True True\r\n";
        stream << "Terminate with NAND Fail : False\r\n";
        stream << "Save Error Information to Result File : True\r\n";
        stream << "\r\n";
        stream << "Get Data (Line6) CH0 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH1 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH2 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH3 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH4 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH5 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH6 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH7 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH8 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH9 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH10 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH11 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH12 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH13 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH14 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH15 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line6) CH0 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH1 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH2 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH3 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH4 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH5 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH6 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH7 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH8 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH9 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH10 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH11 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH12 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH13 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH14 : 98 3C 98 B3 76 72 08 0E\r\n";
        stream << "Get Data (Line9) CH15 : 98 3C 98 B3 76 72 08 0E\n\r\n";


        QString error = generateErase();
        int countError = QRandomGenerator::global()->bounded(1, 101);
        
        foreach(int key, usedCH.keys())
        {
            QList <int> values = usedCH[key];

            values[0] *= countError;
            values[1] *= countError;
               
            usedCH[key] = values;
        }
           
        qInfo() << "Erase";
        foreach(int key, usedCH.keys())
        {
            qInfo() << "CH" + QString::number(key) + ":" << usedCH[key];
        }

        for (int j = 0; j < countError; j++)
        {

            stream << error << "\n";
        }

        QString errorProg = generateProgram();
        int countErrorProg = QRandomGenerator::global()->bounded(1, 11);
        
        foreach(int key, usedCHProg.keys())
        {
            QList <int> values = usedCHProg[key];
            values[0] *= countErrorProg;
            values[1] *= countErrorProg;
            usedCHProg[key] = values;
        }

        qInfo() << "Program";
        foreach(int key, usedCHProg.keys())
        {
            qInfo() << "CH" + QString::number(key) + ":" << usedCHProg[key];
        }

        for (int j = 0; j < countErrorProg; j++)
        {
            stream << errorProg << "\n";
        }
        
    }

    file.close();
}
  
QString generateErase()
{
    QString finalStr = "";
    QString strOne = "Error at Line23 Repeat-2930-Line24: Erase Multichip Fail ";
    QString strTwo = " (Status ";
    QString ch = "";
    QStringList listChannels = { "CH0:E0 E0", "CH1:E0 E0", "CH2:E0 E0", "CH3:E0 E0", "CH4:E0 E0",
        "CH5:E0 E0", "CH6:E0 E0", "CH7:E0 E0", "CH8:E0 E0", "CH9:E0 E0",
        "CH10:E0 E0", "CH11:E0 E0", "CH12:E0 E0", "CH13:E0 E0", "CH14:E0 E0", "CH15:E0 E0" };

    int badChannels = QRandomGenerator::global()->bounded(0, listChannels.size());

    

    for (int i = 0; i <= badChannels; i++)
    {
        int badChNum = QRandomGenerator::global()->bounded(0, listChannels.size());

        if (usedCH.contains(badChNum))
            continue;



        int digit = 3;
        if (!(listChannels[badChNum][digit].isDigit()))
            digit = 2;

        strOne += listChannels[badChNum].left(digit + 1) + " ";

        int chipCount = QRandomGenerator::global()->bounded(1, 3);

        if (chipCount == 1)
        {
            int chip = QRandomGenerator::global()->bounded(0, 2);

            if (chip == 0)
            {
                listChannels[badChNum] = "CH" + QString::number(badChNum) + ":E1 E0";
                usedCH[badChNum] = { 1, 0 };
            }
            if (chip == 1)
            {
                listChannels[badChNum] = "CH" + QString::number(badChNum) + ":E0 E1";
                usedCH[badChNum] = { 0, 1 };
            }
        }

        if (chipCount == 2)
        {
            listChannels[badChNum] = "CH" + QString::number(badChNum) + ":E1 E1";
            usedCH[badChNum] = { 1, 1 };
        }
    }

    for (int i = 0; i < listChannels.size(); i++)
    {
        ch += listChannels[i] + ",";
    }

    ch.chop(1); // Remove last character

    finalStr += strOne + strTwo + ch + ")";
        
    return finalStr;
}

QString generateProgram()
{
    QString finalStr = "";
    QString strOne = "Error at Line23 Repeat-2930-Line24: Block Program Multichip Fail ";
    QString strTwo = " (Status ";
    QString ch = "";
    QStringList listChannels = { "CH0:E0 E0", "CH1:E0 E0", "CH2:E0 E0", "CH3:E0 E0", "CH4:E0 E0",
        "CH5:E0 E0", "CH6:E0 E0", "CH7:E0 E0", "CH8:E0 E0", "CH9:E0 E0",
        "CH10:E0 E0", "CH11:E0 E0", "CH12:E0 E0", "CH13:E0 E0", "CH14:E0 E0", "CH15:E0 E0" };

    int badChannels = QRandomGenerator::global()->bounded(0, listChannels.size());
    
    for (int i = 0; i <= badChannels; i++)
    {
        int badChNum = QRandomGenerator::global()->bounded(0, listChannels.size());

        if (usedCHProg.contains(badChNum))
            continue;



        int digit = 3;
        if (!(listChannels[badChNum][digit].isDigit()))
            digit = 2;

        strOne += listChannels[badChNum].left(digit + 1) + " ";

        int chipCount = QRandomGenerator::global()->bounded(1, 3);

        if (chipCount == 1)
        {
            int chip = QRandomGenerator::global()->bounded(0, 2);

            if (chip == 0)
            {
                listChannels[badChNum] = "CH" + QString::number(badChNum) + ":E1 E0";
                usedCHProg[badChNum] = { 1, 0 };
            }
            if (chip == 1)
            {
                listChannels[badChNum] = "CH" + QString::number(badChNum) + ":E0 E1";
                usedCHProg[badChNum] = { 0, 1 };
            }
        }

        if (chipCount == 2)
        {
            listChannels[badChNum] = "CH" + QString::number(badChNum) + ":E1 E1";
            usedCHProg[badChNum] = { 1, 1 };
        }
    }

    for (int i = 0; i < listChannels.size(); i++)
    {
        ch += listChannels[i] + ",";
    }

    ch.chop(1); // Remove last character

    finalStr += strOne + strTwo + ch + ")";
    
    return finalStr;
}