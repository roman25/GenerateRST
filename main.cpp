#include <QtCore/QCoreApplication>
#include <QMap>
#include <QString>
#include <QRandomGenerator>
#include <QDebug>
#include <QFile>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString fileName = QString(argv[1]);

    //QString fileName = "test.rst";
    QString currDir = QDir::currentPath();
    QString filePath = currDir + "/" + fileName;


    QMap <int, int> map; // <Error code, Count>
    QFile file(filePath);

    /*
        Erase       CH10  chip0
        Erase       CH1 chip4, CH3 chip0
        Program     CH15  chip0 & chip4
        Program     CH14  chip4
        Erase       CH7   chip0
    */

    QStringList errors = {
    "Error at Line23 Repeat-44-Line24: Erase Multichip Fail CH10 (Status CH1:E0 E0,CH2:E0 E0,CH3:E0 E0,CH4:E0 E0,CH5:E0 E0,CH6:E0 E0,CH7:E0 E0,CH8:E0 E0,CH9:E0 E0,CH10:E1 E0,CH11:E0 E0,CH12:E0 E0,CH13:E0 E0,CH14:E0 E0,CH15:E0 E0)",
    "Error at Line23 Repeat-2031-Line24: Erase Multichip Fail CH1 (Status CH1:E0 E1,CH2:E0 E0,CH3:E1 E0,CH4:E0 E0,CH5:E0 E0,CH6:E0 E0,CH7:E0 E0,CH8:E0 E0,CH9:E0 E0,CH10:E0 E0,CH11:E0 E0,CH12:E0 E0,CH13:E0 E0,CH14:E0 E0,CH15:E0 E0)",
    "Error at Line29 Repeat-2924-Line30: Block Program Multichip Fail CH15 (Status CH1:E0 E0,CH2:E0 E0,CH3:E0 E0,CH4:E0 E0,CH5:E0 E0,CH6:E0 E0,CH7:E0 E0,CH8:E0 E0,CH9:E0 E0,CH10:E0 E0,CH11:E0 E0,CH12:E0 E0,CH13:E0 E0,CH14:E0 E0,CH15:E1 E1)",
    "Error at Line23 Repeat-2385-Line24: Block Program Multichip Fail CH14 (Status CH1:E0 E0,CH2:E0 E0,CH3:E0 E0,CH4:E0 E0,CH5:E0 E0,CH6:E0 E0,CH7:E0 E0,CH8:E0 E0,CH9:E0 E0,CH10:E0 E0,CH11:E0 E0,CH12:E0 E0,CH13:E0 E0,CH14:E0 E1,CH15:E0 E0)",
    "Error at Line23 Repeat-2695-Line24: Erase Multichip Fail CH7 (Status CH1:E0 E0,CH2:E0 E0,CH3:E0 E0,CH4:E0 E0,CH5:E0 E0,CH6:E0 E0,CH7:E1 E0,CH8:E0 E0,CH9:E0 E0,CH10:E0 E0,CH11:E0 E0,CH12:E0 E0,CH13:E0 E0,CH14:E0 E0,CH15:E0 E0)" };

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
        stream << "Channel : CH1 CH2 CH3 CH4 CH5 CH6 CH7 CH8 CH9 CH10 CH11 CH12 CH13 CH14 CH15\r\n";
        stream << "Enable(Erase Program Read Dump Compare ErrorCount) : True True True True True True\r\n";
        stream << "Terminate with NAND Fail : False\r\n";
        stream << "Save Error Information to Result File : True\r\n";
        stream << "\r\n";
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


        int iterations = QRandomGenerator::global()->bounded(10);
        if (iterations == 0)
        {
            iterations = 3;
        }

        for (int i = 0; i < iterations; i++)
        {
            int errorType = QRandomGenerator::global()->bounded(errors.size() - 1);
            QString error = errors[errorType];

            int count = QRandomGenerator::global()->bounded(100);

            for (int j = 0; j < count; j++)
            {
                stream << error << "\n";
            }

            if (!(map.count(errorType) > 0))
            {
                map[errorType] = count;
            }
            else
            {
                map[errorType] += count;
            }
        }
    }

    foreach(int key, map.keys())
    {
        if (key == 0)
            qInfo() << "Count of Erase CH10 chip0: " << map[key];

        else if (key == 1)
            qInfo() << "Count of Erase CH1 chip4 and CH3 chip0: " << map[key];

        else if (key == 2)
            qInfo() << "Count of Program CH15 chip0 & chip4: " << map[key];

        else if (key == 3)
            qInfo() << "Count of Program CH14 chip4: " << map[key];

        else if (key == 3)
            qInfo() << "Count of Erase CH7 chip0: " << map[key];

        // Close after writting
 


    }

    file.close();
}
  