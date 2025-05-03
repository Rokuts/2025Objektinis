#include "headers.h"
#include "studentas.h"
#include "apskaiciuotas_studentas.h"
#include "pagalbines.h"
#include "ivedimas.h"
#include "isvedimas.h"
#include "rusiavimas.h"

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


