#include "pso.h"

array<double, 100> pso(double lower_bound ,double upper_bound ,double epsilon, double omega, double phyp, double phyg ,int horizon ,int concept_nos) {
    const int dimensions = 100, prtcls = 50;
	//double errpi = 0.0;
    array<double, dimensions> g , g1 ;
    array<array<double, dimensions>, prtcls> p, x, v;

    for(int i=0; i < prtcls; i++){
        for(int j = 0; j < concept_nos * concept_nos; j++){
            x[i][j] = lower_bound + ((rand()%100000000)/100000000.0)*(abs(upper_bound - lower_bound)) ;
            v[i][j] = (2.0*lower_bound) + ((rand()%100000000)/100000000.0)*(2.0*abs(upper_bound - lower_bound));
            //cout << x[i][j] <<endl;
        }
    }
	for(int j = 0; j < concept_nos * concept_nos; j++){
            g[j]  = lower_bound + ((rand()%100000000)/100000000.0)*(abs(upper_bound - lower_bound)) ;
            g1[j] = lower_bound + ((rand()%100000000)/100000000.0)*(abs(upper_bound - lower_bound)) ;
        }
    p = x;
    // for(int x=0; x < 100; x++){
      // cout << x <<"  "<< p[0][x] << endl;
      // }

    for(int i= 0; i < prtcls; i++){// initializng global best
    	if ( error(p[i] ,horizon ,concept_nos) < error(g ,horizon ,concept_nos) ){
    		g = p[i];
    		//cout << "in loop"  << endl;
    	}
    }
	int iterh = 0;
    for(int iter = 0; iter < omega; iter ++ )
    //while(abs((error(g ,horizon ,concept_nos)) - (error(g1 ,horizon ,concept_nos))) > epsilon)
	{	
        for(int i= 0; i < prtcls; i++){
            for(int j = 0; j < concept_nos * concept_nos; j++){
                double rp = (rand()%100000000)/100000000.0;
                double rg = (rand()%100000000)/100000000.0;
                v[i][j] = (1.0- ((double) 1.0/omega) * iterh ) * v[i][j] + phyp*rp*(p[i][j] - x[i][j]) + phyg*rg*(g[j] - x[i][j]) ;
                double loc = x[i][j] + v[i][j];
				if(loc < lower_bound)
				{
					loc= lower_bound+(lower_bound-loc);

					if(loc > upper_bound)
					{
						loc= lower_bound+(upper_bound-lower_bound)*(rand()%100000000)/100000000.0;
					}
				}
				else if(loc > upper_bound)
					{
						loc= loc-(upper_bound-lower_bound);

						if(loc < lower_bound)
						{
							loc = lower_bound+(upper_bound-lower_bound)*(rand()%100000000)/100000000.0;
						}
					}
				x[i][j] = loc;
            }
			
            if (error(p[i] ,horizon ,concept_nos) > error(x[i] ,horizon ,concept_nos)){
                p[i] = x[i];
            }
            if (error(g ,horizon ,concept_nos) > error(p[i] ,horizon ,concept_nos)){
                g1 =g ;
				g = p[i];
            }
        }
		// for(int x=0; x < 100; x++){
		// cout << x <<"  "<< g[x] << endl;
		// }
		iterh++;
		cout << iterh <<" "<< error(g ,horizon ,concept_nos)<< endl;
		
    }
    return g;
}
