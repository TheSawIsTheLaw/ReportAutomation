#include "reportcreator.hpp"
#include <QDebug>
#include <qtextcodec.h>

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
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QStringList gavno = QStringList() << analyzeFile.toStdString().c_str() << savePath << configPath << QString::number(row);
    qDebug() << gavno;
    creatorProc->setArguments(gavno);
    creatorProc->setProgram("C:/Users/dobri/Desktop/ReportAutomation/app/src/python/dist/reportGenerator.exe");
    creatorProc->start();
    creatorProc->waitForFinished();
//    qDebug() << creatorProc->readAllStandardError().data();
//    qDebug() << QTextCodec::codecForName("cp1251")->toUnicode(creatorProc->readAll().data());
//    qDebug() << creatorProc->exitCode();
    return creatorProc->exitCode();
}
