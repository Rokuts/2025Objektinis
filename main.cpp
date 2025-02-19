#include <iostream>

using namespace std;

struct studentas{
    string vardas, pavarde;
    int egzas, suma = 0;
    double n[10];

};

int main()
{

    studentas S[10];
    int n, x, y, *dydis;

    cout << "Kiek yra studentu (max 10)?" << endl;
    cin >> y;
    cout << endl;

    cout << "Kiek buvo namu darbu (max 10)?" << endl;
    cin >> x;
    cout << endl;

    dydis = new int [y];      //Vardo/Pavardes ilgio masyvas

    int a, b;
    for(int i = 0; i < y; i++){
        cout << "Koks " << i + 1 << "-o studento vardas ir pavarde?" << endl;
        cin >> S[i].vardas >> S[i].pavarde;

        cout << "Iveskite visus sio studento tarpinius rezultatus." << endl;
        for(int j = 0; j < x; j++){
            cin >> S[i].n[j];
            S[i].suma += S[i].n[j];
        }

        cout << "Koks sio studento egzamino rezultatas?" << endl;
        cin >> S[i].egzas;
        cout << endl;
    }

    for(int i=0; i<y; i++){
        cout<<"Studentas: "<<S[i].vardas<<" "<<S[i].pavarde<<";"<<endl;
        cout<<"Jo pazymiai: ";
        for(int j=0; j<x; j++){
            cout<<S[i].n[j]<<" ";
        }
        cout<<endl;
        cout<<"Suma: "<<S[i].suma;
        cout<<endl;
    }

    return 0;
}