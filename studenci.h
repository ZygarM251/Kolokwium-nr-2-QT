#ifndef STUDENCI_H
#define STUDENCI_H
#include <QString>
#include <QVector>
class Studenci
{
private:
    QString imie;
    QString nazwisko ;
    int ocena_Informatyka;
    int ocena_Matematyka;

public:
    Studenci(QString IMIE,QString NAZWISKO,int OcenaInformatyka,int OcenaMatematyka);

    QString getImie()const {return imie;}
    QString getNawisko()const {return nazwisko;}
    int getInformatyka()const {return ocena_Informatyka;}
    int getMatematyka()const {return ocena_Matematyka;}

};
#endif // STUDENCI_H
