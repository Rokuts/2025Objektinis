# Objektinis programavimas

**Naudojimosi instrukcija**
-
Paleidus programą, jums bus pateiktas meniu su šiais pasirinkimais:

1. **Įvedimas ranka**  
   Vartotojas pats suveda studentų vardus, pavardes ir pažymius per terminalą.

2. **Generuoti pažymius**  
   Įvedus vardą ir pavardę, atsitiktinai sugeneruojami pažymiai.

3. **Generuoti pažymius, vardus, pavardes**  
   Visa informacija (vardas, pavardė, pažymiai) sugeneruojama automatiškai.

4. **Duomenys iš failo**  
   Įvedus failo pavadinimą, programa nuskaito studentų duomenis iš pateikto failo.

5. **Išvesti duomenis į ekraną ir baigti darbą**  
   Atvaizduoja studentų duomenis terminale ir užbaigia darbą.

6. **Išvesti duomenis į failą ir baigti darbą**  
   Išsaugo rezultatus į failą ir baigia programą.

7. **Sugeneruoti failą su studentais**  
   Sugeneruoja failą su pasirinktu studentų skaičiumi.

8. **Suskirstyti studentus į „vargšiukus“ ir „kietiakius“**  
   Pagal vidurkį ar medianą atskiria studentus į dvi grupes ir išveda į atskirus failus.

9. **Laiko tyrimas**  
   Paleidžia algoritmą su skirtingais duomenų dydžiais, matuoja veikimo laiką (nuskaitymą, rušiavimą, skirstymą, išvedimą, bendrą laiką).

10. **Tyrimas su strategijom**  
    Lygina 3 skirstymo strategijas, matuoja jų veikimo laiką su skirtingais duomenų kiekiais (nuskaitymą, rušiavimą ir skirstymą).

Pasirinkus bet kurį punktą, programa paprašys papildomos informacijos (pvz., failo pavadinimo, strategijos numerio, rūšiavimo būdo ir t. t.), o toliau veiks automatiškai pagal pasirinktą režimą.

Pries ivedant failo pavadinima pries tai reikia parasyti " ..\ " pvz. ( ..\failas.txt ).

Prieš pasirenkant 8 punktą, įsitikinkite, kad turite jau įvestų arba nuskaitytų studentų duomenų, nes ši funkcija pati nepaprašo duomenų įvedimo.

**Releasai**
-
- **v0.1:** Įvedami ir generuojami studentų duomenys (vardas, pavardė, pažymiai). Taip pat apskaičiuojamas galutinis balas naudojant vidurkį arba medianą.
- **v0.2:** Pridėtas darbas su failais. Duomenys gali būti nuskaityti iš failo ir įrašyti į failą.
- **v0.3:** Įtrauktas išimčių valdymas programos saugumui ir stabilumui užtikrinti.
- **v0.4:** Pridėtas studentų skirstymas pagal galutinį balą ir atliktas pirmas ir antras tyrimas.
- **v1.0:** programos greičio testavimas su trimis skirtingais konteineriais (vector, list, deque). Įgyvendintos 2 duomenų skirstymo strategijos ir viena jų optimizuota.

**Testavimai atlikti kompiuteryje su šia konfigūracija:**
-
- Procesorius (CPU): Intel i5-11300H (3.1 GHz, 11th Gen);
- RAM: 8 GB
- SSD: Intel 660p
- OS: Windows 10
- Kompiliatorius: Clang++ (LLVM), C++20 standartas

Tyrimai atlikti naudojant šią aparatūrą ir programinę įrangą, kuri užtikrina pakankamą našumą duomenų apdorojimo užduotims. Naudojamas Clang++ kompiliatorius su C++20 standartu leidžia efektyviai išnaudoti modernias kalbos galimybes.

**1 tyrimas. Failų kūrimas ir jo uždarymas**
-

**Tikslas:** įvertinti, kiek laiko užtrunka sugeneruoti skirtingo dydžio duomenų failus.

**Tyrimo eiga:**
- Vartotojas įveda failo pavadinimą, studentų ir pažymių kiekį;
- Laiko matavimas prasideda po vartotojo įvesties;
- Programa sugeneruoja duomenų failą su atsitiktiniais vardais, pavardėmis ir pažymiais;
- Laiko matavimas baigiamas užbaigus failo generavimą;
- Išvedamas sugeneravimo laikas sekundėmis, reprezentuojantis programos spartą failo kūrimui pagal pasirinktus parametrus.

**Gauti rezultatai:**

1. Studentų: 1000, pazymių: 10;

![alt text](images/image-3.png)

2. Studentų: 10000, pazymių: 10;

![alt text](images/image-4.png)

3. Studentų: 100000, pazymių: 10;

![alt text](images/image-5.png)

4. Studentų: 1000000, pazymių: 10;

![alt text](images/image-6.png)

5. Studentų: 10000000, pazymių: 10;

![alt text](images/image-7.png)

**Lentele:**

![alt text](images/image-8.png)

**Išvada**: Failo generavimo trukmė didėja proporcingai duomenų kiekiui, o tai rodo gerą programos efektyvumą. Programa išlieka naši net ir su labai dideliais įrašų kiekiais – 10 milijonų įrašų sugeneruota per mažiau nei 3 minutes.

**2 tyrimas. Duomenų apdorojimo našumo tyrimas (std::vector)**
-

**Tikslas:** Įvertinti programos spartą atliekant pilną duomenų apdorojimo procesą: duomenų nuskaitymą iš jau sugeneruoto failo, studentų rūšiavimą į dvi kategorijas, duomenų išvedimą į atskirus failus.

**Tyrimo eiga:**
- Vartotojas įveda: failo pavadinimą, iš kurio bus nuskaitomi duomenys, dviejų rezultatinių failų pavadinimus (vargšiukams ir kietiakams), pasirinkimą, pagal kokį kriterijų skirstyti studentus;
- Laiko matavimas prasideda po vartotojo įvesties;
- Programa nuskaito studentų įrašus į atmintį;
- Studentai suskirstomi į dvi grupes (vargšiukus ir kietiakus);
- Kiekviena grupė išvedama į atskirą failą;
- Laiko matavimas baigiamas užbaigus įrašymą;
- Išvedami laiko rezultatai sekundėmis.

**Gauti rezultatai:**

1. Studentų: 1000, pažymių: 10;

![alt text](images/image-9.png)

2. Studentų: 10000, pažymių: 10;

![alt text](images/image-10.png)

3. Studentų: 100000, pažymių: 10;

![alt text](images/image-11.png)

4. Studentų: 1000000, pažymių: 10;

![alt text](images/image-12.png)

5. Studentų: 10000000, pažymių: 10;

![alt text](images/image-13.png)

**Lentele:**

![alt text](images/image-14.png)

**Išvada:**
Nuskaitymas ir išvedimas užima daugiausia laiko, ypač su dideliais duomenų kiekiais. Tai rodo, kad programos sparta ribojama ne algoritmo efektyvumo, o kietojo disko įvesties/išvesties greičio. Tuo tarpu rūšiavimo ir skirstymo operacijos vykdomos itin sparčiai, todėl galima teigti, kad pati algoritmo logika yra efektyvi.

**3 tyrimas. Duomenų apdorojimo našumo tyrimas su std::list ir std::deque**
-
**Tikslas:** Palyginti std::vector, std::list ir std::deque konteinerių našumą, atliekant duomenų nuskaitymą, rūšiavimą ir skirstymą į grupes.

**Tyrimo eiga:** Išlieka identiška kaip ir antrajame tyrime – duomenys į programą įkeliami iš tų pačių failų, atliekami tie patys veiksmai ta pačia seka: duomenų nuskaitymas, studentų rūšiavimas bei skirstymas į dvi grupes.

**Gauti rezultatai (std::list):**

1. Studentų: 1000, pažymių: 10;

![alt text](images/image-15.png)

2. Studentų: 10000, pažymių: 10;

![alt text](images/image-16.png)

3. Studentų: 100000, pažymių: 10;

![alt text](images/image-17.png)

4. Studentų: 1000000, pažymių: 10;

![alt text](images/image-18.png)

5. Studentų: 10000000, pažymių: 10;

![alt text](images/image-19.png)

**Lentele:**

![alt text](images/image-20.png)

**Gauti rezultatai (std::deque):**

1. Studentų: 1000, pažymių: 10;

![alt text](images/image-21.png)

2. Studentų: 10000, pažymių: 10;

![alt text](images/image-22.png)

3. Studentų: 100000, pažymių: 10;

![alt text](images/image-23.png)

4. Studentų: 1000000, pažymių: 10;

![alt text](images/image-24.png)

5. Studentų: 10000000, pažymių: 10;

![alt text](images/image-25.png)

**Lentele:**

![alt text](images/image-26.png)

**Išvada:**
Remiantis atliktais matavimais, std::deque konteineris buvo pastebimai greitesnis atliekant skirstymo operacijas, ypač esant dideliems duomenų kiekiams, o rūšiavimo ir nuskaitymo greičiai tarp std::list ir std::deque buvo panašūs.

**2 ir 3 tyrimų bendroji analizė**
-
**Nuskaitymas**

![alt text](images/image-27.png)

**Išvada:**
Nors teoriškai std::vector dažniausiai laikomas greičiausiu nuskaitymui, tyrimas parodė netikėtą rezultatą: su 10 milijonų elementų std::list veikė sparčiausiai. Kitais atvejais, std::vector ir std::deque demonstravo našumą.

**Rušiavimas**

![alt text](images/image-28.png)

**Išvada:**
Rūšiavimui mažesniais ir vidutiniais duomenų kiekiais (iki ~100 000) efektyvesnis yra std::list. Tačiau didėjant duomenų kiekiui (virš 1 000 000) dėl geresnės atminties lokalumo ir efektyvesnių algoritmų naudojimo, std::vector tampa žymiai greitesnis.

**Skirstymas**

![alt text](images/image-29.png)

**Išvada:**
Skirstymo operacijos rezultatai yra labai aiškūs: std::vector buvo greičiausias visais testuotais duomenų kiekiais, ir jo pranašumas ypač išryškėjo didėjant elementų skaičiui. Tai rodo, kad programa efektyviausiai išnaudojo std::vector savybes – tvarkingą studentų laikymą atmintyje (vieną šalia kito) ir galimybę greitai pasiekti bet kurį reikiamą studentą.

**4 tyrimas. Duomenų skaidymo strategijų efektyvumo tyrimas naudojant skirtingus STL konteinerius**
-

**Tikslas:**
Ištirti ir palyginti skirtingų C++ STL konteinerių (std::vector, std::list, std::deque) našumą atliekant studentų duomenų skaidymą pagal dvi skirtingas strategijas.

**Tyrimo eiga:**
- Vartotojas įveda: failo pavadinimą, iš kurio bus nuskaitomi duomenys, pagal ką rušiuoti duomenis ir kokia strategija atlikti;
- Laiko matavimas prasideda po vartotojo įvesties;
- Programa nuskaito studentų įrašus į atmintį;
- **1 strategija** - bendro studentai konteinerio skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose.
- **2 strategija** - bendro studentų konteinerio skaidymas panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai.
- Laiko matavimas baigiamas užbaigus įrašymą;
- Išvedami laiko rezultatai sekundėmis.

**Gauti rezultatai:**

![alt text](images/image-30.png)


**Išvada:**

Atlikus studentų skaidymo į "vargšiukus" ir "kietiakus" tyrimą su skirtingais konteinerių tipais (std::vector, std::list, std::deque) ir dviem skaidymo strategijomis, paaiškėjo esminiai našumo ir atminties naudojimo efektyvumo skirtumai, ypač parodantys std::list pranašumą greitaveikos atžvilgiu.
Pirmojoje strategijoje, kur studentai buvo kopijuojami į du naujus konteinerius, std::list rodė geriausius greičio rezultatus su visais duomenų kiekiais. Šį pranašumą užtikrino O(1) sudėtingumo "push_back" operacija ir tai, kad šiam konteineriui nereikalingas atminties perskirstymas. Nors std::vector ir std::deque taip pat demonstravo priimtiną greitį, jų našumas šiek tiek svyravo dėl vidinių atminties valdymo ypatumų. Svarbu paminėti, kad ši strategija yra nepalanki atminties sąnaudų atžvilgiu, nes tie patys studentų duomenys saugomi keliose vietose.
Antrojoje strategijoje, kurioje "vargšiukai" buvo perkeliami į naują konteinerį, o iš pradinio – trinami, std::list pademonstravo absoliutų pranašumą greitaveikoje. Jo O(1) sudėtingumo "erase" operacija leido išlaikyti efektyvumą net ir su 100,000 studentų. Tuo tarpu std::vector ir std::deque konteineriai, dėl O(N) sudėtingumo "erase" operacijos, tapo nepraktiškai lėti didėjant duomenų kiekiui. Visgi, ši strategija pasižymi ženkliai efektyvesniu atminties naudojimu, nes studentų duomenys nėra dubliuojami, o tiesiog perskirstomi tarp pradinio ir naujo "vargšiukų" konteinerio.

**Optimizavus strategija 1 gauti rezultatai**

![alt text](images/image-31.png)

**Išvada:**

Atlikus studentų skirstymo našumo tyrimą su Vector konteineriu, paaiškėjo, kad strategija 1 (naudojant for ciklas) ir optimizuota strategija 1 (naudojant std::partition_point) veikė panašiu greičiu. Pagrindinė to priežastis – abiejose strategijose buvo operuojama su nuorodomis (arba rodyklėmis) į studentų objektus, o ne su jų kopijomis.

### Autorius 
Rokas Venckus