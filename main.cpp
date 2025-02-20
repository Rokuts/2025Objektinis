#include "headers.h"
#include "main.h"

struct studentas{
    string vardas, pavarde;
    int egzas;
    vector<int> n;

};

int atsitiktinis_skaicius(int min, int max) {
    int range = max - min + 1;
    return min + rand() % range;
}

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





int gauti_skaiciu(string zinute, int min = 1, int max = 10, bool minus1 = false){
    int skaicius;
    while (true) {
        cout << zinute <<endl;
        cin >> skaicius;

        if (cin.fail()) { 
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaida!!! Netinkama ivestis. Bandykite dar karta"<<endl;
        } 
        else if (minus1 && skaicius == -1) {
            return skaicius;
        } 
        else if (skaicius < min || skaicius > max){
            cout << "Klaida!!! Iveskite skaiciu nuo " << min << " iki " << max << ". Bandykite dar karta"<<endl;
        }    
        else {
            return skaicius;
        }
    }

}

void vardo_pavardes_ivedimas(vector<studentas> &S, studentas &s, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    cout << "Iveskite " << S.size() + 1 << "-o studento varda ir pavarde arba 'NE' jeigu nebera daugiau studentu." << endl;
    cin >> s.vardas;
    while (!ar_tik_raides(s.vardas))
    {
        cout << "!!!Rasta klaida!!! Bandykite ivesti varda dar karta." << endl;
        cin >> s.vardas;
    }

    if(s.vardas=="NE"){
        s.pavarde = "NE";
        return;
    }

    cin >> s.pavarde;
    while (!ar_tik_raides(s.pavarde))
    {
        cout << "!!!Rasta klaida!!! Bandykite ivesti pavarde dar karta." << endl;
        cin >> s.pavarde;
    }

    ilgiausias_vardas = max(ilgiausias_vardas, (int)s.vardas.size());  // Vardo ilgis
    ilgiausia_pavarde = max(ilgiausia_pavarde, (int)s.pavarde.size()); // Pavardes ilgis
}

void ivedimas_ranka(vector<studentas> &S, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    while(true){
        studentas s;     //vienas studentas kuri siuo metu ivedame apsirasom;
        //---------------------------------------------------------------------------------------------------------------------------
        //Ivedinejame studentu vardus ir pavardes tol kol ivedamas NE.

        vardo_pavardes_ivedimas(S, s, ilgiausias_vardas, ilgiausia_pavarde);
        if(s.vardas=="NE"||s.pavarde=="NE") break;

        //--------------------------------------------------------------------------------------------------------------------------
        //Ivedinejame pazymius
        while (true) {
            int pazimys = gauti_skaiciu("Iveskite studento namu darbu pazymius. Pabaigus juos vardyt, parasykit '-1'.", 1, 10, true);
            if (pazimys == -1) break;
            s.n.push_back(pazimys);
        }
        s.egzas = gauti_skaiciu("Iveskite studento egzamino pazymi:");
        S.push_back(s);     //viena studenta itrauke i studentus;
    }
}

void generuojami_pazymiai(vector<studentas> &S, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    while(true){
        studentas s;     //vienas studentas kuri siuo metu ivedame apsirasom;
        //---------------------------------------------------------------------------------------------------------------------------
        //Ivedinejame studentu vardus ir pavardes tol kol ivedamas NE.

        vardo_pavardes_ivedimas(S, s, ilgiausias_vardas, ilgiausia_pavarde);
        if(s.vardas=="NE"||s.pavarde=="NE") break;

        //--------------------------------------------------------------------------------------------------------------------------
        //Sugeneruojame pazymius;
        int pazymiu_kiekis=gauti_skaiciu("Iveskite kiek pazymiu norite sugeneruoti.", 0, numeric_limits<int>::max());
        for(int i=0; i<pazymiu_kiekis;i++){
            s.n.push_back(atsitiktinis_skaicius(1,10));
        }
        s.egzas = atsitiktinis_skaicius(1,10);
        S.push_back(s);     //viena studenta itrauke i studentus;
    }
}





void lentele(int ilgiausia_pavarde, int ilgiausias_vardas, vector<studentas> &S)
{
    int t;
    cout << "Jei lenteleje norite galutinio vidurkio spauskite 0, jei medianos - 1" << endl;
    cin >> t;
    cout << endl;

    if (t == 0)
    {
        cout << left << setw(ilgiausia_pavarde + 3) << "Pavarde" << setw(ilgiausias_vardas + 3) << "Vardas" << setw(17) << "Galutinis (Vid.)" << endl;
    }
    else
        cout << left << setw(ilgiausia_pavarde + 3) << "Pavarde" << setw(ilgiausias_vardas + 3) << "Vardas" << setw(17) << "Galutinis (med.)" << endl;

    for (int i = 0; i < (ilgiausia_pavarde + ilgiausias_vardas + 6 + 17); i++)
    { // pridetu pakankamai "-", kad gerai atrodytu lentele;
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < S.size(); i++)
    {
        if (t == 0)
        {
            cout << left << setw(ilgiausia_pavarde + 3) << S[i].pavarde << setw(ilgiausias_vardas + 3) << S[i].vardas << setw(17) << fixed << setprecision(2) << vidurkis(&S[i]) << endl;
        }
        else
            cout << left << setw(ilgiausia_pavarde + 3) << S[i].pavarde << setw(ilgiausias_vardas + 3) << S[i].vardas << setw(17) << fixed << setprecision(2) << mediana(&S[i]) << endl;
    }
}

void meniu()
{
    cout << "Pasirinkite ivedimo rezima:" << endl;
    cout << "1. Ivedimas ranka;" << endl;
    cout << "2. Generuoti pazymius;" << endl;
    cout << "3. Generuoti pazymius, vardus, pavardes;" << endl;
    cout << "4. Baigti darba." << endl;
}

int main(){

    vector<studentas> S; // visi studentai

    int ilgiausias_vardas=6, ilgiausia_pavarde=7;       // vardas 6 pavarde 7, nes jeigu butu trumpesnis nei stulpelio pavadinimas kad nesusilietu;

    meniu();
    int pasirinkimas;
    pasirinkimas = gauti_skaiciu("Iveskite norima varianta.", 1, 4);
    switch(pasirinkimas){
        case 1:
            ivedimas_ranka(S, ilgiausias_vardas, ilgiausia_pavarde);
            break; 
        case 2:
            generuojami_pazymiai(S, ilgiausias_vardas, ilgiausia_pavarde);
            break;
        case 3:

            break;


    }
    
    
    
        
    lentele(ilgiausia_pavarde, ilgiausias_vardas, S);

    return 0;
}


