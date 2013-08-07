#include "pso.h"

array<long double, 100> pso(long double lower_bound ,long double upper_bound ,long double epsilon, long double omega, long double phyp, long double phyg) {
    const int dmnsns = 100, prtcls = 30;
	//long double lower_bound = -1.0, upper_bound = 1;
    array<long double, dmnsns> g , g1;
    array<array<long double, dmnsns>, prtcls> p, x, v;

    for(int i=0; i < prtcls; i++){
        for(int j = 0; j < dmnsns; j++){
            x[i][j] = lower_bound + ((rand()%1000)/1000.0)*(abs(upper_bound - lower_bound)) ;
            v[i][j] = (2.0*lower_bound) + ((rand()%1000)/1000.0)*(2.0*abs(upper_bound - lower_bound));
            //cout << x[i][j] <<endl;
        }
    }
	g = x[0];
	g1 = x[80];
    p = x;
    // for(int x=0; x < 100; x++){
      // cout << x <<"  "<< p[0][x] << endl;
      // }

    for(int i= 0; i < prtcls; i++){// initializng global best
    	if ( error(p[i]) < error(g) ){
    		g = p[i];
    		//cout << "in loop"  << endl;
    	}
    }
	int iterh = 0;
    //for(int iter = 0; iter < 20; iter ++ )
    while((error(g)) > epsilon)
	{	
        for(int i= 0; i < prtcls; i++){
            for(int j = 0; j < dmnsns; j++){
                long double rp = (rand()%1000)/1000.0;
                long double rg = (rand()%1000)/1000.0;
                v[i][j] = omega * v[i][j] + phyp*rp*(p[i][j] - x[i][j]) + phyg*rg*(g[j] - x[i][j]) ;
                x[i][j] += v[i][j];
            }
            if (error(p[i]) > error(x[i])){
                p[i] = x[i];
            }
            if (error(g) > error(p[i])){
                g1 =g ;
				g = p[i];
            }
        }
		// for(int x=0; x < 100; x++){
		// cout << x <<"  "<< g[x] << endl;
		// }
		iterh++;
		cout << iterh <<" "<< error(g)<< endl;
		
    }
    return g;
}
