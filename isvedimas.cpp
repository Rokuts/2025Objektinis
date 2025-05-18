#include "isvedimas.h"
#include "rusiavimas.h"
#include "pagalbines.h"
#include "apskaiciuotas_studentas.h"

template <typename Container, typename Getter>
void lentele_universali(int ilgiausia_pavarde, int ilgiausias_vardas, const Container& S, ostream& isvestis, Getter get_ref, bool ar_rodyti_vidurki)
{
    if (ar_rodyti_vidurki)
        isvestis << left << setw(ilgiausia_pavarde + 3) << "Pavarde" << setw(ilgiausias_vardas + 3) << "Vardas" << setw(17) << "Galutinis (Vid.)" << endl;
    else
        isvestis << left << setw(ilgiausia_pavarde + 3) << "Pavarde" << setw(ilgiausias_vardas + 3) << "Vardas" << setw(17) << "Galutinis (med.)" << endl;

    for (int i = 0; i < (ilgiausia_pavarde + ilgiausias_vardas + 6 + 17); i++)
        isvestis << "-";
    isvestis << endl;

    for (size_t i = 0; i < S.size(); i++) {
        const auto& stud = get_ref(S[i]);
        if (ar_rodyti_vidurki)
            isvestis << left << setw(ilgiausia_pavarde + 3) << stud.studentas.pavarde << setw(ilgiausias_vardas + 3) << stud.studentas.vardas << setw(17) << fixed << setprecision(2) << stud.vidurkis << endl;
        else
            isvestis << left << setw(ilgiausia_pavarde + 3) << stud.studentas.pavarde << setw(ilgiausias_vardas + 3) << stud.studentas.vardas << setw(17) << fixed << setprecision(2) << stud.mediana << endl;
    }
}

void lentele(int ilgiausia_pavarde, int ilgiausias_vardas, vector<apskaiciuotas_studentas> &S, ostream &isvestis, bool ar_rodyti_vidurki)       //lentele kopijoms;
{
    lentele_universali(ilgiausia_pavarde, ilgiausias_vardas, S, isvestis, [](const auto& stud) { return stud; }, ar_rodyti_vidurki);
}

void lentele(int ilgiausia_pavarde, int ilgiausias_vardas, vector<const apskaiciuotas_studentas*> &S, ostream &isvestis, bool ar_rodyti_vidurki)    //lentele rodyklėms;
{
    lentele_universali(ilgiausia_pavarde, ilgiausias_vardas, S, isvestis, [](const auto& stud) { return *stud; }, ar_rodyti_vidurki);
}

void isvedimas_i_ekrana(int ilgiausia_pavarde, int ilgiausias_vardas, vector<studentas> &S){
    vector<apskaiciuotas_studentas> A_S;
    A_S.reserve(S.size());
    for(const auto &s: S){
        A_S.push_back(apskaiciuoti_stud(s));
    }
    kaip_rusiuojam_ir_rusiuojam(A_S);
    lentele(ilgiausia_pavarde, ilgiausias_vardas, A_S, cout, paklausiam_ar_rodyti_vidurki());
}

void isvedimas_i_faila(int ilgiausia_pavarde, int ilgiausias_vardas, vector<studentas> &S){
    
    path failas;        //deklaruojame kintamaji;
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
    for(const auto &s: S){      //pereina per visus studentus s esancius studentu sarase S;
        A_S.push_back(apskaiciuoti_stud(s));
    }
    kaip_rusiuojam_ir_rusiuojam(A_S);
    lentele(ilgiausia_pavarde,ilgiausias_vardas,A_S,isvestis, paklausiam_ar_rodyti_vidurki());
    isvestis.close();

}

void skaidymas_ir_isvedimas_i_du_failus(int ilgiausia_pavarde, int ilgiausias_vardas, vector<studentas> &S)
{
    path failas1, failas2;
    while(true){
       
        cout<<"I koki faila norite isvesti vargsiukus?"<<endl;
        cin>>failas1;
       
        if(fs_exists(failas1)){
            cout<<"Toksai failas jau egzistuoja, iveskite kita pavadinima;"<<endl;
            continue;
        }
        break;
    }
    while(true){
       
        cout<<"I koki faila norite isvesti kietiakus?"<<endl;
        cin>>failas2;
       
        if(fs_exists(failas2)){
            cout<<"Toksai failas jau egzistuoja, iveskite kita pavadinima;"<<endl;
            continue;
        }
        break;
    }

    int pasirinkimas;
    pasirinkimas = gauti_skaiciu("Studentus skirstyti pagal vidurki ar mediana? (0 - vidurki, 1 - mediana)", 0, 1);

    vector<apskaiciuotas_studentas> A_S;
    A_S.reserve(S.size());
    for(const auto &s: S){
        A_S.push_back(apskaiciuoti_stud(s));
    }

    vector<const apskaiciuotas_studentas*> vargsiukai;
    vector<const apskaiciuotas_studentas*> kietiakai;

    
    skaidyti_studentus(A_S, vargsiukai, kietiakai, !pasirinkimas);

    ofstream isvestis1(failas1);
    ofstream isvestis2(failas2);

    bool ar_rodyti_vidurki = paklausiam_ar_rodyti_vidurki();
    lentele(ilgiausia_pavarde, ilgiausias_vardas, vargsiukai, isvestis1, ar_rodyti_vidurki);
    lentele(ilgiausia_pavarde, ilgiausias_vardas, kietiakai, isvestis2, ar_rodyti_vidurki);

    isvestis1.close();
    isvestis2.close();

}