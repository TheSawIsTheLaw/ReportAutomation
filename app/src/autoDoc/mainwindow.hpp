#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "facade.hpp"
#include <QFileDialog>

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

private slots:
    void on_MakeReportButton_clicked();

    void on_SetSavePathButton_clicked();

    void on_TableFileButton_clicked();

private:
    Facade *facade = nullptr;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
