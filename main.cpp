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

double tab2[100][100];
int N;
double Xi[100];
bool zdegradowana = false;

void zamianaWierszy (int r, int t)
{
        double tmp = 0.0;
        for (int i = 0; i < N+1; i++)
        {
 
                tmp = tab2[r][i];
                tab2[r][i] = tab2[t][i];
                tab2[t][i] = tmp;
        }
 
}



int main() {

        int opcja;
        int s;
	    float wektorA[s]; 
        float wektorB[s];
        double tab[1][s];
        
        }
