#include "fcm.h"

long double fcm(array<long double, 100> concept, array<long double, 100> dmns, int size, int horizone) {
	
	int time_step = 0;
	array<long double, size> new_concept = {0.0};
	array<array<long double, size>, size> w;
	long double net = 0.0;
	int m, n;
	
	for(m = 0; m < size; m++)    { //import the weights passed to a local array
        for(n = 0; n < size; n++)        {
            w[m][n] = dmns[m*size + n];
			
        }
    }
	
	while (time_step < horizone) {    //total two increments
            // Calculating activation of each function
            for (m = 0; m < size; m++) {
                for (n=0; n < size; n++) {
                    net += concept[n] * w[n][m];
					
					static int y=0;
		if(isnan(w[n][m])&&y==0)
		{
		cout<<"bannnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn!!"<<endl;
		y++;
		}
					
					
                } 
				new_concept[m] = net;
                //new_concept[m] = 1.0 / (1.0 + exp(net * (-1.0)));
				
            }
			//cout<<isnan(a2[m])<<endl;
            concept = new_concept;//updating for next time step t+1th state of a
            time_step++;
        }
	return concept[size - 1] ;
	}
