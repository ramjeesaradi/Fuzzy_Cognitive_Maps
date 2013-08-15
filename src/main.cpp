#include "error.h"
#include "pso.h"
#include "fcm.h"

int main() {
    ofstream otwts("/cygdrive/c/Eclipse/Workspace/fcm1/test-data/weights.csv");
	double upper_bound ,lower_bound ,epsilon , omega, phyp, phyg ,horizon ,num_concepts, num_output_class;
	
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
	cin >> num_concepts;
	cout << endl;
	
	cout << "Enter Number of target classes:";
	cin >> num_output_class;
	cout << endl;
	
    array<double, 500> temp = pso( lower_bound ,upper_bound ,epsilon , omega, phyp, phyg, horizon ,num_concepts, num_output_class );
    for(int m = 0; m < num_concepts; m++) { //import the weights
        for(int n = 0; n < num_concepts; n++) {
            otwts << temp[m*num_concepts + n] << "\t";
        } otwts << endl;
    }
    return 0;
}
