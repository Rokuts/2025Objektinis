#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;



struct studentas{
    string vardas, pavarde;
    int egzas, suma = 0;
    double n[10];
    double galutinisVid, galutinisMed;

};

double vidurkis(studentas *s, int x){
    return ((double)(s->suma))/x;
}

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

    int ilgiausias_vardas=6, ilgiausia_pavarde=7;
    for(int i = 0; i < y; i++){
        cout << "Koks " << i + 1 << "-o studento vardas ir pavarde?" << endl;
        cin >> S[i].vardas >> S[i].pavarde;
        ilgiausias_vardas = max(ilgiausias_vardas, (int)S[i].vardas.size());     //Vardo ilgis
        ilgiausia_pavarde = max(ilgiausia_pavarde, (int)S[i].pavarde.size());    //Pavardes ilgis

        cout << "Iveskite visus sio studento tarpinius rezultatus." << endl;
        for(int j = 0; j < x; j++){
            cin >> S[i].n[j];
            S[i].suma += S[i].n[j];
        }

        cout << "Koks sio studento egzamino rezultatas?" << endl;
        cin >> S[i].egzas;
        cout << endl;
    }

     
    cout << left << setw(ilgiausia_pavarde + 3) << "Pavarde" << setw(ilgiausias_vardas + 3) << "Vardas" << setw(17) << "Galutinis (Vid.)" << endl;
    
    for(int i = 0; i < (ilgiausia_pavarde+ilgiausias_vardas+6+17); i++){        //pridetu pakankamai "-", kad gerai atrodytu lentele;
        cout<<"-";
    }
    cout << endl;

    for(int i = 0; i < y; i++){
        cout << left << setw(ilgiausia_pavarde + 3) << S[i].pavarde << setw(ilgiausias_vardas + 3) << S[i].vardas << setw(17) << vidurkis(&S[i],x) << endl;
    }


    return 0;
}