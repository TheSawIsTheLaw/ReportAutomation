#ifndef ORGANISATIONSCHOICEWINDOW_HPP
#define ORGANISATIONSCHOICEWINDOW_HPP

#include <QDialog>
#include <QListWidget>
#include "excelworker.hpp"

namespace Ui
{
class OrganisationsChoiceWindow;
}

class OrganisationsChoiceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OrganisationsChoiceWindow(QString filepath_, QWidget *parent = nullptr);
    ~OrganisationsChoiceWindow();

private:
    Ui::OrganisationsChoiceWindow *ui;
};

#endif // ORGANISATIONSCHOICEWINDOW_HPP
