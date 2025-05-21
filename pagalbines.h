#pragma once

#include "headers.h"
#include "ivedimas.h"
#include "isvedimas.h"
#include "rusiavimas.h"

int atsitiktinis_skaicius(int min, int max);
bool ar_tik_raides(const string& zodis);
string atsitiktine_zodis(const vector<string> &zodynas);
int gauti_skaiciu(string zinute, int min = 1, int max = 10, bool minus1 = false);
void surinkti_generavimo_duomenis(path& failas, int& studentu_kiekis, int& pazymiu_kiekis, int& pavarde_w, int& vardas_w);
void generuoti_faila_logika(const path& failas, int studentu_kiekis, int pazymiu_kiekis, int pavarde_w, int vardas_w);
path ivesti_failo_pavadinima(const string& uzklausa, bool turi_egzistuoti);
void generuoti_faila();
bool paklausiam_ar_rodyti_vidurki();
void laiko_tyrimas();


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