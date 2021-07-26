#include "autodocconfiguration.hpp"

AutoDocConfiguration::AutoDocConfiguration() {}

AutoDocConfiguration::AutoDocConfiguration(
    QString savePath_, QString readFilePath_, QString startCell_, QString configPath_)
{
    savePath = savePath_;
    readFilePath = readFilePath_;
    startCell = startCell_;
    configPath = configPath_;
}
