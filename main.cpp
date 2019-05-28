#include <QtCore/QCoreApplication>
#include <QMap>
#include <QString>
#include <QRandomGenerator>
#include <QDebug>
#include <QFile>
#include <QDir>

// Declare functions
QString generateErase();
QString generateProgram();

// Storage of errors
QMap <int, QList <int> > usedCHErase;
QMap <int, QList <int> > usedCHProg;

// Count of error types
int errorTypes = 3;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Output file name
    QString fileName = QString(argv[1]);
    //QString fileName = "test.rst";
    
    // Get current directory and set path to out file
    QString currDir = QDir::currentPath();
    QString filePath = currDir + "/" + fileName;   
    QFile file(filePath);

    // Remove old report if it exists
    file.remove();

    // Write to .rst from input
    if (file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);

        // Write service lines
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

        // Temporary storages for used channels
        QList <int> keyStorage;
        QList <int> keyStorageProg;
        
        // Max value of count of errors
        int generatorRange = 101;

        for (int iter = 0; iter < errorTypes; iter++)
        {
            // Generate errors line
            QString errorErase  = generateErase();
            QString errorProg   = generateProgram();
            
            // Generate error count
            int countErrorErase = QRandomGenerator::global()->bounded(1, generatorRange);
            int countErrorProg  = QRandomGenerator::global()->bounded(1, generatorRange);
            
            // Read every bad channel
            foreach(int key, usedCHErase.keys())
            {
                // if channel already was used than get new channel from the map
                if (keyStorage.contains(key))
                    continue;

                // Get count of errors per chip for current channel
                QList <int> values = usedCHErase[key];

                // Write count of errors
                // Chip0
                if (values[0] == 1000000)
                {
                    values[0] = countErrorErase;
                }                
                else if (values[0] > 0)
                {
                    values[0] += countErrorErase;
                }
                // Chip4
                if (values[1] == 1000000)
                {
                    values[1] = countErrorErase;
                }
                else if (values[1] > 0)
                {
                    values[1] += countErrorErase;
                }

                // Write data
                usedCHErase[key] = values;
                keyStorage << key;
            }

 
            foreach(int key, usedCHProg.keys())
            {
                // if channel already was used than get new channel from the map
                if (keyStorageProg.contains(key))
                    continue;

                // Get count of errors per chip for current channel
                QList <int> values = usedCHProg[key];

                // Write count of errors
                // Chip 0
                if (values[0] == 1000000)
                {
                    values[0] = countErrorProg;
                }
                else if (values[0] > 0)
                {
                    values[0] += countErrorProg;
                }
                // Chip 4
                if (values[1] == 1000000)
                {
                    values[1] = countErrorProg;
                }
                else if (values[1] > 0)
                {
                    values[1] += countErrorProg;
                }

                // Write data
                usedCHProg[key] = values;
                keyStorageProg << key;
            }

            // Write generated errors into .rst
            for (int j = 0; j < countErrorProg; j++)
            {
                stream << errorProg << "\n";
            }
            
            for (int j = 0; j < countErrorErase; j++)
            {
                stream << errorErase << "\n";
            }
        }
        
        // Out to console   
        qInfo() << "Erase";
        foreach(int key, usedCHErase.keys())
        {
            qInfo() << "CH" + QString::number(key) + ":" << usedCHErase[key];
        }

        qInfo() << "Program";
        foreach(int key, usedCHProg.keys())
        {
            qInfo() << "CH" + QString::number(key) + ":" << usedCHProg[key];
        }        
    }

    // Close .rst
    file.close();
}
  
QString generateErase()
{
    /* 
        Generates Erase errors
    */

    // Define lines for .rst
    QString finalStr    = "";
    QString strOne      = "Error at Line23 Repeat-2930-Line24: Erase Multichip Fail ";
    QString strTwo      = " (Status ";
    QString ch          = "";
    
    // Initial state of channels
    QStringList listChannels = { "CH0:E0 E0", "CH1:E0 E0", "CH2:E0 E0", "CH3:E0 E0", "CH4:E0 E0",
        "CH5:E0 E0", "CH6:E0 E0", "CH7:E0 E0", "CH8:E0 E0", "CH9:E0 E0",
        "CH10:E0 E0", "CH11:E0 E0", "CH12:E0 E0", "CH13:E0 E0", "CH14:E0 E0", "CH15:E0 E0" };

    // Set random count of bad channels
    int badChannels = QRandomGenerator::global()->bounded(0, listChannels.size());

    for (int i = 0; i <= badChannels; i++)
    {
        // Set ordinal number of bad channel
        int badChNum = QRandomGenerator::global()->bounded(0, listChannels.size());

        // Verify that no errors for current bad channel
        if (usedCHErase.contains(badChNum))
            continue;

        // Check channel is 1 or 2 digit value
        int digit = 3;
        if (!(listChannels[badChNum][digit].isDigit()))
            digit = 2;

        strOne += listChannels[badChNum].left(digit + 1) + " ";

        // Set count of bad chips
        int chipCount = QRandomGenerator::global()->bounded(1, 3);

        if (chipCount == 1)
        {
            // Set ordinal number of bad chip
            int chip = QRandomGenerator::global()->bounded(0, 2);

            if (chip == 0)
            {
                listChannels[badChNum] = "CH" + QString::number(badChNum) + ":E1 E0";

                // Write temporary value to highlight that chip is bad
                usedCHErase[badChNum] = { 1000000, 0 };
            }
            if (chip == 1)
            {

                listChannels[badChNum] = "CH" + QString::number(badChNum) + ":E0 E1";

                // Write temporary value to highlight that chip is bad
                usedCHErase[badChNum] = { 0, 1000000 };
            }
        }

        if (chipCount == 2)
        {
            listChannels[badChNum] = "CH" + QString::number(badChNum) + ":E1 E1";
            
            // Write temporary values to highlight that chips are bad
            usedCHErase[badChNum] = { 1000000, 1000000 };
        }
    }

    for (int i = 0; i < listChannels.size(); i++)
    {
        ch += listChannels[i] + ",";
    }

    ch.chop(1); // Remove last character

    // Concatenate final string
    finalStr += strOne + strTwo + ch + ")";
        
    return finalStr;
}

QString generateProgram()
{

    /*
        Generates Program errors
    */

    // Define lines for .rst
    QString finalStr    = "";
    QString strOne      = "Error at Line23 Repeat-2930-Line24: Block Program Multichip Fail ";
    QString strTwo      = " (Status ";
    QString ch          = "";

    // Initial state of channels
    QStringList listChannels = { "CH0:E0 E0", "CH1:E0 E0", "CH2:E0 E0", "CH3:E0 E0", "CH4:E0 E0",
        "CH5:E0 E0", "CH6:E0 E0", "CH7:E0 E0", "CH8:E0 E0", "CH9:E0 E0",
        "CH10:E0 E0", "CH11:E0 E0", "CH12:E0 E0", "CH13:E0 E0", "CH14:E0 E0", "CH15:E0 E0" };

    // Set random count of bad channels
    int badChannels = QRandomGenerator::global()->bounded(0, listChannels.size());
    
    for (int i = 0; i <= badChannels; i++)
    {
        // Set ordinal number of bad channel
        int badChNum = QRandomGenerator::global()->bounded(0, listChannels.size());

        // Verify that no errors for current bad channel
        if (usedCHProg.contains(badChNum))
            continue;

        // Check channel is 1 or 2 digit value
        int digit = 3;
        if (!(listChannels[badChNum][digit].isDigit()))
            digit = 2;

        strOne += listChannels[badChNum].left(digit + 1) + " ";

        // Set count of bad chips
        int chipCount = QRandomGenerator::global()->bounded(1, 3);

        if (chipCount == 1)
        {
            // Set ordinal number of bad chip
            int chip = QRandomGenerator::global()->bounded(0, 2);

            if (chip == 0)
            {
                listChannels[badChNum] = "CH" + QString::number(badChNum) + ":E1 E0";

                // Write temporary value to highlight that chip is bad
                usedCHProg[badChNum] = { 1000000, 0 };
            }
            if (chip == 1)
            {
                listChannels[badChNum] = "CH" + QString::number(badChNum) + ":E0 E1";

                // Write temporary value to highlight that chip is bad
                usedCHProg[badChNum] = { 0, 1000000 };
            }
        }

        if (chipCount == 2)
        {
            listChannels[badChNum] = "CH" + QString::number(badChNum) + ":E1 E1";

            // Write temporary values to highlight that chips are bad
            usedCHProg[badChNum] = { 1000000, 1000000 };
        }
    }

    for (int i = 0; i < listChannels.size(); i++)
    {
        ch += listChannels[i] + ",";
    }

    ch.chop(1); // Remove last character

    // Concatenate final string
    finalStr += strOne + strTwo + ch + ")";
    
    return finalStr;
}