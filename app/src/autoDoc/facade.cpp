#include "facade.hpp"

Facade::Facade()
{
    configuration = new AutoDocConfiguration();
}

void Facade::setSavePathForConfiguration(QString path)
{
    configuration->savePath = path;
}

void Facade::setAnalyzeFile(QString filePath)
{
    configuration->readFilePath = filePath;
}
