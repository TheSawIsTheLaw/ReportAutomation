#ifndef ORGANISATIONSCHOICEWINDOW_HPP
#define ORGANISATIONSCHOICEWINDOW_HPP

#include <QDialog>
#include <QListWidget>

namespace Ui
{
class OrganisationsChoiceWindow;
}

class OrganisationsChoiceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OrganisationsChoiceWindow(QWidget *parent = nullptr);
    ~OrganisationsChoiceWindow();

private:
    Ui::OrganisationsChoiceWindow *ui;
};

#endif // ORGANISATIONSCHOICEWINDOW_HPP
