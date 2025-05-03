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