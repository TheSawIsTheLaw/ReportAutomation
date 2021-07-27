#include "facade.hpp"

/**
 * \fn Facade::Facade() : configuration(new AutoDocConfiguration())
 * \brief Facade init function
 *
 * \return Facade class with configuration inited
 */
Facade::Facade() : configuration(new AutoDocConfiguration())
{
    setConfigByFile(PATH_TO_CONF);
}

/**
 * \fn void Facade::setSavePathForConfiguration(QString path)
 * \brief Save path of configuration file
 *
 * \param QString path - path of new configuration file
 */
void Facade::setSavePathForConfiguration(QString path) { configuration->savePath = path; }

/**
 * \fn void Facade::setAnalyzeFile(QString filePath)
 * \brief Save path to analyze file (excel table in our case)
 *
 * \param QString filePath - path to excel table
 */
void Facade::setAnalyzeFile(QString filePath)
{
    if (std::filesystem::exists(filePath.toUtf8().toStdString()))
        return;
    //    qDebug("Exists");
    configuration->readFilePath = filePath;
    //    qDebug("Filepath: '%s'", filePath.toStdString().c_str());
}

/**
 * \fn int Facade::setConfigByFile(QString filePath)
 * \brief Save path to configuration file and sets value of
 * startCell field in AutoDocConfiguration class
 *
 * \param Qstring filePath - path to configuration file
 *
 * \return 0 if success
 */
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

/**
 * \fn void Facade::initChoiceOfOrgs(QWidget *parent)
 * \brief Opens new window to get user's choice of needed
 * orgs and to generate a report(s)
 *
 * \param QWidget *parent - a pointer to the parent O.o
 */
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
