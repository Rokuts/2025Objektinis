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
    while (true) {
        cout << "Kaip norite pavadinti sugeneruota faila?" << endl;
        cin >> failas;
        if (fs_exists(failas)) {
            cout << "Toksai failas jau egzistuoja, iveskite kita pavadinima;" << endl;
            continue;
        }
        break;
    }

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
    generuoti_faila_logika(failas, studentu_kiekis, pazymiu_kiekis, pavarde_w, vardas_w);
}

bool paklausiam_ar_rodyti_vidurki()
{
    int pasirinkimas;
    pasirinkimas = gauti_skaiciu("Norite vidurkio ar medianos? (0 - vidurkis, 1 - mediana)?", 0, 1);
    return pasirinkimas == 0;
}

