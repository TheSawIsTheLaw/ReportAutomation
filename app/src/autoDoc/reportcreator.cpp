#include "reportcreator.hpp"

ReportCreator::ReportCreator(
    QString analyzeFile_, QString savePath_, QString configPath_, int row_)
{
    analyzeFile = analyzeFile_;
    savePath = savePath_;
    configPath = configPath_;
    row = row_;
}

int ReportCreator::startProc()
{
    QProcess *creatorProc = new QProcess();
    creatorProc->start("./reportCreator.exe",
                       QStringList() << analyzeFile << savePath << configPath << QString::number(row));
    creatorProc->waitForFinished();
    return creatorProc->exitCode();
}
