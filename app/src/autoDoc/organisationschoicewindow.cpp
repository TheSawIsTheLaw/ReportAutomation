#include "organisationschoicewindow.hpp"
#include "ui_organisationschoicewindow.h"

OrganisationsChoiceWindow::OrganisationsChoiceWindow(QString filepath_, QWidget *parent)
: QDialog(parent), ui(new Ui::OrganisationsChoiceWindow)
{
    ui->setupUi(this);

    ui->listOfFoundedCompanies->setSelectionMode(QAbstractItemView::MultiSelection);

    ExcelWorker excelReader;
    std::vector<QString> names = excelReader.getFirstCellsText(filepath_);
    qDebug("%d", names.size());
    for (std::vector<QString>::iterator it = names.begin(); it != names.end(); it++)
        ui->listOfFoundedCompanies->addItem(*it);
}

OrganisationsChoiceWindow::~OrganisationsChoiceWindow() { delete ui; }
