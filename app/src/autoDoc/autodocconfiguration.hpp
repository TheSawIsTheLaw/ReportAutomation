#ifndef AUTODOCCONFIGURATION_HPP
#define AUTODOCCONFIGURATION_HPP

#include <QString>
#include <vector>

class AutoDocConfiguration
{
public:
    AutoDocConfiguration();

    QString savePath = "";
    QString readFilePath = "";
    QString startCell = "";

    std::vector<QString> vectorOfNeededHeaders;
};

#endif // AUTODOCCONFIGURATION_HPP
