#include "mainwindow.hpp"
#include "organisationschoicewindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("Тук-тук, кто там? Плохой нейминг"));
    // Without BBB sound today :(

    facade = new Facade();

    // test
//    QFile file(QString("C:/Users/dobri/Downloads/exam_timetable_2020_2021_s2_all.xls"));
//    bool isOpen = file.open(QIODevice::ReadOnly | QIODevice::Text);
//    if (isOpen)
//        qDebug("Opened!");
//    else
//        qDebug("Fuck");
//    while (!file.atEnd())
//        qDebug("%s", file.readLine().toStdString().c_str());
//    file.close();
    // end
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_MakeReportButton_clicked()
{
    facade->initChoiceOfOrgs(this);
}

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

void MainWindow::on_LoadNewConfigButton_clicked()
{
    QString gotFilePath = QFileDialog::getOpenFileName(
        this, "Выбор конфигурационного файла", ".", "*.ycfg");
    facade->setConfigByFile(gotFilePath);
}
