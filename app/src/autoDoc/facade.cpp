#include "facade.hpp"

Facade::Facade() { configuration = new AutoDocConfiguration(); }

void Facade::setSavePathForConfiguration(QString path) { configuration->savePath = path; }

void Facade::setAnalyzeFile(QString filePath)
{
    if (std::filesystem::exists(filePath.toUtf8().toStdString()))
        return;
    configuration->readFilePath = filePath;
}

int Facade::setConfigByFile(QString filePath)
{
    if (std::filesystem::exists(filePath.toUtf8().toStdString()))
        return -FILE_NOT_EXIST_ERR;

    return SUCCESS;
}
