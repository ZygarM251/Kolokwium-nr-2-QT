#include "form.h"
#include "ui_form.h"

form::form(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::form)
{
    ui->setupUi(this);
    ui->O_Informatyka->setMinimum(1);
    ui->O_Informatyka->setMaximum(6);

    // Ustaw zakres dla ocen z matematyki od 1 do 6
    ui->O_Matematyka->setMinimum(1);
    ui->O_Matematyka->setMaximum(6);
}

form::~form()
{
    delete ui;
}

void form::on_buttonBox_accepted()
{
    QString imie = ui->Imie->toPlainText();
    QString nazwisko = ui->Nazwisko->toPlainText();
    int ocena_Informatyka = ui->O_Informatyka->value();
    int ocena_Matematyka = ui->O_Matematyka->value();

    emit dodajStudenta(imie,nazwisko,ocena_Informatyka,ocena_Matematyka);
}

