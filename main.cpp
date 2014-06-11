#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>


using namespace std;

//Autorzy: Micha³ Bazyd³o, Tomasz Wyszyñski, Ilya Shauliuk



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
                //wypisanieTab();
 
                przeksztalcenieTab(m-1);
 
               
        }
}
 
 
void gauss(int k)
{
        if( k < N)
        {
 
                double p = tab2[k][k];
 
                if (p == 0)
                        zdegradowana = true;
                else
                {
                        for (int i = k+1; i < N; i++)
                        {
                                double f = tab2[i][k] / p;
                                for (int j = k; j < N+1; j++)
                                {
                       
                                        tab2[i][j] = tab2[i][j] - f * tab2[k][j];
                                }
                        }
 
                        gauss(k+1);
                }
        }
        if (!zdegradowana)
        {
                double a = 0.0;
 
                for(int i = k+1; i < N; i++)
                        a+=tab2[k][i]*Xi[i];
                    Xi[k] = (tab2[k][N] + (-a)) / tab2[k][N-(N-k)];
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
 
void czy_zdegradowana()
{
 
        double det = 0.0;
       
        if (N == 2)
                det = tab2[0][0] * tab2 [1][1] - tab2 [0][1] * tab2 [1][0];
       
        if (N == 3)
                det = tab2[0][0] * tab2[1][1] * tab2[2][2] + tab2 [1][0] * tab2[2][1] * tab2[0][2] + tab2[2][0] * tab2[0][1] * tab2[1][2] - tab2[0][2] * tab2[1][1] * tab2[2][0] - tab2[1][2] * tab2[2][1] * tab2[0][0] - tab2[2][2] * tab2 [0][1] * tab2[1][0];
 
        if (det == 0)
        zdegradowana = true;
       
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
	    	cout << "\tIloczyn skalarny= " << iloczynSkalarny(wektorA, wektorB, s) << endl<<endl;
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
      case 2:
	  {
	 
       cout<<endl<<endl<<"\t\tWybrales obliczanie ukladu rownan metoda Gaussa"<<endl;
       
       cout << "\n\tPodaj wymiar: ";
       cin >> N;
       cout << endl;
	   wczytTab();
       cout << "\n\n\tMacierz: " << endl;
       wypisanieTab();
 if(!zdegradowana)
        {
                przeksztalcenieTab(N);
                gauss(0);
 if(!zdegradowana)
                {
                
                cout << "\n\n\tMacierz po przeksztalceniu: " << endl;
                wypisanieTab();
              
				cout<< "\n\n\tRozwiazanie ukladu rownan: " << endl;
                for(int i=0;i<N;i++)
                                cout <<"x" << i+1 << " = " << Xi[i] << endl;
                }
                else cout << "Podana macierz jest zdegradowana!" << endl;;
 }
                else cout << "Podana macierz jest zdegradowana!" << endl;;

break;
}
        
}

  
    	return 0;
    		
}

