#include "error.h"

double error(array<double, 500> dimensions , int horizon ,int num_concepts, int num_output_class)
{
    ifstream inrec ("/cygdrive/c/Eclipse/Workspace/fcm1/test-data/wbc/train.csv");//import input file


    // TODO: l,m,n,t say nothing about what the variables are.
    const int size = 100;

    int m, n, l = 0 ;
    double toterror = 0.0, threshold = 0.5;
    array<double, size> a, a2;

   while(!inrec.eof()) { // check if file ends
        for (m = 0; m < num_concepts; m++) {// loading the concepts within records
            inrec >> a[m];
            a2[m] = a[m]; //saving original values to the actual concepts
			//if(isnan(a2[m]))cout<<"bannnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn!!"<<endl;
        }
        for(int x = 0; x < num_output_class; x++ ){
			a[num_concepts - num_output_class + x] = 0; // As it is training data
		}
        //cout << endl;

        array<double, 100> output = fcm( a, dimensions, num_concepts, num_output_class, horizon);
		 // if(((a2[num_concepts-1] - output) < 0) || (output < = 0)){
			 // toterror++;
		 // }
		for(int x = 0; x < num_output_class; x++ ){
			 toterror += pow( a2[num_concepts - num_output_class + x] - output[x] , 2 );
		}
        
        l++;
    }


	//cout<< toterror /((double) l) <<endl;
    return toterror /((double) (l*num_output_class));
}
