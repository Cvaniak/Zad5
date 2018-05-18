#ifndef ROBOT_HH
#define ROBOT_HH

#include <iostream>
#include <vector>
#include "Wektor2D.hh"
#include "Przeszkoda.hh"

#include "ObiektGraficzny.hh"
#include "lacze_do_gnuplota.hh"
#include "Scieszka.hh"
#include <typeinfo> 
#include <string>
#include <memory>



  /*!
   * \brief Klasa Robota
   *
   * Klasa dziedziczy po robocie, sterowany przez Scene
   */
class Robot : public ObiektGraficzny
{
protected:
  /*!
   * \brief numer indeksu wykorzystywany do tworzenia nazwy
   */
  int numer;
public:
  /*!
   * \brief Zmienna informujaca o wielkosci robota
   */
  double rozmiar = 1;
  /*!
   * \brief Aktualny kat obrotu robota
   */
  double kat = 0;
  /*!
   * \brief Docelowy kat obrotu robota
   */
  double katDocelowy = 0;
  /*!
   * \brief Docelowe polozenie robota
   */
  Wektor2D polozenieDocelowe = {0, 0};
  /*!
   * \brief promien do kolizji
   */
  double promien = 0;
  /*!
   * \brief jednostka ruchu do przodu
   */
  double krok_move = 50;
  /*!
   * \brief jednostka ruchu katowego
   */
  double krok_kat = 3;
  /*!
   * \brief Indywidualna scieszka dla danego robota
   */
  Scieszka Sciesz;
  //Robot(){}
  /*!
   * \brief Konstruktor robota
   *
   * Nadaje mu nazwe, inicjalizuje scieszke, Inicjalizuje krztalt
   */
  Robot(int x)
  {
    numer = x;
    std::string   a = "figury/";
    std::string   b = "robot";
    std::string   c = std::to_string(x);
    std::string   d = ".dat";
    name = a + b + c + d;
    Sciesz.Inicjalizuj(x);
    Inicjalizuj();
  }
  /*!
   * \brief Konstruktor robota
   *
   * Nadaje mu nazwe, inicjalizuje scieszke, Inicjalizuje krztalt
   */
  Robot(int x, Wektor2D Pozycja)
  {
    _PolozenieObiektu = Pozycja;
    polozenieDocelowe = Pozycja;
    numer = x;
    std::string   a = "figury/";
    std::string   b = "robot";
    std::string   c = std::to_string(x);
    std::string   d = ".dat";
    name = a + b + c + d;
    Sciesz.Inicjalizuj(x);
    Inicjalizuj();
  }
  /*!
   * \brief Metoda incjacji krztaltu Robota
   */
  void InicjalizujKsztalt();
  /*!
   * \brief Metoda wywolujoca Inicjalizacje krztaltu robota i scieszki
   */
  void Inicjalizuj();
  /*!
   * \brief Zmienia polozenie
   */
  void ZmienPolozenie(double x, double y);
  /*!
   * \brief Zmienia polozenie
   */
  void ZmienPolozenie(Wektor2D W);
  /*!
   * \brief Obrot do kata podanego w zmiennej kat
   */
  void Obrot();
  /*!
   * \brief Obrot o kat
   */
  void Obrot(double a);
  /*!
   * \brief Obrot o kat wyrownujacy przod z wektorem
   */
  void Obrot(Wektor2D W);
  /*!
   * \brief Wyznacza kat o jaki trzeba obrocic by skierowac Robota w strone punktu
   */
  double KatObrotu(Wektor2D W);
  /*!
   * \brief Zwraca wektor jednostkowy rownolegly do Robota
   */
  Wektor2D KrokRuchu();
  /*!
   * \brief Zwraca wektor jednostkowy rownolegly do Robota
   */
  Wektor2D KrokRuchu(double danyKat);
  /*!
   * \brief Aktualizuje pozycje do aktualnej i dodaje punkt do scieszki
   */
  void Move();
  /*!
   * \brief Przemieszcza o dana wartosc
   */
  void Move(double a);
  /*!
   * \brief Przemieszcza do danego punktu
   */
  void Move(Wektor2D W);
  /*!
   * \brief Przemieszcza do danego punktu i Rysuje
   */
  void Move(Wektor2D W, PzG::LaczeDoGNUPlota L);
  /*!
   * \brief Zapisuje do odpowiednich plikow Robota i jego Scieszke
   */
  void Update();
  /*!
   * \brief Zapisuje do odpowiednich plikow Robota i jego Scieszke i Rysuje
   */
  void Update( PzG::LaczeDoGNUPlota L);
  /*!
   * \brief Obraca z animacja i przesuwa z animacja i rysuje
   */
  bool Animuj(std::vector <std::shared_ptr <Przeszkoda>> Przeszkody, std::vector <std::shared_ptr <Robot>> Roboty, std::list<std::shared_ptr <ObiektGraficzny>> listaObiektow);
  /*!
   * \brief Obraca z animacja i przesuwa z animacja i rysuje
   */
  void Animuj(double nowyKat, double nowePolozenie, PzG::LaczeDoGNUPlota L);
  /*!
   * \brief Skaluje do danej wielkosci
   */
  void Skaluj(double s);
  /*!
   * \brief Skaluje do danej wielkosci
   */
  void UstalPolozenie(double zmianaKata, double zmianaPolozenia, int typ = 0);
  /*!
   * \brief Skaluje do danej wielkosci
   */
  void UstalPolozenie(Wektor2D punktKoncowy);

  bool Collision(std::vector <std::shared_ptr <Przeszkoda>> Przeszkody);
  
  bool CollisionWithRobots(std::vector <std::shared_ptr <Robot>> Roboty);
  
  //void Kolizja(ObiektGraficzny OB);

  
};

#endif
