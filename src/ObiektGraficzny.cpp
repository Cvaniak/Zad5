/*!
 * \file
 * \brief Zawiera definicje metod klasy ObiektGraficzny
 *
 * Zawiera definicje metod klasy ObiektGraficzny
 * wraz z ich opisem.
 */

#include <fstream>
#include "ObiektGraficzny.hh"


using namespace std;


/*!
 * Przypisuje wartości współrzędnych poszczególnym wierzchołkom.
 *
 * Uwaga:Ta metoda to tylko tymczasowe rozwiązanie. Ona powinna
 *       być w klasie pochodnej.
 */
void ObiektGraficzny::InicjalizujKsztalt()
{
  _TabWierz.push_back({ 0 ,  45});
  _TabWierz.push_back({ 0 ,  0 });
  _TabWierz.push_back({ 0 ,  20});
  _TabWierz.push_back({ 20,  20});
  _TabWierz.push_back({ 20, -20});
  _TabWierz.push_back({-20, -20});
  _TabWierz.push_back({-20,  20});
  _TabWierz.push_back({  0,  20});
  /* _TabWierz[1][0] =  30;  _TabWierz[1][1]=   0;
  _TabWierz[2][0] =   0;  _TabWierz[2][1]= -30;
  _TabWierz[3][0] = -30;  _TabWierz[3][1]= -30;
  _TabWierz[4][0] = -30;  _TabWierz[4][1]=  30;
  _TabWierz[5][0] =   0;  _TabWierz[5][1]=  30;
  _TabWierz[6][0] =  30;  _TabWierz[6][1]=   0;*/
}



/*!
 *  Zmiania współrzędne położenia punktu, względem którego tworzony
 *  jest obrys obiektu.
 *  \param[in] x - współrzędna x-owa nowego położenia.
 *  \param[in] y - współrzędna y-owa nowego położenia.
 */
void ObiektGraficzny::ZmienPolozenie(double x, double y)
{
  _PolozenieObiektu[0] = x;
  _PolozenieObiektu[1] = y;  
}


/*!
 *  Zmiania współrzędne położenia punktu, względem którego tworzony
 *  jest obrys obiektu.
 *  \param[in] x - współrzędna x-owa nowego położenia.
 *  \param[in] y - współrzędna y-owa nowego położenia.
 */
void ObiektGraficzny::ZmienPolozenie(Wektor2D W)
{
  _PolozenieObiektu[0] = W[0];
  _PolozenieObiektu[1] = W[1];  
}


/*!
 * Zapisuje do strumienia współrzędne globalne wierzchołków
 * obrysu obiektu.
 * \param[in,out] - strumień, do którego wpisane zostałe współrzędne
 *                  wierzchołków.
 * \retval true - gdy operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ObiektGraficzny::ZapiszDoStrumienia(std::ostream& StrmWy) const
{
  Wektor2D  W_glob;

  for (Wektor2D  W_lok : _TabWierz) {
    W_glob = W_lok + _PolozenieObiektu;
    StrmWy << W_glob << endl;
  }
  return !StrmWy.fail();
}


/*!
 * Zapisuje do pliku współrzędne globalne wierzchołków
 * obrysu obiektu.
 * \param[in,out] - strumień, do którego wpisane zostałe współrzędne
 *                  wierzchołków.
 * \retval true - gdy operacja powiodła się,
 * \retval false - w przypadku przeciwnym.


 */
bool ObiektGraficzny::ZapiszDoPliku(const char* sNazwaPliku) const
{
  ofstream   StrmWy(sNazwaPliku);

  if (!StrmWy.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << sNazwaPliku
	 << "' nie powiodlo sie." << endl
	 << endl;
    return false;
  }
  return ZapiszDoStrumienia(StrmWy);
}
