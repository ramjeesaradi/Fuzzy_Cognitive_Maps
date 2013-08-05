#include "pso.h"

array<long double, 100> pso(long double epsilon, long double omega, long double phyp, long double phyg) {
    const int dmnsns = 100, prtcls = 20;

    array<long double, dmnsns> g;
    array<array<long double, dmnsns>, prtcls> p, x, v;

    for(int i=0; i < prtcls; i++){
        for(int j = 0; j < dmnsns; j++){
            x[i][j] = -1.0 + ((rand()%100000000)/100000000.0)*2.0 ;
            v[i][j] = -2.0 + ((rand()%100000000)/100000000.0)*4.0;
            g[j] = 0.0;
            //cout << x[i][j] <<endl;
        }
    }

    p = x;
    /*for(int x=0; x < 100; x++){
      cout << x <<"  "<< p[0][x] << endl;
      }*/

    for(int i= 0; i < prtcls; i++){// initializng global best
    	if ( error(p[i]) < error(g) ){
    		g = p[i];
    		//cout << "in loop"  << endl;
    	}
    }
    for(int iter = 0; iter < 20; iter ++ )
    //while(error(g) > epsilon)
	{	
        for(int i= 0; i < prtcls; i++){
            for(int j = 0; j < dmnsns; j++){
                long double rp = (rand()%10000000)/10000000.0;
                long double rg = (rand()%10000000)/10000000.0;
                v[i][j] = omega * v[i][j] + phyp*rp*(p[i][j] - x[i][j]) + phyg*rg*(g[j] - x[i][j]) ;
                x[i][j] += v[i][j];
            }
            if (error(p[i]) > error(x[i])){
                p[i] = x[i];
            }
            if (error(g) > error(p[i])){
                g = p[i];
            }
        }
		for(int x=0; x < 100; x++){
		cout << x <<"  "<< g[x] << endl;
		}
		cout << iter <<" "<< error(g)<< endl;
		
    }
    return g;
}
