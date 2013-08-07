#include "error.h"

long double error(array<long double, 100> dimensions)
{
    ifstream inrec ("test-data/wbctrain.csv");//import input file
    ofstream outrec ("test-data/wbcrec.csv");

    // TODO: l,m,n,t say nothing about what the variables are.
	int concept_nos = 10;
    const int size = 100;

    int m, n, num_timesteps = 3, l = 0 ;
    long double toterror = 0.0, threshold = 0.5;
    array<long double, size> a, a2;

   while(!inrec.eof()) { // check if file ends
        for (m = 0; m < concept_nos; m++) {// loading the concepts within records
            inrec >> a[m];
            outrec << a[m] << "\t";
            a2[m] = a[m]; //saving original values to the actual concepts
			//if(isnan(a2[m]))cout<<"bannnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn!!"<<endl;
        }
        outrec << "\n";
        a[concept_nos-1] = 0; // As it is training data
        //cout << endl;

        long double output = fcm( a, dimensions, concept_nos, num_timesteps);
		 // if(((a2[concept_nos-1] - output) < 0) || (output < = 0)){
			 // toterror++;
		 // }

        toterror += pow((a2[concept_nos-1] - output),2);
        l++;
    }


	//cout<< toterror /((long double) l) <<endl;
    return toterror /((long double) l);
}
