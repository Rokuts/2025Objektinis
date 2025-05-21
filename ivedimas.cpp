#include "ivedimas.h"
#include "pagalbines.h"

void vardo_pavardes_ivedimas(vector<studentas> &S, studentas &s, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    cout << "Iveskite " << S.size() + 1 << "-o studento varda ir pavarde arba 'NE' jeigu nebera daugiau studentu." << endl;
    cin >> s.vardas;
    while (!ar_tik_raides(s.vardas))
    {
        cout << "!!!Rasta klaida!!! Bandykite ivesti varda dar karta." << endl;
        cin >> s.vardas;
    }

    if(s.vardas=="NE"){         //Nebeivedinejame vardu ir pavardziu kai bent vienas yra = NE;
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
        cout<<"Iveskite studento namu darbu pazymius. Pabaigus juos vardyt, parasykit '-1'."<<endl;
        while (true) {
            int pazimys = gauti_skaiciu("", 1, 10, true);
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

void generuojama_viskas(vector<studentas> &S, int &ilgiausias_vardas, int &ilgiausia_pavarde)
{
    int studentu_kiekis=gauti_skaiciu("Iveskite kiek studentu norite sugeneruoti.", 0, numeric_limits<int>::max());
    int pazymiu_kiekis=gauti_skaiciu("Iveskite kiek pazymiu norite sugeneruoti.", 0, numeric_limits<int>::max());
    for(int i=0;i<studentu_kiekis;i++){
        studentas s;     //vienas studentas kuri siuo metu ivedame apsirasom;
        //---------------------------------------------------------------------------------------------------------------------------
        //Sugeneruojami vardai ir pavardes;
        
        s.vardas=atsitiktine_zodis(vardai);
        s.pavarde=atsitiktine_zodis(pavardes);

        ilgiausias_vardas = max(ilgiausias_vardas, (int)s.vardas.size());  // Vardo ilgis
        ilgiausia_pavarde = max(ilgiausia_pavarde, (int)s.pavarde.size()); // Pavardes ilgis

        //--------------------------------------------------------------------------------------------------------------------------
        //Sugeneruojame pazymius;
        for(int i=0; i<pazymiu_kiekis;i++){
            s.n.push_back(atsitiktinis_skaicius(1,10));
        }
        //Sugeneruojam egzo pazymi;
        s.egzas = atsitiktinis_skaicius(1,10);
        S.push_back(s);     //viena studenta itrauke i studentus;
    }
}

void skaitymas_is_failo(vector<studentas> &S, int &ilgiausias_vardas, int &ilgiausia_pavarde){
    
    path failas = ivesti_failo_pavadinima("Iveskite failo pavadinima:", true);
    skaitymas_is_failo_logika(S, ilgiausias_vardas, ilgiausia_pavarde, failas);
    
}

void skaitymas_is_failo_logika(vector<studentas> &S, int &ilgiausias_vardas, int &ilgiausia_pavarde, path &failas)
{
    ifstream ivestis;

    ivestis.exceptions(ifstream::failbit | ifstream::badbit); // Ijungia exceptions failo atidarymui
    try
    {
        ivestis.open(failas);
    }
    catch (const std::ifstream::failure &e)
    {
        cout << "Toksai failas nerastas!!!" << endl;
        return;
    }
    ivestis.exceptions(0); // Isjungia exceptions failo atidarymui

    string eilute;
    getline(ivestis, eilute);

    while (getline(ivestis, eilute))
    {
        stringstream iss(eilute);
        studentas naujas;
        int paz;

        if (!(iss >> naujas.vardas >> naujas.pavarde))
        {
            cout << "Netinkamas duomenų formatas eilutėje: " << eilute << endl;
            continue;
        }

        while (iss >> paz)
        {
            naujas.n.push_back(paz);
        }

        // Bent vienas pazymys yra
        if (!naujas.n.empty())
        {
            naujas.egzas = naujas.n.back(); // Last value is the exam
            naujas.n.pop_back();            // Remove exam from grades
        }
        else
        {
            naujas.egzas = 0; // Default exam grade if none found
        }

        // Track longest name lengths
        ilgiausias_vardas = max(ilgiausias_vardas, (int)naujas.vardas.length());
        ilgiausia_pavarde = max(ilgiausia_pavarde, (int)naujas.pavarde.length());

        // Add student to the list
        S.push_back(naujas);
    }

    ivestis.close();
    cout << "Duomenys sekmingai nuskaityti!" << endl;
    ;
}

