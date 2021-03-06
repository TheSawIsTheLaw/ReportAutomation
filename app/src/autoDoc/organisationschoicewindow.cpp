#include "organisationschoicewindow.hpp"
#include "ui_organisationschoicewindow.h"

/**
 * \fn OrganisationsChoiceWindow::OrganisationsChoiceWindow(AutoDocConfiguration
 * &configuration_, QWidget *parent): QDialog(parent), ui(new
 * Ui::OrganisationsChoiceWindow), configuration(configuration_)
 * \brief Init of OrganisationsChoiceWindow
 *
 * Inits Excel Worker and gets names of organisation for a listOfFOundedCompanies.
 *
 * \param AutoDocConfiguration *configuration_ - configuration class
 * \param Parent a parent j.j
 *
 *  \return Inited OrganisationsChoiceWindow class
 */
OrganisationsChoiceWindow::OrganisationsChoiceWindow(
    AutoDocConfiguration &configuration_, QWidget *parent)
: QDialog(parent), ui(new Ui::OrganisationsChoiceWindow), configuration(configuration_)
{
    ui->setupUi(this);
    this->setWindowTitle("Обнаруженные данные в таблице");

    ui->listOfFoundedCompanies->setSelectionMode(QAbstractItemView::MultiSelection);

    ExcelWorker excelReader;
    std::vector<QString> names = excelReader.getFirstCellsText(
        configuration.readFilePath, configuration.startCell);

    for (std::vector<QString>::iterator it = names.begin(); it != names.end(); it++)
        ui->listOfFoundedCompanies->addItem((*it).remove('\n'));
}

OrganisationsChoiceWindow::~OrganisationsChoiceWindow() { delete ui; }

/**
 * \fn void OrganisationsChoiceWindow::on_buttonsGroup_accepted()
 * \brief Slot for buttonsGroup when choice was accepted
 *
 * Generates reports for each selected name in listOfFOundedCompanies
 */

void OrganisationsChoiceWindow::on_buttonsGroup_accepted()
{
    QList<QModelIndex> items =
        ui->listOfFoundedCompanies->selectionModel()->selectedIndexes();

    int exitCode = 0;

    QProgressDialog progressDial("Генерим отчёты...", "Отмена", 0, items.size(), nullptr);
    progressDial.setModal(true);

    for (int i = 0; i < items.size() && !exitCode && !progressDial.wasCanceled(); i++)
    {
        qApp->processEvents();
        progressDial.setValue(i);

        exitCode = ReportCreator(configuration.readFilePath, configuration.savePath,
            configuration.configPath, items.at(i).row())
                       .startProc();

        if (exitCode == 1)
        {
            QErrorMessage *err = new QErrorMessage(this);
            err->setWindowTitle("Ошибка");
            err->showMessage("Произошла ошибка во время обработки таблицы (" +
                             ui->listOfFoundedCompanies->selectedItems().at(i)->text() +
                             ").\nПроверьте "
                             "целостность конфигурационного файла или таблицы.");
        }
        else if (exitCode == 2)
        {
            QErrorMessage *err = new QErrorMessage(this);
            err->setWindowFilePath("Ошибка");
            err->showMessage("Файл не доступен для записи (" +
                             ui->listOfFoundedCompanies->selectedItems().at(i)->text() +
                             "). Закройте документ и повторите "
                             "попытку ещё раз.");
        }
    }

    progressDial.setValue(items.size());
    progressDial.close();
}
