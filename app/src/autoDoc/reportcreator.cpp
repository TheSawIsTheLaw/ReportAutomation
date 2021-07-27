#include "reportcreator.hpp"
#include <QDebug>
#include <qtextcodec.h>

/**
 * \fn ReportCreator::ReportCreator(
 * QString analyzeFile_, QString savePath_, QString configPath_, int row_)
 * \brief Init of ReportCreator class
 *
 *  Inits ReportCreator using passed values
 *
 *  \return Inited ReportCreator class
 */
ReportCreator::ReportCreator(
    QString analyzeFile_, QString savePath_, QString configPath_, int row_)
: analyzeFile(analyzeFile_), savePath(savePath_), configPath(configPath_), row(row_)
{
}

/**
 * \fn int ReportCreator::startProc()
 * \brief Starts python script to generate one report
 *
 *  Prepares arguments and sets a program to a QProcess.
 *  Then executes it.
 *
 *  \return Exit code of executed script
 */
int ReportCreator::startProc()
{
    QStringList arguments = QStringList() << analyzeFile.toStdString().c_str() << savePath
                                          << configPath << QString::number(row);
    //    qDebug() << gavno;

    QProcess *creatorProc = new QProcess();
    creatorProc->setArguments(arguments);
    creatorProc->setProgram("reportGenerator.exe");

    creatorProc->start();
    creatorProc->waitForFinished();

    //    qDebug() << creatorProc->readAllStandardError().data();
    //    qDebug() <<
    //    QTextCodec::codecForName("cp1251")->toUnicode(creatorProc->readAll().data());
    //    qDebug() << creatorProc->exitCode();
    return creatorProc->exitCode();
}
