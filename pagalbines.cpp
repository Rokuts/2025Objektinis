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