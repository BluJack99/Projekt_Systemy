#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

//Projekt na Systemy operacyjne, autorzy: Micha� Bazyd�o, Tomasz Wyszy�ski, Ilya Shauliuk


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
 
void wypisanieTab();

void przeksztalcenieTab(int m)
{
       
        if (m > 1)
        {
                int max = 0;
                for (int i = N-m; i < N; i++)
                {
                        if (tab2[i][N-m] > tab2[N-m][N-m])
                                zamianaWierszy(N-m,i);
                }
               
 
                przeksztalcenieTab(m-1);
 
               
        }
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
