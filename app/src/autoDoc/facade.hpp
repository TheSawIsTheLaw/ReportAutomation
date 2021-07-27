#ifndef FACADE_HPP
#define FACADE_HPP

#include "autodocconfiguration.hpp"
#include <filesystem>
#include <fstream>
#include <organisationschoicewindow.hpp>

#include <QErrorMessage>

#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxchartsheet.h"
#include "xlsxdocument.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

#include <fstream>

#include "constants.hpp"

#define SUCCESS 0
#define FILE_NOT_EXIST_ERR 1

// Legendary Facade. RIP CGCoursework.

/*! \class Facade
    \brief Contains all needed in case methods

    Includes methods for configuration sets, set of used in program paths and initiation
   of choice of organisation window
 */
class Facade
{
public:
    Facade();

    void setSavePathForConfiguration(QString path);
    void setAnalyzeFile(QString filePath);
    int setConfigByFile(QString filePath);
    void initChoiceOfOrgs(QWidget *parent);

private:
    AutoDocConfiguration *configuration;
};

#endif // FACADE_HPP
