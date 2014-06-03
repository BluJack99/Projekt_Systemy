#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

//Projekt na Systemy operacyjne, autorzy: Micha³ Bazyd³o, Tomasz Wyszyñski, Ilya Shauliuk


using namespace std;





float iloczynSkalarny(float *wektorA, float *wektorB, float wymiarWektora) {
        int i = 0;
        float iloczynSkalarny = 0;
        for(i = 0; i < wymiarWektora; i++) {
            
                iloczynSkalarny = iloczynSkalarny + wektorA[i] * wektorB[i];  
                
        }
        return iloczynSkalarny;
}


float iloczynSkalarny2(float *wektorA, float wymiarWektora) {
        int i = 0;
        float iloczynSkalarny2 = 0;
        for(i = 0; i < wymiarWektora; i++) {
               
                iloczynSkalarny2 = iloczynSkalarny2 + wektorA[i] * wektorA[i]; 
                
        }
        return iloczynSkalarny2;
}




int main() {

        int opcja;
        int s;
	    float wektorA[s]; 
        float wektorB[s];
        double tab[1][s];
        
         cout << "Wybierz opcje: "<<endl;
         cout << "1. Ortogonalizacja wektorow"<<endl;
         cout << "2. Obliczenie ukladu rownan metoda eliminacji Gaussa"<<endl<<endl;
         cout << "Wcisnij 1 lub 2: ";
         cin >> opcja;      
        
        }
