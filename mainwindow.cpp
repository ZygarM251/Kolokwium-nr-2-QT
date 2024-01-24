#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap zdjecie("M:/Mariusz Zywar/Na urki/kol.jpg");
    ui->Logo->setPixmap(zdjecie.scaled(400,400,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dodajStudenta(QString imie,QString nazwisko,int o_informatyka,int o_matematyka)
{

    listaStudentow.append(Studenci(imie,nazwisko,o_informatyka,o_matematyka));

        int rowPosition = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowPosition);
        //Wprowadzanie danych
        ui->tableWidget->setItem(rowPosition, 0, new QTableWidgetItem(imie));
        ui->tableWidget->setItem(rowPosition, 1, new QTableWidgetItem(nazwisko));
        ui->tableWidget->setItem(rowPosition, 2, new QTableWidgetItem(QString::number(o_informatyka)));
        ui->tableWidget->setItem(rowPosition, 3, new QTableWidgetItem(QString::number(o_matematyka)));
    ui->tableWidget->sortItems(1, Qt::AscendingOrder);
};



void MainWindow::on_Dodaj_Studenta_clicked()
{
    form* Formularz = new form(this);
    Formularz->show();

    // Połącz sygnał z okna dodawania z funkcją obsługującą dodawanie klienta
    connect(Formularz, SIGNAL(dodajStudenta(QString, QString, int, int)), this, SLOT(dodajStudenta(QString, QString, int, int)));
}

void MainWindow::srednia()
{
    if (listaStudentow.isEmpty())
    {
        ui->textSrednie->setText("Nie podano żadnych danych.");
            return;
    }

    ui->textSrednie->clear();

    double sumaOcenInformatyka = 0.0;
    double sumaOcenMatematyka = 0.0;
    double sredniaInformatyka = 0.0;
    double sredniaMatematyka = 0.0;

    for (int i = 0; i < listaStudentow.size(); i++)
    {
        const Studenci &stud = listaStudentow.at(i);

        sumaOcenInformatyka += stud.getInformatyka();
        sumaOcenMatematyka += stud.getMatematyka();
    }

    // Poprawione obliczenia średnich
    if (!listaStudentow.isEmpty())
    {
        sredniaInformatyka = sumaOcenInformatyka / listaStudentow.size();
        sredniaMatematyka = sumaOcenMatematyka / listaStudentow.size();
    }

    ui->textSrednie->append(QString("<b>Średnia ocen z Informatyki wynosi:</b> %1").arg(sredniaInformatyka));
        ui->textSrednie->append(QString("<b>Średnia ocen z Matematyki wynosi:</b> %1").arg(sredniaMatematyka));
}

void MainWindow::on_Srednia_clicked()
{
    srednia();
}

