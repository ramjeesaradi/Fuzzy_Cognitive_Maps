#include "error.h"

long double error(array<long double, 100> dmns)
{
    ifstream inrec ("test-data/wbctrain.csv");//import input file
    ofstream outrec ("test-data/wbcrec.csv");

    // TODO: l,m,n,t say nothing about what the variables are.

    int size = 10;

    int m, n, t=1, l=0 ;
    long double toterror = 0.0;
    array<long double, size> a, a2;

   while(!inrec.eof()) { // check if file ends
        for (m = 0; m < size; m++) {// loading the concepts within records
            inrec >> a[m];
            outrec << a[m] << "\t";
            a2[m] = a[m]; //saving original values to the actual concepts
			//if(isnan(a2[m]))cout<<"bannnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn!!"<<endl;
        }
        outrec << "\n";
        a[size-1]=0; // As it is training data
        //cout << endl;
        
        long double output = fcm(a,size,t);
		
        toterror += abs (a2[size-1] - output);
		
		
        l++;
    }
	
	
	//cout<<isnan(toterror)<<endl;
    return toterror /((long double) l);
}
