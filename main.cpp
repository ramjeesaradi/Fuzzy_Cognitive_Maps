#include "error.h"
#include "pso.h"
#include "fcm.h"

int main() {
    ofstream otwts("test-data/weights.csv");
	//error();
    array<long double, 100> temp = pso(0.2,0.5,5.0,5.0);
    for(int m = 0; m < 10; m++) { //import the weights
        for(int n = 0; n < 10; n++) {
            otwts << temp[m*10 + n] << "\t";
            //cout <<m*10 + n <<" " << dmns[m*10 + n] << endl;
            //cout << w[m][n] << endl ;
        } otwts << endl;
    }
    return 0;
}
