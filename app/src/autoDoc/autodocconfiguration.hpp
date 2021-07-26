#ifndef AUTODOCCONFIGURATION_HPP
#define AUTODOCCONFIGURATION_HPP

#include "constants.hpp"
#include <QString>
#include <vector>

class AutoDocConfiguration
{
public:
    AutoDocConfiguration();
    AutoDocConfiguration(QString savePath_, QString readFilePath_, QString startCell_,
        QString configPath_);

    QString savePath = "";
    QString readFilePath = "";
    QString startCell = "";
    QString configPath = PATH_TO_CONF;

    std::vector<QString> vectorOfNeededHeaders;
};

#endif // AUTODOCCONFIGURATION_HPP
