#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <array>

using std::cout;
using std::endl;
using std::array;
using std::ifstream;
using std::ofstream;
using std::getline;

int main()
{
    ifstream inrec ("test-data/wbc/train.csv");
    ofstream outrec ("test-data/wbc/rec.csv");

    // TODO: l,m,n,t say nothing about what the variables are.

    const int size = 10;

    int m, n;
    array<double, size> a;

    while(!inrec.eof()){ // iterate for each record
        
		for (m = 0; m < 10; m++)            {// loading the concepts within records
            //getline(inrec,a[0],"\t");
			inrec >> a[m];
            outrec << (double)a[m] << "\t";
        }
		outrec << "\n";
    }
	return 0;
}