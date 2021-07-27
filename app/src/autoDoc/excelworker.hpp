#ifndef EXCELWORKER_HPP
#define EXCELWORKER_HPP

#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxchartsheet.h"
#include "xlsxdocument.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

/*! \class ExcelWorker
    \brief Contains method for excel table analyze

    May only get names of organisations. Noice.
 */
class ExcelWorker
{
public:
    ExcelWorker();

    std::vector<QString> getFirstCellsText(QString filepath, QString startPosition);
};

#endif // EXCELWORKER_HPP
