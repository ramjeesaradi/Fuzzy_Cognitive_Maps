#include "test.h"

void test()
{
    ifstream inrec ("test-data/wbctest.csv");//import input file
	ifstream inwts ("test-data/weights.csv"); //import weights 
    ofstream outrec ("test-data/wbcrec.csv");

    // TODO: l,m,n,t say nothing about what the variables are.
	int concept_nos = 10;
	int num_timesteps = 3;
    const int size = 100;
	

    int m, n, l=0 , correct = 0 ;
    long double net=0.0;
    array<long double, size> a, a2 , w;

    for(m = 0; m < size; m++)    { //import the weights passed to a local array
            inwts >>w[m];
    }
   while(!inrec.eof()) { // check if file ends
        for (m = 0; m < concept_nos; m++) {// loading the concepts within records
            inrec >> a[m];
            outrec << a[m] << "\t";
            a2[m] = a[m]; //saving original values to the actual concepts
		
        }
        a[concept_nos-1]=0; // As it is training data
        long double output = fcm( a, w,concept_nos , num_timesteps);
        
       
		outrec << output << "\n";
		if(abs(a2[concept_nos-1]-output)<0.1) correct++;
		l++;
    }
	cout << correct;
}
int main(){
	test();
	}
