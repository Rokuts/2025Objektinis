#include "pagalbines.h"

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

string atsitiktine_zodis(const vector<string> &zodynas){
    return zodynas[atsitiktinis_skaicius(0,zodynas.size()-1)];
}

int gauti_skaiciu(string zinute, int min, int max, bool minus1){
    int skaicius;
    
    while (true) {
        if(!minus1)                 //isjungia zinuciu spauzdinima 
            cout << zinute <<endl;
        cin >> skaicius;

        if (cin.fail()) {           //trikriname ar ivedamas skaicius
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Klaida!!! Netinkama ivestis. Bandykite dar karta"<<endl;
        } 
        else if (minus1 && skaicius == -1) {
            return skaicius;
        } 
        else if (skaicius < min || skaicius > max){         //tikriname ar skaicius yra tinkamame intervale;
            cout << "Klaida!!! Iveskite skaiciu nuo " << min << " iki " << max << ". Bandykite dar karta"<<endl;
        }    
        else {
            return skaicius;
        }
    }

}

void surinkti_generavimo_duomenis(path& failas, int& studentu_kiekis, int& pazymiu_kiekis, int& pavarde_w, int& vardas_w) {
    
    failas = ivesti_failo_pavadinima("Iveskite failo pavadinima:", false); //ivesti failo pavadinima;

    studentu_kiekis = gauti_skaiciu("Iveskite kiek studentu norite sugeneruoti.", 0, numeric_limits<int>::max());
    pazymiu_kiekis = gauti_skaiciu("Iveskite kiek pazymiu norite sugeneruoti.", 0, numeric_limits<int>::max());

    pavarde_w = 20;     //stulpeliu ilgiai, kad butu graziai isdestyta;
    vardas_w = 15;
    double studentu_sk_kiekis = log10(static_cast<double>(studentu_kiekis));        //log10 studentu skaicius, kad gauti kiek reikia vietos isvedimui;
    int apvalintas_sk_kiekis = static_cast<int>(ceil(studentu_sk_kiekis));          //apvaliname iki sveiko skaiciaus i didesne puse(ceil);
    pavarde_w += apvalintas_sk_kiekis;      //pridedame prie pavardes stulpelio ilgio, kad tilptu studento numeris;
    vardas_w += apvalintas_sk_kiekis;       //pridedame prie vardo stulpelio ilgio, kad tilptu studento numeris;
}

void generuoti_faila_logika(const path& failas, int studentu_kiekis, int pazymiu_kiekis, int pavarde_w, int vardas_w) {
    ofstream isvestis(failas);
    if (!isvestis) {
        cout << "Nepavyko atidaryti failo." << endl;
        return;
    }
    isvestis << left << setw(vardas_w) << "Vardas" << setw(pavarde_w) << "Pavarde";
    for (int i = 0; i < pazymiu_kiekis; i++) {
        isvestis << setw(5) << ("ND" + to_string(i + 1));
    }
    isvestis << setw(5) << "Egz." << endl;

    mt19937 gen(system_clock::now().time_since_epoch().count());    //inicelizuojame RNG remiantis dabartiniu laiku as our seed.
    uniform_int_distribution<> pazymiai_dist(1, 10);     //sukuriame RNG paskirstymas, kad gauti skaicius nuo 1 iki 10.

    for (int i = 0; i < studentu_kiekis; i++) {
        string vardas = atsitiktine_zodis(vardai);
        string pavarde = atsitiktine_zodis(pavardes);
        isvestis << left << setw(vardas_w) << (vardas + to_string(i + 1))
                 << setw(pavarde_w) << (pavarde + to_string(i + 1));
        for (int j = 0; j < pazymiu_kiekis; j++) {
            isvestis << setw(5) << pazymiai_dist(gen);
        }
        isvestis << setw(5) << pazymiai_dist(gen) << endl;  // egzamino pazymys;
    }
}
void generuoti_faila() {
    path failas;
    int studentu_kiekis, pazymiu_kiekis, pavarde_w, vardas_w;
    surinkti_generavimo_duomenis(failas, studentu_kiekis, pazymiu_kiekis, pavarde_w, vardas_w);

    auto pradzia = high_resolution_clock::now();
    generuoti_faila_logika(failas, studentu_kiekis, pazymiu_kiekis, pavarde_w, vardas_w);
    auto pabaiga = high_resolution_clock::now();
    auto trukme = duration<double>(pabaiga - pradzia);
    cout << "Trukme: " << trukme.count() << " seconds" << endl;
}

bool paklausiam_ar_rodyti_vidurki()
{
    int pasirinkimas;
    pasirinkimas = gauti_skaiciu("Norite vidurkio ar medianos? (0 - vidurkis, 1 - mediana)?", 0, 1);
    return pasirinkimas == 0;
}

path ivesti_failo_pavadinima(const string& uzklausa, bool turi_egzistuoti) {
    path failas;
    while (true) {
        cout << uzklausa;
        cin >> failas;
        if (turi_egzistuoti && !fs_exists(failas)) {
            cout << "Toks failas neegzistuoja, bandykite dar kartą." << endl;
        } else if (!turi_egzistuoti && fs_exists(failas)) {
            cout << "Toks failas jau egzistuoja, įveskite kitą pavadinimą." << endl;
        } else {
            break;
        }
    }
    return failas;
}

void laiko_tyrimas()
{
    path nuskaitymo_failas = ivesti_failo_pavadinima("Is kokio failo norite nuskaityti?:", true);
    path vargsiuku_failas = ivesti_failo_pavadinima("Iveskite failo pavadinima vargsiukams:", false);
    path kietiaku_failas = ivesti_failo_pavadinima("Iveskite failo pavadinima kietiakams:", false);
    int pasirinkimas = gauti_skaiciu("Studentus skirstyti pagal vidurki ar mediana? (0 - vidurki, 1 - mediana)", 0, 1);
    
    Container(studentas) S; // visi studentai
    int ilgiausias_vardas = 0, ilgiausia_pavarde = 0;       
    
    auto pradzia = high_resolution_clock::now();

    skaitymas_is_failo_logika(S, ilgiausias_vardas, ilgiausia_pavarde, nuskaitymo_failas);

    auto etapas1 = high_resolution_clock::now();

    Container(apskaiciuotas_studentas) A_S;
    Container_reserve(A_S, S.size());
    for (const auto &s : S)
    {
        A_S.push_back(apskaiciuoti_stud(s));
    }

    sort_pagal_pasirinkima(pasirinkimas + 3, A_S);

    auto etapas2 = high_resolution_clock::now();

    Container(const apskaiciuotas_studentas *) vargsiukai;
    Container(const apskaiciuotas_studentas *) kietiakai;

    skaidyti_studentus(A_S, vargsiukai, kietiakai, !pasirinkimas);

    auto etapas3 = high_resolution_clock::now();

    ofstream isvestis1(vargsiuku_failas);
    ofstream isvestis2(kietiaku_failas);

    lentele(ilgiausia_pavarde, ilgiausias_vardas, vargsiukai, isvestis1, pasirinkimas == 0) ;
    lentele(ilgiausia_pavarde, ilgiausias_vardas, kietiakai, isvestis2, pasirinkimas == 0);

    isvestis1.close();
    isvestis2.close();

    auto pabaiga = high_resolution_clock::now();
    auto trukme = duration<double>(pabaiga - pradzia);

    auto trukme1 = duration<double>(etapas1 - pradzia);
    auto trukme2 = duration<double>(etapas2 - etapas1);
    auto trukme3 = duration<double>(etapas3 - etapas2);
    auto trukme4 = duration<double>(pabaiga - etapas3);

    cout << "Laiko tyrimo rezultatai:" << endl;
    cout << "1. Nuskaitymas is failo: " << trukme1.count() << " seconds" << endl;
    cout << "2. Studentu rusiavimas: " << trukme2.count() << " seconds" << endl;
    cout << "3. Studentu skirstymas: " << trukme3.count() << " seconds" << endl;
    cout << "4. Studentu isvedimas i failus: " << trukme4.count() << " seconds" << endl;
    cout << "Bendras laiko tyrimo rezultatas: " << trukme.count() << " seconds" << endl;


}

void tyrimas_su_strategijom()
{
    path nuskaitymo_failas = ivesti_failo_pavadinima("Is kokio failo norite nuskaityti?:", true);
    int pasirinkimas = gauti_skaiciu("Studentus skirstyti pagal vidurki ar mediana? (0 - vidurki, 1 - mediana)", 0, 1);
    int strategijos_pasirinkimas = gauti_skaiciu("Taikyti pirma strategija (copy), ar antra strategija (move/erase)? (1 - pirma s., 2 - antra s.)", 1, 2);

    Container(studentas) S; // visi studentai
    int ilgiausias_vardas = 0, ilgiausia_pavarde = 0;

    auto pradzia = high_resolution_clock::now();
    skaitymas_is_failo_logika(S, ilgiausias_vardas, ilgiausia_pavarde, nuskaitymo_failas);
    
    Container(apskaiciuotas_studentas) A_S;
    Container_reserve(A_S, S.size());
    for (const auto &s : S)
    {
        A_S.push_back(apskaiciuoti_stud(s));
    }

    sort_pagal_pasirinkima(pasirinkimas + 3, A_S);

    if(strategijos_pasirinkimas == 1) {
        // 1 strategija;
        
        Container(const apskaiciuotas_studentas *) vargsiukai;
        Container(const apskaiciuotas_studentas *) kietiakai;
        skaidyti_studentus(A_S, vargsiukai, kietiakai, !pasirinkimas);
    } else {
        // 2 strategija;
        Container(apskaiciuotas_studentas) vargsiukai;
        skaidyti_strategija2(A_S, vargsiukai, !pasirinkimas);
    }
    auto pabaiga = high_resolution_clock::now();
    auto trukme = duration<double>(pabaiga - pradzia);
    
    
    cout << CONTAINER_NAME <<endl;
    if(strategijos_pasirinkimas == 1) {
        cout << "Naudota 1 strategija (copy)." << endl;
    } else {
        cout << "Naudota 2 strategija (move/erase)." << endl;
    }
    cout << "Laiko tyrimo rezultatas: " << trukme.count() << " seconds" << endl;
    
}