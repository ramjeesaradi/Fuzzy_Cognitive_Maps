#include "error.h"
#include "pso.h"
#include "fcm.h"

int main() {
    ofstream otwts("/cygdrive/c/Users/krrao/Eclipse/Workspace/fcm/test-data/weights.csv");
	double upper_bound ,lower_bound ,epsilon , omega, phyp, phyg ,horizon ,concept_nos;
	
	cout << "Enter Upper bound:";
	cin >> upper_bound;
	cout << endl;
	
	cout << "Enter Lower bound:";
	cin >> lower_bound;
	cout << endl;
	
	cout << "Enter epsilon:";
	cin >> epsilon;
	cout << endl;
	
	cout << "Enter iteration:";
	cin >> omega;
	cout << endl;
	
	cout << "Enter C1:";
	cin >> phyp;
	cout << endl;

	cout << "Enter C2:";
	cin >> phyg;
	cout << endl;
	
	cout << "Enter Horizon:";
	cin >> horizon;
	cout << endl;
	
	cout << "Enter number of Concepts/variables:";
	cin >> concept_nos;
	cout << endl;
	
    array<double, 500> temp = pso( lower_bound ,upper_bound ,epsilon , omega, phyp, phyg, horizon ,concept_nos );
    for(int m = 0; m < concept_nos; m++) { //import the weights
        for(int n = 0; n < concept_nos; n++) {
            otwts << temp[m*concept_nos + n] << "\t";
        } otwts << endl;
    }
    return 0;
}
