#ifndef EXCELWORKER_HPP
#define EXCELWORKER_HPP

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

class ExcelWorker
{
public:
    ExcelWorker();

    std::vector<QString> getFirstCellsText(QString filepath, QString startPosition);
};

#endif // EXCELWORKER_HPP
