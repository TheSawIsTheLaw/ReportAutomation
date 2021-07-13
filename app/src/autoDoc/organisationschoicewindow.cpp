#include "organisationschoicewindow.hpp"
#include "ui_organisationschoicewindow.h"

OrganisationsChoiceWindow::OrganisationsChoiceWindow(QWidget *parent)
: QDialog(parent), ui(new Ui::OrganisationsChoiceWindow)
{
    ui->setupUi(this);
    ui->listOfFoundedCompanies->addItem(QString("1"));
    ui->listOfFoundedCompanies->addItem(QString("2"));
    ui->listOfFoundedCompanies->addItem(QString("3"));
    ui->listOfFoundedCompanies->setSelectionMode(QAbstractItemView::MultiSelection);
}

OrganisationsChoiceWindow::~OrganisationsChoiceWindow() { delete ui; }
