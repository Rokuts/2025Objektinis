#include "headers.h"
#include "studentas.h"
#include "apskaiciuotas_studentas.h"
#include "pagalbines.h"
#include "ivedimas.h"
#include "isvedimas.h"
#include "rusiavimas.h"



void lentele(int ilgiausia_pavarde, int ilgiausias_vardas, vector<apskaiciuotas_studentas> &S, ostream &isvestis)
{
    int t;
    cout << "Jei lenteleje norite galutinio vidurkio spauskite 0, jei medianos - 1" << endl;
    cin >> t;
    cout << endl;

    if (t == 0)
    {
        isvestis << left << setw(ilgiausia_pavarde + 3) << "Pavarde" << setw(ilgiausias_vardas + 3) << "Vardas" << setw(17) << "Galutinis (Vid.)" << endl;
    }
    else
        isvestis << left << setw(ilgiausia_pavarde + 3) << "Pavarde" << setw(ilgiausias_vardas + 3) << "Vardas" << setw(17) << "Galutinis (med.)" << endl;

    for (int i = 0; i < (ilgiausia_pavarde + ilgiausias_vardas + 6 + 17); i++)
    { // pridetu pakankamai "-", kad gerai atrodytu lentele;
        isvestis << "-";
    }
    isvestis << endl;

    for (int i = 0; i < S.size(); i++)
    {
        if (t == 0)
        {
            isvestis << left << setw(ilgiausia_pavarde + 3) << S[i].studentas.pavarde << setw(ilgiausias_vardas + 3) << S[i].studentas.vardas << setw(17) << fixed << setprecision(2) << S[i].vidurkis << endl;
        }
        else
            isvestis << left << setw(ilgiausia_pavarde + 3) << S[i].studentas.pavarde << setw(ilgiausias_vardas + 3) << S[i].studentas.vardas << setw(17) << fixed << setprecision(2) << S[i].mediana << endl;
    }
}

//palyginimo funkcijos:

bool compareByVidurkis(apskaiciuotas_studentas &a, apskaiciuotas_studentas &b) {
    return a.vidurkis > b.vidurkis;
}

bool compareByMediana(apskaiciuotas_studentas &a, apskaiciuotas_studentas &b) {
    return a.mediana > b.mediana;
}

bool compareByVardas(apskaiciuotas_studentas &a, apskaiciuotas_studentas &b) {
    return a.studentas.vardas < b.studentas.vardas;
}

bool compareByPavarde(apskaiciuotas_studentas &a, apskaiciuotas_studentas &b) {
    return a.studentas.pavarde < b.studentas.pavarde;
}


void kaip_rusiuojam_ir_rusiuojam(vector<apskaiciuotas_studentas> &S){
    int pasirinkimas;
    cout << "Pasirinkite rikiavimo buda:"<<endl;
    cout << "1 - Pagal varda"<<endl;
    cout << "2 - Pagal pavarde"<<endl;
    cout << "3 - Pagal vidurki"<<endl;
    cout << "4 - Pagal mediana"<<endl;
    cin >> pasirinkimas;

    while(true){
        if(pasirinkimas<1||pasirinkimas>4){
            cout << "Neteisingas pasirinkimas, bandykite dar karta."<<endl;
            cin >> pasirinkimas;
        }else break;
    }

    switch(pasirinkimas){
        case 1:
            sort(S.begin(), S.end(), compareByVardas);
            break;
        case 2:
            sort(S.begin(), S.end(), compareByPavarde);
            break;
        case 3: 
            sort(S.begin(), S.end(), compareByVidurkis);
            break;
        case 4:
            sort(S.begin(), S.end(), compareByMediana);
            break;
    }

}

void isvedimas_i_ekrana(int ilgiausia_pavarde, int ilgiausias_vardas, vector<studentas> &S){
    vector<apskaiciuotas_studentas> A_S;
    A_S.reserve(S.size());
    for(const auto &s: S){
        A_S.push_back(apskaiciuoti_stud(s));
    }
    kaip_rusiuojam_ir_rusiuojam(A_S);
    lentele(ilgiausia_pavarde, ilgiausias_vardas, A_S, cout);
}


void isvedimas_i_faila(int ilgiausia_pavarde, int ilgiausias_vardas, vector<studentas> &S){
    
    path failas;
    while(true){
       
        cout<<"I koki faila norite isvesti duomenis?"<<endl;
        cin>>failas;
       
        if(fs_exists(failas)){
            cout<<"Toksai failas jau egzistuoja, iveskite kita pavadinima;"<<endl;
            continue;
        }
        break;
    }

    
    ofstream isvestis(failas);
    vector<apskaiciuotas_studentas> A_S;
    A_S.reserve(S.size());
    for(const auto &s: S){
        A_S.push_back(apskaiciuoti_stud(s));
    }
    kaip_rusiuojam_ir_rusiuojam(A_S);
    lentele(ilgiausia_pavarde,ilgiausias_vardas,A_S,isvestis);
    isvestis.close();

}

void meniu()
{
    cout << "Pasirinkite ivedimo rezima:" << endl;
    cout << "1. Ivedimas ranka;" << endl;
    cout << "2. Generuoti pazymius;" << endl;
    cout << "3. Generuoti pazymius, vardus, pavardes;" << endl;
    cout << "4. Duomenis paimti is failo;" << endl;
    cout << "5. Isvesti duomenis i ekrana ir baigti darba" << endl;
    cout << "6. Isvesti duomenis i faila ir baigti darba" << endl;
}

int main(){
    srand (time(NULL));     //padaro jog generuojami atsitiktiniai skaiciai butu skirtingi kiekviena karta;
    
    vector<studentas> S; // visi studentai

    int ilgiausias_vardas=6, ilgiausia_pavarde=7;       // vardas 6 pavarde 7, nes jeigu butu trumpesnis nei stulpelio pavadinimas kad nesusilietu;

    while(true){
        meniu();
        int pasirinkimas;
        pasirinkimas = gauti_skaiciu("Iveskite norima varianta.", 1, 6);
        switch(pasirinkimas){
            case 1:
                ivedimas_ranka(S, ilgiausias_vardas, ilgiausia_pavarde);
                break; 
            case 2:
                generuojami_pazymiai(S, ilgiausias_vardas, ilgiausia_pavarde);
                break;
            case 3:
                generuojama_viskas(S, ilgiausias_vardas, ilgiausia_pavarde);
                break;
            case 4: 
                skaitymas_is_failo(S, ilgiausias_vardas, ilgiausia_pavarde);
                break;
            case 5: //isvesti i ekrana
                isvedimas_i_ekrana(ilgiausia_pavarde, ilgiausias_vardas, S);
                return 0;
            case 6: //isvesti i faila
                isvedimas_i_faila(ilgiausia_pavarde,ilgiausias_vardas,S);
                return 0;
        }

    }
    
    return 0;
}


