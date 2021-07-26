#include "excelworker.hpp"

ExcelWorker::ExcelWorker()
{

}

std::vector<QString> ExcelWorker::getFirstCellsText(QString filepath, QString startPosition)
{
    std::vector<QString> outVec;

    QXlsx::Document excelDoc(filepath);
    if (!excelDoc.load())
        return outVec;

    QStringList separatedStartPosition = startPosition.split(" ");
    int currentRow = separatedStartPosition[1].toInt();
    qDebug("%d", currentRow);

    QString curName = excelDoc.read(startPosition.replace(" ", "")).toString();
//    qDebug("Is start cell NULL? %s", filepath.toStdString().c_str());
    while (curName != "")
    {
        outVec.push_back(curName);
        currentRow++;
        curName = excelDoc.read(separatedStartPosition[0] + QString::number(currentRow)).toString();
    }

    return outVec;
}
