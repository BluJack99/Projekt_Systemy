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


void wypisanieTab()
{
       
        for (int i=0; i < N; i++)
        {
                for (int j = 0; j < N+1; j++)
                {
                        if (j < N) 
						cout <<tab2[i][j]<<"  ";
                        else cout << tab2[i][j];
                       
                }
 
                cout << endl;
        }
}
 
void wczytTab()
{
        
        for (int i=0; i < N; i++)
                for (int j = 0; j < N; j++)
                {
                        cout << "\tPodaj liczbe dla [" << i+1 << "," << j+1 << "] = ";
                        cin >> tab2[i][j];
                }
 
        cout << endl << endl;
        for (int i = 0; i < N; i++)
        {
                cout << "\tPodaj wyrazy wolne dla wiersza nr " << i+1 << ": ";
                cin >> tab2[i][N];
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
         
         
         switch(opcja){

case 1:
{

	
      cout<<endl<<endl<<"\t\tWybrales ortogonalizacje Grama-Schimdta"<<endl<<endl;
	  cout << "\tPodaj rozmiar wektora A i B: ";
	  cin >> s;
	  cout<<endl;
		for(int i=0; i<s; ++i){
	    	cout << "\tPodaj liczbe nr " << i << ": ";
	    	cin >> wektorA[i];
	    }
	    cout<<endl;
	    cout << "\tWektor A: ";
	    for(int i=0; i<s; ++i){
	    	cout << wektorA[i]<< " ";
	    	}
	    	cout << endl;
	    	cout << endl;
	    for(int i=0; i<s; ++i){
	    	cout << "\tPodaj liczbe nr " << i << ": ";
	    	cin >> wektorB[i];
	    
}
        cout << endl;
   
	    cout << "\tWektor B: ";
	    for(int i=0; i<s; ++i){
	    	cout << wektorB[i]<< " ";
	    	}
	    
	    	cout << endl<<endl;
	    	cout << "\tIloczyn skalarny A*B= " << iloczynSkalarny(wektorA, wektorB, s) << endl<<endl;
	        cout << "\tIloczyn skalarny A*A= " << iloczynSkalarny2(wektorA, s) << endl<<endl;
			cout <<endl;
	    
	    
	    float il=iloczynSkalarny(wektorB, wektorA,s);
	    float il2=iloczynSkalarny2(wektorA,s);
			
			cout << "\t\tOrtogonalizacja Grama-Schimdta: ";
	    	for(int i=0; i<s; ++i){
	    	  float Orto;
	    		Orto=Orto=(wektorB[i]-(il/sqrt(il2*il2))*wektorA[i]);
	    	cout << Orto<< " ";
	    
	    	} 
break;            
}    
        
        }
