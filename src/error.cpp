#include "error.h"

double error(array<double, 100> dimensions , int horizon ,int concept_nos)
{
    ifstream inrec ("test-data/iris/train.csv");//import input file


    // TODO: l,m,n,t say nothing about what the variables are.
    const int size = 100;

    int m, n, l = 0 ;
    double toterror = 0.0, threshold = 0.5;
    array<double, size> a, a2;

   while(!inrec.eof()) { // check if file ends
        for (m = 0; m < concept_nos; m++) {// loading the concepts within records
            inrec >> a[m];
            a2[m] = a[m]; //saving original values to the actual concepts
			//if(isnan(a2[m]))cout<<"bannnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn!!"<<endl;
        }
        a[concept_nos-1] = 0; // As it is training data
        //cout << endl;

        double output = fcm( a, dimensions, concept_nos, horizon);
		 // if(((a2[concept_nos-1] - output) < 0) || (output < = 0)){
			 // toterror++;
		 // }

        toterror += pow((a2[concept_nos-1] - output),2);
        l++;
    }


	//cout<< toterror /((double) l) <<endl;
    return toterror /((double) l);
}
