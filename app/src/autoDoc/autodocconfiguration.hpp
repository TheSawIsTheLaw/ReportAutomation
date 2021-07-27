#ifndef AUTODOCCONFIGURATION_HPP
#define AUTODOCCONFIGURATION_HPP

#include "constants.hpp"
#include <QString>
#include <vector>

/*! \class AutoDocConfiguration
    \brief Class which contains needed in this place information

    Contains from config path to save generated report, path to analyze excel table,
   coordinates of start cell in excel style and path to configuration file.
 */
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
};

#endif // AUTODOCCONFIGURATION_HPP
