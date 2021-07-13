#include "mainwindow.hpp"
#include "organisationschoicewindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    facade = new Facade();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_MakeReportButton_clicked()
{
    OrganisationsChoiceWindow orgChoiceWin(this);
    orgChoiceWin.setModal(true);
    orgChoiceWin.exec();
}

void MainWindow::on_SetSavePathButton_clicked()
{
    QString gotPath = QFileDialog::getExistingDirectory(this, "Выбор пути сохранения отчёта", ".");
    if (gotPath != "")
    {
        ui->PathStatusLabel->setText(gotPath);
        facade->setSavePathForConfiguration(gotPath);
    }
}


void MainWindow::on_TableFileButton_clicked()
{
    QString gotFilePath = QFileDialog::getOpenFileName(this, "Выбор пути сохранения отчёта", ".", "*.xls;*.xlsx");
    if (gotFilePath != "")
    {
        ui->TableFileLabel->setText(gotFilePath);
        facade->setAnalyzeFile(gotFilePath);
    }
}

