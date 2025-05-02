#include "headers.h"

struct studentas{
    string vardas, pavarde;
    int egzas;
    vector<int> n;

};
struct apskaiciuotas_studentas{
    studentas studentas;
    double vidurkis;
    double mediana;
};

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

double vidurkis(studentas *s){       //funkcija balui su vidurkiu skaiciavimas
    if (s->n.size() == 0) 
        return s->egzas * 0.6;  // Jei tarpiniu pazimiu nera, tai isvedamas balas su egzamino pazimiu;
    
    double vidurkis=0;
    for(int i=0; i<s->n.size();i++){
        vidurkis += s->n[i];
    }
    vidurkis = vidurkis/s->n.size();
    
    return vidurkis * 0.4 + (s->egzas * 0.6);
}

double mediana(studentas *s){        //funkcija  balui su mediana skaiciavimas
    if (s->n.size() == 0) 
        return s->egzas*0.6;    //Jei tarpiniu pazimiu nera, tai isvedamas balas su egzamino pazimiu;
    
    double mediana;
    int x=s->n.size();
    sort(s->n.begin(),s->n.end());
    if(x%2==0)
        mediana = (s->n[x/2]+s->n[x/2-1])/2;
    else mediana = (s->n[x/2]);
    return mediana * 0.4 + (s->egzas * 0.6);
}

//Konvertuoja studenta i apskaiciuota studenta
apskaiciuotas_studentas apskaiciuoti_stud(studentas stud){
    apskaiciuotas_studentas S;
    S.studentas = stud;
    S.vidurkis = vidurkis(&stud);
    S.mediana = mediana(&stud);
    return S;
    
}

static const vector<string> vardai = {

    "Dominykas", "Deividas", "Matas", "Lukas", "Nojus",
    "Erikas", "Danielis", "Tomas", "Mindaugas", "Edvinas",
    "Gabrielius", "Martynas", "Mantas", "Azuolas", "Benas"
};

static const vector<string> pavardes = {

    "Kazlauskas", "Petrauskas", "Jankauskas", "Antanaitis", "Baksys",
    "Balciunas", "Baranauskas", "Bartkus", "Dambrauskas", "Gudauskas",
    "Kavaliauskas", "Kazakevicius", "Lukauskas", "Maciulis", "Navickas",
    "Paulauskas", "Rutkauskas", "Simkus", "Urbonas", "Valentukevicius"
};

string atsitiktine_zodis(const vector<string> &zodynas){
    return zodynas[atsitiktinis_skaicius(0,zodynas.size()-1)];
}

int gauti_skaiciu(string zinute, int min = 1, int max = 10, bool minus1 = false){
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

void skaitymas_is_failo(vector<studentas> &S, int &ilgiausias_vardas, int &ilgiausia_pavarde){
    path failas;
    
    cout<<"Is kokio failo norite isvesti duomenis?"<<endl;
    cin>>failas;
    
    ifstream ivestis;

    ivestis.exceptions(ifstream::failbit | ifstream::badbit); // Ijungia exceptions failo atidarymui
    try {
        ivestis.open(failas);
    } catch (const std::ifstream::failure& e) {
        cout << "Toksai failas nerastas!!!"<< endl;
        return;
    }
    ivestis.exceptions(0); // Isjungia exceptions failo atidarymui
    
    string eilute;
    getline(ivestis,eilute);

    while (getline(ivestis, eilute)) {
        stringstream iss(eilute);
        studentas naujas;
        int paz;
        
        if (!(iss >> naujas.vardas >> naujas.pavarde)) {
            cout << "Netinkamas duomenų formatas eilutėje: " << eilute << endl;
            continue;
        }

        
        while (iss >> paz) {
            naujas.n.push_back(paz);
        }

        // Bent vienas pazymys yra
        if (!naujas.n.empty()) {
            naujas.egzas = naujas.n.back();  // Last value is the exam
            naujas.n.pop_back();  // Remove exam from grades
        } else {
            naujas.egzas = 0;  // Default exam grade if none found
        }

        // Track longest name lengths
        ilgiausias_vardas = max(ilgiausias_vardas, (int)naujas.vardas.length());
        ilgiausia_pavarde = max(ilgiausia_pavarde, (int)naujas.pavarde.length());

        // Add student to the list
        S.push_back(naujas);
    }

    ivestis.close();
    cout << "Duomenys sekmingai nuskaityti!"<<endl;;


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


