#ifndef ORGANISATIONSCHOICEWINDOW_HPP
#define ORGANISATIONSCHOICEWINDOW_HPP

#include <QDialog>
#include <QListWidget>
#include <QErrorMessage>
#include "reportcreator.hpp"
#include "excelworker.hpp"
#include "autodocconfiguration.hpp"

namespace Ui
{
class OrganisationsChoiceWindow;
}

class OrganisationsChoiceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OrganisationsChoiceWindow(AutoDocConfiguration &conf, QWidget *parent = nullptr);
    ~OrganisationsChoiceWindow();

private slots:
    void on_buttonsGroup_accepted();

private:
    Ui::OrganisationsChoiceWindow *ui;
    AutoDocConfiguration configuration;
};

#endif // ORGANISATIONSCHOICEWINDOW_HPP
