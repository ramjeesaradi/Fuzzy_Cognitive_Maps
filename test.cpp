//#include "test.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <array>

using std::cout;
using std::endl;
using std::array;
using std::ifstream;
using std::ofstream;
using std::abs;

int main()
{
    ifstream inrec ("test-data/wbctest.csv");//import input file
	ifstream inwts ("test-data/weights.csv"); //import weights 
    ofstream outrec ("test-data/wbcrec.csv");

    // TODO: l,m,n,t say nothing about what the variables are.

    const int size = 10;

    int m, n, t=0, l=0 , correct = 0 ;
    long double net=0.0;
    array<long double, size> a, a1, a2;
    array<array<long double, size>, size> w;

    for(m = 0; m < size; m++)    { //import the weights passed to a local array
        for(n = 0; n < size; n++)        {
            inwts >>w[m][n];			
        }
    }
   while(!inrec.eof()) { // check if file ends
        for (m = 0; m < size; m++) {// loading the concepts within records
            inrec >> a[m];
            outrec << a[m] << "\t";
            a2[m] = a[m]; //saving original values to the actual concepts
			//if(isnan(a2[m]))cout<<"bannnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn!!"<<endl;
        }
        a[size-1]=0; // As it is training data
        //cout << endl;
        
        while (t < 1) {//total two increments
            // Calculating activation of each function
            for (m = 0; m < size; m++) {
                for (n=0; n < size; n++) {
                    net += a[n] * w[n][m];
				
				}               
                a1[m] = 1.0 / (1.0 + exp(net * (-1.0)));
				
            }
			//cout<<isnan(a2[m])<<endl;
            a = a1;//updating for next time step t+1th state of a
            t++;
        }
		outrec << a1[size-1]<< "\n";
		if(abs(a2[size-1]-a1[size-1])<0.1) correct++;
		l++;
    }
	cout << correct;
    return 0;
}