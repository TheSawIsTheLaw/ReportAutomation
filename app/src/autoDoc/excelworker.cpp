#include "excelworker.hpp"

ExcelWorker::ExcelWorker()
{

}

std::vector<QString> ExcelWorker::getFirstCellsText(QString filepath)
{
    std::vector<QString> outVec;

    QXlsx::Document excelDoc(filepath);
    if (!excelDoc.load())
        return outVec;

    int currentRow = 3;
    QString curName = excelDoc.read(currentRow, 3).toString();
    qDebug("Is start cell NULL? %s", filepath.toStdString().c_str());
    while (curName != "")
    {
        outVec.push_back(curName);
        currentRow++;
        curName = excelDoc.read(currentRow, 3).toString();
    }

    return outVec;
}
