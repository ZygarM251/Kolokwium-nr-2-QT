#ifndef FORM_H
#define FORM_H

#include <QDialog>
#include <QString>
#include <QTextEdit>

namespace Ui {
class form;
}

class form : public QDialog
{
    Q_OBJECT
signals:
    void dodajStudenta(QString imie,QString nazwisko,int o_informatyka,int o_matematyka);

public:
    explicit form(QWidget *parent = nullptr);
    ~form();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::form *ui;
};

#endif // FORM_H
