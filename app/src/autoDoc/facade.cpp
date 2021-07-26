#include "facade.hpp"

Facade::Facade()
{
    configuration = new AutoDocConfiguration();
    setConfigByFile(PATH_TO_CONF); // !!!!!!!!!!!!!!!!!!!!!! Потребуется изменить
}

void Facade::setSavePathForConfiguration(QString path) { configuration->savePath = path; }

void Facade::setAnalyzeFile(QString filePath)
{
    if (std::filesystem::exists(filePath.toUtf8().toStdString()))
        return;
    //    qDebug("Exists");
    configuration->readFilePath = filePath;
    //    qDebug("Filepath: '%s'", filePath.toStdString().c_str());
}

int Facade::setConfigByFile(QString filePath)
{
    if (!std::filesystem::exists(filePath.toStdString()))
        return 1;

    std::ifstream conf(filePath.toStdString());
    std::string checkSubstr = "";
    std::string line = "";
    for (getline(conf, line), checkSubstr = line.substr(0, 3);
         checkSubstr == "--!" || checkSubstr == "###";
         getline(conf, line), checkSubstr = line.substr(0, 3))
    {}

    configuration->startCell = QString::fromStdString(line);

    return 0;
}

void Facade::initChoiceOfOrgs(QWidget *parent)
{
    if (configuration->readFilePath == "" || configuration->startCell == "" ||
        configuration->savePath == "")
    {
        //        qDebug("%s %s %s", configuration->readFilePath.toStdString().c_str(),
        //            configuration->startCell.toStdString().c_str(),
        //            configuration->savePath.toStdString().c_str());
        QErrorMessage *errorWin = new QErrorMessage();
        errorWin->setWindowTitle("Ошибка");
        errorWin->showMessage("Не заданы параметры для выполнения работы.");
        return;
    }

    OrganisationsChoiceWindow orgChoiceWin(*configuration, parent);

    orgChoiceWin.setModal(true);
    orgChoiceWin.exec();
}

int Facade::generateReport(int row)
{
    ReportCreator creator(configuration->readFilePath, configuration->savePath,
        configuration->configPath, row);
    return creator.startProc();
}
