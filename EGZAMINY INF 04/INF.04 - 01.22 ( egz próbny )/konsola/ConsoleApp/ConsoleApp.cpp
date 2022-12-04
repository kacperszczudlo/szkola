
#include <iostream>

using namespace std;

class SortSelection {

    static const int n = 10;
    int numbers[n];
    int searchMax(int);

public:
    void sortNumbers();
    void inputNumbers();
    void outputNumbers();
};
/********************************************************
 nazwa funkcji: <SortSelection>
 parametry wej�ciowe: <brak> - <przechowuje zmnienn� typu int>
 warto�� zwracana: <numbers[i] - pobiera liczb� ca�kowit�>
 autor: <Kacper Szczud�o>
********************************************************/
void SortSelection::inputNumbers() {
    for (int i = 0; i < n; i++) {
        cout << "Podaj " << i << " elemnt tablicy: ";
        cin >> numbers[i];
    }
}
/********************************************************
 nazwa funkcji: <SortSelection>
 parametry wej�ciowe: <brak> - <przechowuje zmnienn� typu int>
 warto�� zwracana: <numbers[i] - zwraca liczb� ca�kowit�>
 autor: <Kacper Szczud�o>
********************************************************/
void SortSelection::outputNumbers() {
    for (int i = 0; i < n; i++) {
        cout << "Element[" << i << "] = " << numbers[i] << endl;
    }
}
/********************************************************
 nazwa funkcji: <SortSelection>
 parametry wej�ciowe: <startIndex> - <przechowuje zmnienn� typu int>
 warto�� zwracana: <maxNumberIndex - warto�� najwy�sza>
 autor: <Kacper Szczud�o>
********************************************************/
int SortSelection::searchMax(int startIndex) {
    int maxNumberIndex = startIndex;
    for (int i = startIndex + 1; i < n; i++) {
        if (numbers[i] > numbers[maxNumberIndex]) maxNumberIndex = i;
    }
    return maxNumberIndex;
}
/********************************************************
 nazwa funkcji: <SortSelection>
 parametry wej�ciowe: <brak> - <przechowuje zmnienn� typu int>
 warto�� zwracana: <temp - posortowana tablica liczb ca�kowitych>
 autor: <Kacper Szczud�o>
********************************************************/
void SortSelection::sortNumbers() {
    for (int i = 0; i < n - 1; i++) {
        int temp = numbers[i];
        int searchIndex = searchMax(i);
        numbers[i] = numbers[searchIndex];
        numbers[searchIndex] = temp;
    }
}

int main()
{
    SortSelection myArray;
    myArray.inputNumbers();
    myArray.sortNumbers();
    myArray.outputNumbers();
    return 0;
}

