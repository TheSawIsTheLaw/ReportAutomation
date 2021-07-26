#include "facade.hpp"

Facade::Facade()
{
    configuration = new AutoDocConfiguration();

    if (std::filesystem::exists(
            PATH_TO_CONF)) // !!!!!!!!!!!!!!!!!!!!!! Потребуется изменить
    {
        std::ifstream conf(PATH_TO_CONF);
        std::string checkSubstr = "";
        std::string line = "";
        for (getline(conf, line), checkSubstr = line.substr(0, 3);
             checkSubstr == "--!" || checkSubstr == "###";
             getline(conf, line), checkSubstr = line.substr(0, 3))
        {}

        QString startCell = QString::fromStdString(line);
        startCell.replace(" ", "");
        std::cout << startCell.toStdString();
    }
}

void Facade::setSavePathForConfiguration(QString path) { configuration->savePath = path; }

void Facade::setAnalyzeFile(QString filePath)
{
    if (std::filesystem::exists(filePath.toUtf8().toStdString()))
        return;
    qDebug("Exists");
    configuration->readFilePath = filePath;
    qDebug("Filepath: '%s'", filePath.toStdString().c_str());
}

int Facade::setConfigByFile(QString filePath)
{
    if (std::filesystem::exists(filePath.toUtf8().toStdString()))
        return -FILE_NOT_EXIST_ERR;

    // TODO!

    return SUCCESS;
}

void Facade::initChoiceOfOrgs(QWidget *parent)
{
    if (configuration->readFilePath == "" || configuration->startCell == "" ||
        configuration->savePath == "")
    {
        QErrorMessage *errorWin = new QErrorMessage();
        errorWin->setWindowTitle("Ошибка");
        errorWin->showMessage("Не заданы параметры для выполнения работы.");
        return;
    }

    OrganisationsChoiceWindow orgChoiceWin(
        configuration->readFilePath, configuration->startCell, parent);

    orgChoiceWin.setModal(true);
    orgChoiceWin.exec();
}
