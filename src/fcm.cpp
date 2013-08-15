#include "fcm.h"

array<double, 100> fcm(array<double, 100> concept, array<double, 500> dmns, int num_concepts, int num_output_class, int horizon) {
	const int size = 100;
	int time_step = 0;
	array<double, size> new_concept = {0.0} , net ={0.0} , output = {0.0} ;
	array<array<double, size>, size> w;
	int m, n;
	
	for(m = 0; m < num_concepts; m++)    { //import the weights passed to a local array
        for(n = 0; n < num_concepts; n++)        {
            w[m][n] = dmns[m*num_concepts + n];
			
        }
    }
	
	while (time_step < horizon) {    //total two increments
            // Calculating activation of each function
            for (m = 0; m < num_concepts; m++) {
                for (n=0; n < num_concepts; n++) {
                    net[m] += concept[n] * w[n][m];
					} 
				new_concept[m] = net[m];
				//cout << net << endl;
                new_concept[m] = pow( (1.0 + exp((new_concept[m] - 1.0) * 6.0 * -1.0 )), -1.0 );
				
            }
			//cout<<isnan(a2[m])<<endl;
            concept = new_concept;//updating for next time step t+1th state of a
            time_step++;
        }
	if(isnan(concept[num_concepts - 1]))cout<<"bannnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn!!"<<endl;
	//cout << concept[num_concepts - 1] << endl;
	for(int x = 0; x < num_output_class; x++ ){
		output[x] = concept[num_concepts - num_output_class + x];
	}
	return output ;
	}
