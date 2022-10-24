#include<iostream>
#include<cmath>
using namespace std;

//Definicja szablonu klasy (uog�lnionej) Oceny
template<class T> //szablon ma jeden parametr szablonowy T
class Oceny {
public:
    //Definicja kontruktora domy�lnego
    Oceny() {
        cout << "Wywo�anie konstruktora klasy og�lnej..." << endl;
    }
    //Definicje szablon�w zmiennych cz�onkowskich
    T wyklad;
    T cwiczenia;
    T laboratorium;
    T seminarium;
    //Definicja szablonu funkcji cz�onkowskiej srednia()
    T srednia() {
        return (wyklad + cwiczenia + laboratorium + seminarium) / 4;
        /*UWAGA:
        Je�eli zmienne cz�onkowskie wyklad, cwiczenia, laboratorium, seminarium nale�� do typu ca�kowitego
        mamy do czynienia z dzieleniem ca�kowitym.*/
    }

};

//Definicja specjalizacji szablonu klasy Oceny dla typu long
template<>
class Oceny<long> {
public:
    //Definicja kontruktora domy�lnego
    Oceny() {
        cout << "Wywo�anie konstruktora klasy specjalizowanej..." << endl;
    }
    //Definicje szablon�w zmiennych cz�onkowskich
    long wyklad;
    long cwiczenia;
    long laboratorium;
    long seminarium;
    //Definicja szablonu funkcji cz�onkowskiej srednia()
    long srednia() {
        return (round(wyklad) + round(cwiczenia) + round(laboratorium) + round(seminarium)) / 4;
        /*UWAGA:
        Kod (implementacja) metody �rednia w klasie specjalizowanej r�ni si� od kodu szablonu metody o tej samej nazwie
        zdefiniowanej w klasie uog�lnionej.*/
    }

};

int main()
{
    //Utworzenie obiektu oceny1
    Oceny<int> oceny1 = Oceny<int>(); //jawne wywo�anie konstruktora domy�lnego
    /*UWAGA:
    Obiekt oceny1 zosta� utworzony na podstawie klasy og�lnej Oceny po jej konkretyzacji dla typu int.
    Wcze�niej kompilator sprawdzi�, �e nie jest dost�pna specjalizacja szablonu Oceny dla typu int.*/
    oceny1.wyklad = 3;
    oceny1.cwiczenia = 4;
    oceny1.laboratorium = 3;
    oceny1.seminarium = 4;
    cout << "�rednia ocen semestralnych: " << oceny1.srednia() << endl;

    //Utworzenie obiektu oceny2
    Oceny<long> oceny3; //niejawne wywo�anie konstruktora domy�lnego
    /*UWAGA:
    Obiekt oceny2 zostaje utworzony na podstawie specjalizacji szablonu klasy Oceny dla typu danych long.*/
    oceny3.wyklad = 3.0;
    oceny3.cwiczenia = 4.0;
    oceny3.laboratorium = 3.0;
    oceny3.seminarium = 4.0;
    cout << "�rednia ocen semestralnych: " << oceny3.srednia() << endl;

    return 0;
}