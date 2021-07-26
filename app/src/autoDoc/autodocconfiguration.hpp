#ifndef AUTODOCCONFIGURATION_HPP
#define AUTODOCCONFIGURATION_HPP

#include <QString>
#include <vector>
#include "constants.hpp"

class AutoDocConfiguration
{
public:
    AutoDocConfiguration();

    QString savePath = "";
    QString readFilePath = "";
    QString startCell = "";
    QString configPath = PATH_TO_CONF;

    std::vector<QString> vectorOfNeededHeaders;
};

#endif // AUTODOCCONFIGURATION_HPP
