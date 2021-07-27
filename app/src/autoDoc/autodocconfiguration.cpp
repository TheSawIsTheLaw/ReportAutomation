#include "autodocconfiguration.hpp"

AutoDocConfiguration::AutoDocConfiguration() {}

/**
 * \fn AutoDocConfiguration::AutoDocConfiguration(QString savePath_, QString
 * readFilePath_, QString startCell_, QString configPath_) : savePath(savePath_),
 * readFilePath(readFilePath_), startCell(startCell_), configPath(configPath_)
 * \brief Init of AutoDocConfiguration class
 *
 * \param savePath_ - path to save generated file
 * \param readFilePath_ - path of read file (excel table in our case)
 * \param startCell_ - coordinates in excel style of start cell
 * \param configFile_ - path to configuration file
 *
 *  I guess, i should not use a class but...
 *
 *  \return Inited ExcelWorker class
 */
AutoDocConfiguration::AutoDocConfiguration(
    QString savePath_, QString readFilePath_, QString startCell_, QString configPath_)
: savePath(savePath_)
, readFilePath(readFilePath_)
, startCell(startCell_)
, configPath(configPath_)
{
}
