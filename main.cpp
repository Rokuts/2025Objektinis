#include "headers.h"

struct studentas{
    string vardas, pavarde;
    int egzas;
    vector<int> n;

};

bool ar_tik_raides(const string& zodis) {
    for (char simbolis : zodis) {
        if (!isalpha(simbolis)) {
            return false;
        }
    }
    return true;
}

double vidurkis(studentas *s){       //funkcija balui su vidurkiu skaiciavimas
    if (s->n.size() == 0) 
        return s->egzas * 0.6;  // Jei tarpiniu pazimiu nera, tai isvedamas balas su egzamino pazimiu;
    
    double vidurkis=0;
    for(int i=0; i<s->n.size();i++){
        vidurkis += s->n[i];
    }
    vidurkis = vidurkis/s->n.size();
    
    return vidurkis * 0.4 + (s->egzas * 0.6);
}

double mediana(studentas *s){        //funkcija  balui su mediana skaiciavimas
    if (s->n.size() == 0) 
        return s->egzas;  
    
    double mediana;
    int x=s->n.size();
    sort(s->n.begin(),s->n.end());
    if(x%2==0)
        mediana = (s->n[x/2]+s->n[x/2-1])/2;
    else mediana = (s->n[x/2]);
    return mediana * 0.4 + (s->egzas * 0.6);
}

int main(){
    vector<studentas> S;    //visi studentai

    int ilgiausias_vardas=6, ilgiausia_pavarde=7;       // vardas 6 pavarde 7, nes jeigu butu trumpesnis nei stulpelio pavadinimas kad nesusilietu;
    
    
    while(true){
        //---------------------------------------------------------------------------------------------------------------------------
        //Ivedinejame studentu vardus ir pavardes tol kol ivedamas NE.

        studentas s;       //vienas studentas kuri siuo metu ivedame apsirasom;
        cout << "Iveskite " << S.size()+1 << "-o studento varda ir pavarde arba 'NE' jeigu nebera daugiau studentu." << endl;
        cin >> s.vardas;

        if(s.vardas=="NE") break;
        if(!ar_tik_raides(s.vardas)){
            cout<<"!!!Rasta klaida!!! Bandykite dar karta."<<endl;
            continue;
        }
        
        cin >> s.pavarde;
        if(s.pavarde=="NE") break;
        if(!ar_tik_raides(s.pavarde)){
            cout<<"!!!Rasta klaida!!! Bandykite dar karta."<<endl;
            continue;
        }

        ilgiausias_vardas = max(ilgiausias_vardas, (int)s.vardas.size());     //Vardo ilgis
        ilgiausia_pavarde = max(ilgiausia_pavarde, (int)s.pavarde.size());    //Pavardes ilgis

        //--------------------------------------------------------------------------------------------------------------------------
        //Ivedinejame pazymius
        cout << "Iveskite studento namu darbu pazymius. Pabaigus juos vardyt, parasykite '-1'." << endl;
        while (true) {
            int pazimys;
            cin >> pazimys;

            if (cin.fail()) {  
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                cout << "!!!Klaida. Ivestas neteisingas simbolis. Iveskite skaiciu tarp 1 ir 10 arba '-1' jei norite baigti." << endl;
                continue;  
            }

            if (pazimys == -1) break;
            if (pazimys < 1 || pazimys > 10) {
                cout << "!!!Klaida. Pazymys turi buti tarp 1 ir 10!!!" << endl;
                continue;
            }

            s.n.push_back(pazimys);
        }

        while (true) {
            cout << "Iveskite studento egzamino pazymi:" << endl;
            cin >> s.egzas;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "!!!Klaida. Egzamino rezultatas turi buti skaicius. Bandykite dar karta." << endl;
            } 
            else if (s.egzas < 1 || s.egzas > 10) {
                cout << "!!!Klaida. Egzamino pazymys turi buti tarp 1 ir 10!!!" << endl;
            } 
            else break;
            
        }

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
            cout << left << setw(ilgiausia_pavarde + 3) << S[i].pavarde << setw(ilgiausias_vardas + 3) << S[i].vardas << setw(17) << fixed << setprecision(2) << vidurkis(&S[i]) << endl;
        }
        else cout << left << setw(ilgiausia_pavarde + 3) << S[i].pavarde << setw(ilgiausias_vardas + 3) << S[i].vardas << setw(17) << fixed << setprecision(2)<< mediana(&S[i]) << endl;
    }


    return 0;
}