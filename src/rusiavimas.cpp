#include "rusiavimas.h"

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

void kaip_rusiuojam_ir_rusiuojam(Container(apskaiciuotas_studentas) &S){
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

    sort_pagal_pasirinkima(pasirinkimas, S);
}

void sort_pagal_pasirinkima(int pasirinkimas, Container(apskaiciuotas_studentas) &S)
{
    
    switch (pasirinkimas)
    {
    case 1:
        Container_sort(S, compareByVardas);
        break;
    case 2:
        Container_sort(S, compareByPavarde);
        break;
    case 3:
        Container_sort(S, compareByVidurkis);
        break;
    case 4:
        Container_sort(S, compareByMediana);
        break;
    }

}

void skaidyti_studentus(Container(apskaiciuotas_studentas) &S, Container(const apskaiciuotas_studentas*) &vargsiukai, Container(const apskaiciuotas_studentas*) &kietiakiai, bool naudoti_vidurki)
{
    for (const auto& studentas : S) {
        if (naudoti_vidurki) {
            if (studentas.vidurkis < 5.0) {
                vargsiukai.push_back(&studentas);
            }
            else {
                kietiakiai.push_back(&studentas);
            }
        }
        else {
            if (studentas.mediana < 5.0) {
                vargsiukai.push_back(&studentas);
            }
            else {
                kietiakiai.push_back(&studentas);
            }
        }
    }
}

// 2 strategija: Perkėlimas ir trynimas į vieną naują konteinerį ('vargšiukai')
void skaidyti_strategija2(Container(apskaiciuotas_studentas) &S, Container(apskaiciuotas_studentas) &vargsiukai, bool naudoti_vidurki) {
    auto it = S.begin();
    while (it != S.end()) {
        bool yra_vargsiukas;
        if (naudoti_vidurki) {
            yra_vargsiukas = it->vidurkis < 5.0;
        } else {
            yra_vargsiukas = it->mediana < 5.0;
        }

        if (yra_vargsiukas) {
            vargsiukai.push_back(move(*it));
            it = S.erase(it);
        } else {
            ++it;
        }
    }
}
