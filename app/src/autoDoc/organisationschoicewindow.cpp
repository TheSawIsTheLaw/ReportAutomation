#include "organisationschoicewindow.hpp"
#include "ui_organisationschoicewindow.h"

OrganisationsChoiceWindow::OrganisationsChoiceWindow(
    AutoDocConfiguration &conf, QWidget *parent)
: QDialog(parent), ui(new Ui::OrganisationsChoiceWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Обнаруженные данные в таблице");
    configuration = conf;

    ui->listOfFoundedCompanies->setSelectionMode(QAbstractItemView::MultiSelection);

    ExcelWorker excelReader;
    std::vector<QString> names =
        excelReader.getFirstCellsText(conf.readFilePath, configuration.startCell);
    for (std::vector<QString>::iterator it = names.begin(); it != names.end(); it++)
        ui->listOfFoundedCompanies->addItem((*it).remove('\n'));
}

OrganisationsChoiceWindow::~OrganisationsChoiceWindow() { delete ui; }

void OrganisationsChoiceWindow::on_buttonsGroup_accepted()
{
    QList<QModelIndex> items = ui->listOfFoundedCompanies->selectionModel()->selectedIndexes();

    int exitCode = 0;

    QProgressDialog progressDial("Генерим отчёты...", "Отмена", 0, items.size(), nullptr);
    progressDial.setModal(true);
    progressDial.setValue(0);
    progressDial.wasCanceled();
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
            err->showMessage("Произошла ошибка во время обработки таблицы (" + ui->listOfFoundedCompanies->selectedItems().at(i)->text() + ").\nПроверьте "
                             "целостность конфигурационного файла или таблицы.");
        }
        else if (exitCode == 2)
        {
            QErrorMessage *err = new QErrorMessage(this);
            err->setWindowFilePath("Ошибка");
            err->showMessage("Файл не доступен для записи (" + ui->listOfFoundedCompanies->selectedItems().at(i)->text() + "). Закройте документ и повторите "
                             "попытку ещё раз.");
        }

    }
    progressDial.setValue(items.size());
    progressDial.close();
}
