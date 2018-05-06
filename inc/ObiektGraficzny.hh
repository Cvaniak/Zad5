#ifndef OBIEKTGRAFICZNY_HH
#define OBIEKTGRAFICZNY_HH

/*!
 * \file
 * \brief Definicja klasy ObiektGraficzny
 *
 * Plik zawiera definicję klasy ObiektGraficzny.
 */

#include <iostream>
#include <vector>
#include "Wektor2D.hh"
#include "lacze_do_gnuplota.hh"
#include <string>

/*!
 * \brief Modeluje obiekt, który ma swoją reprezentację graficzną
 *
 * Modeluje obiekt, który ma swoją reprezentację graficzną
 * w postaci łamanej. Może ona być łamaną zamkniętą w postaci
 * wieloboku lub otwartą. Ilość jej wierzchołków nie jest jawnie
 * ograniczona. Jedynym ograniczeniem jest dostępność pamięci
 * komputera.
 */
class ObiektGraficzny {
protected:

  public:
  /*!
   * \brief Zmienna przechowujaca nazwe Robota
   *
   * Nazwa obiektu to obiekt + numer
   */
  std::string name;
  /*!
   * \brief Współrzędne pozycji obiektu
   *
   *  Zawiera współrzędne punktu względem, którego podane są
   *  współrzędne punktów obrysu obiektu.
   */
   Wektor2D   _PolozenieObiektu;
  /*!
   * \brief Tablica wierzchołków
   *
   */
  std::vector <Wektor2D>   _TabWierz;
  /*!
   * \brief Tablica wierzchołków uzywana jako wzorzec
   *  
   */
  std::vector <Wektor2D>   _TabWierz_wzorzec;
  /*!
   * \brief Inicjalizacja współrzędnych wierzchołków
   */
   void InicjalizujKsztalt();
  /*!
   * \brief Metoda zapisuje do pliku współrzędne wierzchołków
   */
   bool ZapiszDoPliku(const char* sNazwaPliku) const;
  /*!
   * \brief Metoda zapisuje do strumienia współrzędne wierzchołków
   */   
   bool ZapiszDoStrumienia(std::ostream& StrmWy) const;
  /*!
   * \brief Zmiania współrzędne położenia obiektu
   */
  void ZmienPolozenie(double x, double y);
  /*!
   * \brief Zmiania współrzędne położenia obiektuxx
   */  
  void ZmienPolozenie(Wektor2D W);
  /*!
   * \brief Zapisuje do odpowiednich plikow Robota i jego Scieszke
   */
  void Update();
  /*!
   * \brief Zapisuje do odpowiednich plikow Robota i jego Scieszke i Rysuje
   */
  void Update( PzG::LaczeDoGNUPlota L);
};


#endif
