#include "headers.h"

struct studentas{
    string vardas, pavarde;
    int egzas;
    vector<int> n;

};

double vidurkis(studentas *s){       //funkcija balui su vidurkiu skaiciavimas
    double vidurkis=0;
    for(int i=0; i<s->n.size();i++){
        vidurkis += s->n[i];
    }
    vidurkis = vidurkis/s->n.size();
    
    return vidurkis * 0.4 + (s->egzas * 0.6);
}

double mediana(studentas *s){        //funkcija  balui su mediana skaiciavimas
    double mediana;
    int x=s->n.size();
    sort(s->n.begin(),s->n.end());
    if(x%2==0)
        mediana = (s->n[x/2]+s->n[x/2-1])/2;
    else mediana = (s->n[x/2]);
    return mediana * 0.4 + (s->egzas * 0.6);
}

int main()
{
    vector<studentas> S;    //visi studentai

    int ilgiausias_vardas=6, ilgiausia_pavarde=7;       // vardas 6 pavarde 7, nes jeigu butu trumpesnis nei stulpelio pavadinimas kad nesusilietu;
    
    
    while(true){
        //Ivedinejame studentu vardus ir pavardes tol kol ivedamas NE.
        //---------------------------------------------------------------------------------------------------------------------------
        studentas s;       //vienas studentas kuri siuo metu ivedame apsirasom;
        cout << "Iveskite " << S.size()+1 << "-o studento varda ir pavarde arba 'NE' jeigu nebera daugiau studentu." << endl;
        cin >> s.vardas;
        if(s.vardas=="NE")
            break;
        cin >> s.pavarde;
        if(s.pavarde=="NE")
            break;

        ilgiausias_vardas = max(ilgiausias_vardas, (int)s.vardas.size());     //Vardo ilgis
        ilgiausia_pavarde = max(ilgiausia_pavarde, (int)s.pavarde.size());    //Pavardes ilgis

        //Ivedinejame pazymius
        cout << "Iveskite studento namu darbu pazymius. Pabaigus juos vardyt, parasykite '-1'." << endl;
        while(true){
            int pazimys;
            cin >> pazimys;
            if(pazimys == -1)
                break;
            s.n.push_back(pazimys);
        }

        cout << "Koks sio studento egzamino rezultatas?" << endl;
        cin >> s.egzas;
        cout << endl;

        S.push_back(s);     //viena studenta itrauke i studentus;
    }

    int t;
    cout << "Jei lenteleje norite galutinio vidurkio spauskite 0, jei medianos - 1" << endl;
    cin >> t;
    cout << endl; 

    if(t==0){
        cout << left << setw(ilgiausia_pavarde + 3) << "Pavarde" << setw(ilgiausias_vardas + 3) << "Vardas" << setw(17) << "Galutinis (Vid.)" << endl;
    }
    else cout << left << setw(ilgiausia_pavarde + 3) << "Pavarde" << setw(ilgiausias_vardas + 3) << "Vardas" << setw(17) << "Galutinis (med.)" << endl;

    
    for(int i = 0; i < (ilgiausia_pavarde+ilgiausias_vardas+6+17); i++){        //pridetu pakankamai "-", kad gerai atrodytu lentele;
        cout<<"-";
    }
    cout << endl;

    for(int i = 0; i < S.size(); i++){
        if(t==0){
            cout << left << setw(ilgiausia_pavarde + 3) << S[i].pavarde << setw(ilgiausias_vardas + 3) << S[i].vardas << setw(17) << vidurkis(&S[i]) << endl;
        }
        else cout << left << setw(ilgiausia_pavarde + 3) << S[i].pavarde << setw(ilgiausias_vardas + 3) << S[i].vardas << setw(17) << mediana(&S[i]) << endl;
    }


    return 0;
}