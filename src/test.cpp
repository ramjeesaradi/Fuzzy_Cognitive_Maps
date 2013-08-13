#include "test.h"

void test(int horizon, int concept_nos)
{
    ifstream inrec ("/cygdrive/c/Users/krrao/Eclipse/Workspace/fcm/test-data/wine/test.csv");//import input file
	ifstream inwts ("/cygdrive/c/Users/krrao/Eclipse/Workspace/fcm/test-data/weights.csv"); //import weights 
    ofstream outrec ("/cygdrive/c/Users/krrao/Eclipse/Workspace/fcm/test-data/wine/predicted.csv");

    // TODO: l,m,n,t say nothing about what the variables are.
    const int size = 100;
	

    int m, n, l=0 , correct = 0 ;
    double net=0.0;
    array<double, size> a, a2 ;
	array<double, 500 > w;

    for(m = 0; m < concept_nos*concept_nos; m++)    { //import the weights passed to a local array
            inwts >>w[m];
    }
   while(!inrec.eof()) { // check if file ends
        for (m = 0; m < concept_nos; m++) {// loading the concepts within records
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
        a[concept_nos-1]=0; // As it is training data
        double output = fcm( a, w,concept_nos , horizon);
       
		outrec << output << "\t";
		if(abs(a2[concept_nos-1]-output) < 0.25){
			correct++;
			outrec << "True" << "\n";
		}else outrec << "False" << "\n";
		l++;
    }
	cout << correct << " of " << l << endl;;
}
int main(){
	int horizon;
	int concept_nos;
	cout << "Enter horizon:";
	cin >> horizon;
	cout << endl;
	
	cout << "Enter Number of Concepts or Attributes:";
	cin >> concept_nos;
	cout << endl;
	
	test(horizon, concept_nos);
	}
