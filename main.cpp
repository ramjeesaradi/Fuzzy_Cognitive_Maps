#include "error.h"
#include "pso.h"
#include "fcm.h"

int main() {
    ofstream otwts("test-data/weights.csv");
	//error();
    array<long double, 100> temp = pso( -1.0 ,1.0 ,0.1132 ,0.1 ,2.0 ,2.0 );
    for(int m = 0; m < 10; m++) { //import the weights
        for(int n = 0; n < 10; n++) {
            otwts << temp[m*10 + n] << "\t";
        } otwts << endl;
    }
    return 0;
}
