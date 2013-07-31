#include "pso.h"

array<double, 100> pso(double epsilon, double omega, double phyp, double phyg) {
    const int dmnsns = 100, prtcls = 20;

    array<double, dmnsns> g;
    array<array<double, dmnsns>, prtcls> p, x, v;

    for(int i=0; i < prtcls; i++){
        for(int j = 0; j < dmnsns; j++){
            x[i][j] = -1000.0 + ((rand()%10000)/10000.0)*2000.0 ;
            v[i][j] = -2000.0 + ((rand()%10000)/10000.0)*4000.0;
            g[j] = 0.0;
            //cout << x[i][j] <<endl;
        }
    }

    p = x;
    /*for(int x=0; x < 100; x++){
      cout << x <<"  "<< p[0][x] << endl;
      }*/

    for(int i= 0; i < prtcls; i++){// initializng global best

    	//double temp[dmnsns];
    	//memcpy(temp,p[i],sizeof(p));
    	/*for(int x=0; x < 100; x++){
          cout << x <<"  "<< temp[x] << endl;
          }*/
    	//cout<< fitness(g)<<endl;
    	if ( fitness(p[i]) < fitness(g) ){
    		//cout << fitness(p[i]) << endl;
    		g = p[i];
    		//cout << "in loop";
    	}
    }
    
    while(fitness(g) < epsilon){
        for(int i= 0; i < prtcls; i++){
            for(int j = 0; j < dmnsns; j++){
                double rp = (rand()%1000)/1000.0;
                double rg = (rand()%1000)/1000.0;
                v[i][j] = omega * v[i][j] + phyp*rp*(p[i][j] - x[i][j]) + phyg*rg*(g[j] - x[i][j]) ;
                x[i][j] += v[i][j];
            }
            if (fitness(p[i]) < fitness(x[i])){
                p[i] = x[i];
            }
            if (fitness(g) < fitness(p[i])){
                g = p[i];
            }
        }
    }
    return g;
}
