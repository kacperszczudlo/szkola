#include<iostream>
using namespace std;

//Definicja szablonu klasy Oceny
template<class T, int n>
//UWAGA:
//Szablon klasy oceny ma dwa parametry szablonowe: ug�lniony typ danych T oraz liczb� ca�kowit� n.
class Oceny {
public:
    T oceny[n]; //zmienna cz�onkowska
    T max() { //funkcja cz�onkowska
        T temp = oceny[0];
        for (int i = 0; i < n; i++) {
            if (oceny[i] > temp) temp = oceny[i];
        }
        return temp;
    }

    T min() { //funkcja cz�onkowska
        T temp = oceny[0];
        for (int i = 0; i < n; i++) {
            if (oceny[i] < temp) temp = oceny[i];
        }
        return temp;
    }
    T srednia() {
        T suma = 0;
        for (int i = 0; i < n; i++) {
            suma += oceny[i];
        }
        return suma / n;
    }
};

int main()
{
    //Utworzenie i inicjalizacja obiektu oceny
    Oceny<float, 6> oceny{ 3,5,4,1,2,6 };
    /*UWAGA:
    Szablon klasy Oceny zosta� skonkretyzowany za pomoc� argument�w szablonowych: typu danych int oraz liczby 3.
    Tym samym zosta�a wygenerowana instancja szablonu klasy Oceny - nowa klasa, w kt�rej uog�lniony typ danych T zosta�
    zast�piony typem ca�kowitym int, a parametr n - liczb� 3.
    Obiekt oceny jest instancj� w�a�nie tej klasy.*/
    cout << "Najwy�sza z oceny: " << oceny.max() << endl;
    cout << "Najni�sza z oceny: " << oceny.min() << endl;
    cout << "Srednia ocen: " << oceny.srednia() << endl;
    return 0;
}