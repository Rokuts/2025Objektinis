#pragma once

#include "headers.h"

int atsitiktinis_skaicius(int min, int max);
bool ar_tik_raides(const string& zodis);
string atsitiktine_zodis(const vector<string> &zodynas);
int gauti_skaiciu(string zinute, int min = 1, int max = 10, bool minus1 = false);
void generuoti_faila();
bool paklausiam_ar_rodyti_vidurki();

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