#ifndef REPORTCREATOR_H
#define REPORTCREATOR_H

#include <QProcess>
#include <QString>

class ReportCreator
{
public:
    ReportCreator(QString analyzeFile_, QString savePath_, QString configPath_, int row_);
    int startProc();

private:
    QString analyzeFile;
    QString savePath;
    QString configPath;
    int row;
};

#endif // REPORTCREATOR_H
