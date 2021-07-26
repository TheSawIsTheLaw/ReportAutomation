#ifndef FACADE_HPP
#define FACADE_HPP

#include "autodocconfiguration.hpp"
#include <filesystem>
#include <fstream>
#include <organisationschoicewindow.hpp>

#include <QErrorMessage>

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

#define SUCCESS 0
#define FILE_NOT_EXIST_ERR 1

#define PATH_TO_CONF "../../src/config/stdConfig.ycfg"

// Legendary Facade. RIP CGCoursework.
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
