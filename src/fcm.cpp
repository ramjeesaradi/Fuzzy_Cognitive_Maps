#include "fcm.h"

double fcm(array<double, 100> concept, array<double, 500> dmns, int concept_nos, int horizon) {
	const int size = 100;
	int time_step = 0;
	array<double, size> new_concept = {0.0} , net ={0.0};
	array<array<double, size>, size> w;
	int m, n;
	
	for(m = 0; m < concept_nos; m++)    { //import the weights passed to a local array
        for(n = 0; n < concept_nos; n++)        {
            w[m][n] = dmns[m*concept_nos + n];
			
        }
    }
	
	while (time_step < horizon) {    //total two increments
            // Calculating activation of each function
            for (m = 0; m < concept_nos; m++) {
                for (n=0; n < concept_nos; n++) {
                    net[m] += concept[n] * w[n][m];
					} 
				new_concept[m] = net[m];
				//cout << net << endl;
                //new_concept[m] = 1.0 / (1.0 + exp((new_concept[m] - 1.0) * 6.0 * -1.0 ));
				
            }
			//cout<<isnan(a2[m])<<endl;
            concept = new_concept;//updating for next time step t+1th state of a
            time_step++;
        }
	if(isnan(concept[concept_nos - 1]))cout<<"bannnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn!!"<<endl;
	//cout << concept[concept_nos - 1] << endl;
	return concept[concept_nos - 1] ;
	}
