#include "facade.hpp"

Facade::Facade() { configuration = new AutoDocConfiguration(); }

void Facade::setSavePathForConfiguration(QString path) { configuration->savePath = path; }

void Facade::setAnalyzeFile(QString filePath)
{
    if (std::filesystem::exists(filePath.toUtf8().toStdString()))
        return;
    qDebug("Exists");
    configuration->readFilePath = filePath;
    qDebug("Filepath: '%s'", filePath.toStdString().c_str());
}

int Facade::setConfigByFile(QString filePath)
{
    if (std::filesystem::exists(filePath.toUtf8().toStdString()))
        return -FILE_NOT_EXIST_ERR;

    return SUCCESS;
}

void Facade::initChoiceOfOrgs(QWidget *parent)
{
    OrganisationsChoiceWindow orgChoiceWin(configuration->readFilePath, parent);

    orgChoiceWin.setModal(true);
    orgChoiceWin.exec();
}
