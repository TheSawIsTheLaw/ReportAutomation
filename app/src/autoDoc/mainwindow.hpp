#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "facade.hpp"
#include <QErrorMessage>
#include <QFileDialog>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private Q_SLOTS:
    void on_MakeReportButton_clicked();

    void on_SetSavePathButton_clicked();

    void on_TableFileButton_clicked();

    void on_LoadNewConfigButton_clicked();

private:
    Facade *facade = nullptr;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
