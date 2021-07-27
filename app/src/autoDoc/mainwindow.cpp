#include "mainwindow.hpp"
#include "organisationschoicewindow.hpp"
#include "ui_mainwindow.h"

#include "reportcreator.hpp"

/**
 * \fn MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
 * \brief MainWindow init function
 *
 * \param parent a parent O.o
 *
 * \return MainWindow class with facade inited
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("Отчёто-генератор-2000"));
    // Without BBB sound today :(

    facade = new Facade();
}

MainWindow::~MainWindow() { delete ui; }

/**
 * \fn void MainWindow::on_MakeReportButton_clicked()
 * \brief Slot for MakeReportButton
 *
 *  Inits choice of organisations from facade.
 *  Opens new window.
 */
void MainWindow::on_MakeReportButton_clicked() { facade->initChoiceOfOrgs(this); }

/**
 * \fn void MainWindow::on_SetSavePathButton_clicked()
 * \brief Slot for set SetSavePathButton
 *
 *  Gets directory to save generated document.
 *  Opens QFileDialog.
 */
void MainWindow::on_SetSavePathButton_clicked()
{
    QString gotPath =
        QFileDialog::getExistingDirectory(this, "Выбор пути сохранения отчёта", ".");
    if (gotPath != "")
    {
        ui->PathStatusLabel->setText(gotPath);
        facade->setSavePathForConfiguration(gotPath);
    }
}

/**
 * \fn void MainWindow::on_TableFileButton_clicked()
 * \brief Slot for set TableFileButton
 *
 *  Gets directory of excel document that contains all info.
 *  Opens QFileDialog.
 */
void MainWindow::on_TableFileButton_clicked()
{
    QString gotFilePath =
        QFileDialog::getOpenFileName(this, "Выбор источника", ".", "*.xls;*.xlsx");
    if (gotFilePath != "")
    {
        ui->TableFileLabel->setText(gotFilePath);
        facade->setAnalyzeFile(gotFilePath);
    }
}

/**
 * \fn void MainWindow::on_LoadNewConfigButton_clicked()
 * \brief Slot for set LoadNewConfigButton
 *
 *  Gets path of new configuration file and set it as used.
 *  Opens QFileDialog and sets config using facade.
 */
void MainWindow::on_LoadNewConfigButton_clicked()
{
    QString gotFilePath = QFileDialog::getOpenFileName(
        this, "Выбор конфигурационного файла", ".", "*.ycfg");
    facade->setConfigByFile(gotFilePath);
}
