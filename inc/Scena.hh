#ifndef SCENA_HH
#define SCENA_HH


#include "lacze_do_gnuplota.hh"
#include "Robot.hh"
#include "Przeszkoda.hh"
#include <vector>
#include <list>
#include <memory>

  /*!
   * \brief Klasa odpowiedzialna za dzialanie programu
   *
   * Klasa deklaruje zmienne i Laczedognuplota
   * oraz jest odpowiedzialna za wyswietlanie menu
   */
class Scena
{
  
public:
    /*!
   * \brief Tablica dynamiczna przechowujaca Roboty
   *
   * Przechowuje stworzone roboty
   * 
  std::list<std::shared_ptr <Robot>> Roboty;
   */
  std::vector <std::shared_ptr <Robot>> Roboty;
    /*!
   * \brief Tablica dynamiczna przechowujaca Roboty
   *
   * Przechowuje stworzone roboty
   * 
   */
  std::vector <std::shared_ptr<Przeszkoda>> Przeszkody;
  std::list<std::shared_ptr <ObiektGraficzny>> listaObiektow;
  /*!
   * \brief Lacze do Gnuplota
   *
   * Pozwala na wywolanie metod takich jak Rysuj()
   */
  PzG::LaczeDoGNUPlota Lacze;
    /*!
   * \brief Zmienna przechowujaca wiadomosc o ilosci robotow
   *
   * Dodatkowo jest wykorzystywana posrednio do indeksowania Robotow
   * to tymczasowy sposob
   */
  int IloscRobotow = 0;
  /*!
   * \brief Zmienna przechowujaca wiadomosc o ilosci robotow
   *
   * Dodatkowo jest wykorzystywana posrednio do indeksowania Robotow
   * to tymczasowy sposob
   */
  int IloscPrzeszkod = 0;
  /*!
   * \brief Zmienna przechowujaca wiadomosc o ilosci robotow
   *
   */
  int Status = 0;
  /*!
   * \brief Zmienna przechowujaca wiadomosc o ilosci robotow
   *
   * Dodatkowo jest wykorzystywana posrednio do indeksowania Robotow
   * to tymczasowy sposob
   */
  int szybkoscAnimacji = 100000;
  /*!
   * \brief Zmienna uzywana do zmiany polozenia  
   *
   */
  Wektor2D NowePolozenie= {0, 0};
  /*!
   * \brief Deklaracja Sceny
   *
   * Przy deklaracji jest inicjonowany tyb wyswietlania
   */
  Scena(){Lacze.ZmienTrybRys(PzG::TR_2D); }  /*!
   * \brief Glowna petla programu
   *
   * Wywoluje Menu itp.
   */
  int Run();
  /*!
   * \brief metoda tworzaca nowego robota
   *
   * Tworzy rowniez odpowiednie lacze z Gnuplotem
   */
  int nowyRobot(int x, Wektor2D W);
  /*!
   * \brief metoda tworzaca nowego robota
   *
   * Tworzy rowniez odpowiednie lacze z Gnuplotem
   */
  int nowaPrzeszkoda(int x, Wektor2D Polozenie, double Szerokosc, double Wysokosc);
  /*!
   * \brief Nic nie robi narazie
   *
   *
   */
  void Update();
  /*!
   * \brief Wywoluje Menu
   *
   * Wyswietla mozliwe opcje
   */
  void Menu();

  void OdnowListePlikow();

  void Sterowanie(int c);
};
  
#endif
