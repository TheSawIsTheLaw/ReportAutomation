#include "organisationschoicewindow.hpp"
#include "ui_organisationschoicewindow.h"

OrganisationsChoiceWindow::OrganisationsChoiceWindow(
    AutoDocConfiguration &conf, QWidget *parent)
: QDialog(parent), ui(new Ui::OrganisationsChoiceWindow)
{
    ui->setupUi(this);
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
    QList<QListWidgetItem *> items = ui->listOfFoundedCompanies->selectedItems();

    int startRow = configuration.startCell.split(" ")[1].toInt();
    int exitCode = 0;
    for (int i = 0; i < items.size() && !exitCode; i++)
    {
        exitCode = ReportCreator(configuration.readFilePath, configuration.savePath,
            configuration.configPath, startRow + i)
                       .startProc();
        if (exitCode == 1)
        {
            QErrorMessage *err = new QErrorMessage(this);
            err->setWindowTitle("Ошибка");
            err->showMessage("Произошла ошибка во время обработки таблицы.\nПроверьте "
                             "целостность конфигурационного файла или таблицы.");
        }
        else if (exitCode == 2)
        {
            QErrorMessage *err = new QErrorMessage(this);
            err->setWindowFilePath("Ошибка");
            err->showMessage("Файл не доступен для записи (%s). Закройте документ и повторите "
                             "попытку ещё раз.", items.at(i)->text());
        }
    }

    if (exitCode) {}
}
