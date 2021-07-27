#include "excelworker.hpp"

/**
 * \fn ExcelWorker::ExcelWorker()
 * \brief Init of ExcelWorker class
 *
 *  Inits ExcelWorker using nothing
 *
 *  I guess, i should not use a class but...
 *
 *  \return Inited ExcelWorker class
 */
ExcelWorker::ExcelWorker() {}

/**
 * \fn std::vector<QString> ExcelWorker::getFirstCellsText(
 * QString filepath, QString startPosition)
 * \brief Gets first column rows names
 *
 * \param QString filepath - path of excel table to analyze
 * \param QString startPosition - start position from which we will start (format:
 * column-row in excel style)
 *
 * \warning It will look up throuh all non-empty cells in the row.
 *
 *  \return Vector of got names from start position
 */

std::vector<QString> ExcelWorker::getFirstCellsText(
    QString filepath, QString startPosition)
{
    std::vector<QString> outVec;

    QXlsx::Document excelDoc(filepath);
    if (!excelDoc.load())
        return outVec;

    QStringList separatedStartPosition = startPosition.split(" ");
    int currentRow = separatedStartPosition[1].toInt();
    //    qDebug("%d", currentRow);

    QString curName = excelDoc.read(startPosition.replace(" ", "")).toString();
    //    qDebug("Is start cell NULL? %s", filepath.toStdString().c_str());
    while (curName != "")
    {
        outVec.push_back(curName);
        currentRow++;
        curName = excelDoc.read(separatedStartPosition[0] + QString::number(currentRow))
                      .toString();
    }

    return outVec;
}
