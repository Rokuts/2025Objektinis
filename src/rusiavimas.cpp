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

// 1 strategija: Perkėlimas į du naujus konteinerius ('vargšiukai' ir 'kietiakiai')
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
            vargsiukai.push_back(std::move(*it));
            it = S.erase(it);
        } else {
            ++it;
        }
    }
}

// 3 strategija. (1 strategijos optimizavimas)
void skaidyti_strategija3_vector(const Container(apskaiciuotas_studentas)& A_S, Container(const apskaiciuotas_studentas*)& vargsiukai, Container(const apskaiciuotas_studentas*)& kietiakiai, bool naudoti_vidurki)
{
    // Ši realizacija naudoja std::partition_copy efektyviai įgyvendinant 1 strategiją
    vargsiukai.clear();
    kietiakiai.clear();

    auto kriterijus_func = [&](const apskaiciuotas_studentas& s) {
        return naudoti_vidurki ? s.vidurkis : s.mediana;
    };

    // Naudojame partition_point, nes S jau surūšiuotas pagal kriterijų
    auto partition_point = std::partition_point(A_S.begin(), A_S.end(), [&](const apskaiciuotas_studentas& s) {
        return kriterijus_func(s) < 5.0;
    });

    for (auto it = A_S.begin(); it != partition_point; ++it) {
        vargsiukai.push_back(&(*it));
    }
    for (auto it = partition_point; it != A_S.end(); ++it) {
        kietiakiai.push_back(&(*it));
    }
}
