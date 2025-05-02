#include "apskaiciuotas_studentas.h"

//Konvertuoja studenta i apskaiciuota studenta
apskaiciuotas_studentas apskaiciuoti_stud(studentas stud){
    apskaiciuotas_studentas S;
    S.studentas = stud;
    S.vidurkis = vidurkis(&stud);
    S.mediana = mediana(&stud);
    return S;
    
}