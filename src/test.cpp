#include "test.h"

void test(int horizon, int num_concepts, int num_output_class)
{
    ifstream inrec ("/cygdrive/c/Eclipse/Workspace/fcm1/test-data/wbc/test.csv");//import input file
	ifstream inwts ("/cygdrive/c/Eclipse/Workspace/fcm1/test-data/weights.csv"); //import weights 
    ofstream outrec ("/cygdrive/c/Eclipse/Workspace/fcm1/test-data/wbc/predicted.csv");

    // TODO: l,m,n,t say nothing about what the variables are.
    const int size = 100;
	

    int m, n, l=0 , correct = 0 ;
    double net=0.0;
    array<double, size> a, a2 ;
	array<double, 500 > w;

    for(m = 0; m < num_concepts*num_concepts; m++)    { //import the weights passed to a local array
            inwts >>w[m];
    }
   while(!inrec.eof()) { // check if file ends
        for (m = 0; m < num_concepts; m++) {// loading the concepts within records
            inrec >> a[m];
            outrec << a[m] << "\t";
            a2[m] = a[m]; //saving original values to the actual concepts
			static int y=0;
			if(isnan(w[m])&&y==0)
				{
				cout<<"bannnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn!!"<<endl;
				y++;
				}
        }
		
		for(int x = 0; x < num_output_class; x++ ){
			a[num_concepts - num_output_class + x] = 0; // As it is training data
		}
		
        array<double , 100> output = fcm( a, w,num_concepts, num_output_class , horizon);
        
		for(int x = 0; x < num_output_class; x++ ){
		outrec << output[x] << "\t";
		}
		
		double max_value = 0.0;
		for(int x = 0; x < num_output_class; x++ ){
			if (max_value < output[x]) max_value = output[x];
		}
		
		for(int x = 0; x < num_output_class; x++ ){
			if ( a2[num_concepts - num_output_class + x] == 1.0 && output[x] == max_value ) {
				outrec << "True" << "\n";
				correct++;
			}
			if ( a2[num_concepts - num_output_class + x] == 1.0 && output[x] != max_value ) {
				outrec << "False" << "\n";
			}
		}
		
		// if(abs(a2[num_concepts-1]-output) < 0.25){
			// correct++;
			// outrec << "True" << "\n";
		// }else outrec << "False" << "\n";
		l++;
    }
	cout << correct << " of " << l << endl;;
}
int main(){
	int horizon;
	int num_concepts, num_output_class;
	cout << "Enter horizon:";
	cin >> horizon;
	cout << endl;
	
	cout << "Enter Number of Concepts or Attributes:";
	cin >> num_concepts;
	cout << endl;
	
	cout << "Enter Number of target classes:";
	cin >> num_output_class;
	cout << endl;
	
	test(horizon, num_concepts, num_output_class );
	}
