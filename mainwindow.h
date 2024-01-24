#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QList>
#include <QPixmap>
#include "studenci.h"
#include "form.h"

QT_BEGIN_NAMESPACE
namespace Ui {
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
    void on_Dodaj_Studenta_clicked();
    void dodajStudenta(QString imie,QString nazwisko,int o_informatyka,int o_matematyka);

    void srednia();
    void on_Srednia_clicked();

private:
    Ui::MainWindow *ui;
    QList<Studenci> listaStudentow;

};
#endif // MAINWINDOW_H
