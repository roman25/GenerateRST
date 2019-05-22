#include <QtCore/QCoreApplication>
#include <QMap>
#include <QString>
#include <QRandomGenerator>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap <QString, int> map;
    
    // CH10 chip 0
    int value10= QRandomGenerator::global()->bounded(100);
    qInfo() << "CH10 chip 0: " << value10;    
    map.insert("Error at Line23 Repeat-44-Line24: Erase Multichip Fail CH10 (Status CH0:E0 E0,CH1:E0 E0,CH2:E0 E0,CH3:E0 E0,CH4:E0 E0,CH5:E0 E0,CH6:E0 E0,CH7:E0 E0,CH8:E0 E0,CH9:E0 E0,CH10:E1 E0,CH11:E0 E0,CH12:E0 E0,CH13:E0 E0,CH14:E0 E0,CH15:E0 E0)", value10);
    
    // CH1 chip 4
    int value1 = QRandomGenerator::global()->bounded(100);
    qInfo() << "CH1 chip 4: " << value1;
    map.insert("Error at Line23 Repeat-2031-Line24: Erase Multichip Fail CH1 (Status CH0:E0 E0,CH1:E0 E1,CH2:E0 E0,CH3:E0 E0,CH4:E0 E0,CH5:E0 E0,CH6:E0 E0,CH7:E0 E0,CH8:E0 E0,CH9:E0 E0,CH10:E0 E0,CH11:E0 E0,CH12:E0 E0,CH13:E0 E0,CH14:E0 E0,CH15:E0 E0)", value1);

    // CH15 chip 0 & 4
    int value15 = QRandomGenerator::global()->bounded(100);
    qInfo() << "CH15 chip 0 & 4: " << value15;
    map.insert("Error at Line29 Repeat-2924-Line30: Block Program Multichip Fail CH15 (Status CH0:E0 E0,CH1:E0 E0,CH2:E0 E0,CH3:E0 E0,CH4:E0 E0,CH5:E0 E0,CH6:E0 E0,CH7:E0 E0,CH8:E0 E0,CH9:E0 E0,CH10:E0 E0,CH11:E0 E0,CH12:E0 E0,CH13:E0 E0,CH14:E0 E0,CH15:E1 E1)", value15);

    // CH9 chip 0
    int value9 = QRandomGenerator::global()->bounded(100);
    qInfo() << "CH9 chip 0: " << value9;
    map.insert("Error at Line23 Repeat-1482-Line24: Erase Multichip Fail CH9 (Status CH0:E0 E0,CH1:E0 E0,CH2:E0 E0,CH3:E0 E0,CH4:E0 E0,CH5:E0 E0,CH6:E0 E0,CH7:E0 E0,CH8:E0 E0,CH9:E1 E0,CH10:E0 E0,CH11:E0 E0,CH12:E0 E0,CH13:E0 E0,CH14:E0 E0,CH15:E0 E0)", value9);

    QString filePath = "G:\\test.rst";
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
        stream << "Lane : 2\r\n";
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
        stream << "Get Data (Line9) CH0 : 98 3C 98 B3 76 72 08 0E\r\n";
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

        foreach(QString str, map.keys())
        {
            for (int i = 0; i < map[str]; i++)
            {
                stream << str << "\r\n";
            }
        }
    }

    // Close after writting
    file.close();

    
}
