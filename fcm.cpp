#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
using namespace std;

double fitness(double dmns[])
{
    ifstream inrec ("wbc.csv");
    ifstream inwts ("weights1.csv");
    int l, m, n, t;
    double a[10], a2[10];
    double a1[10], net , w[10][10], toterror = 0.0;
    //int a1[50][10000];
    for(m=0;m<10;m++)    { //import the weights
        for(n=0;n<10;n++)        {
            dmns[m*10 + n] = w[m][n];
            //cout <<m*10 + n <<" " << dmns[m*10 + n] << endl;
        	//inwts >> w[m][n];
            //cout << w[m][n] << endl ;
        }
    }
    for (l = 0; l < 700 ; l++) { // iterate for each record
       //inrec >> a[0] >> a[1] >> a[2] >>a[3] >>a[4] >>a[5] >>a[6] >>a[7] >>a[8] >>a[9];
       //cout << a[l] << " " << b[l] << " " << c[l]<<" " << d[l]<<" " << e[l]<<" " << f[l]<<" " << g[l]<<" " << h[l]<<" " << i[l] << " " << j[l] << endl;
        for (m = 0; m<10; m++)            {// loading the concepts within records
            inrec >> a[m];
            a2[m]=a[m]; //saving original values to the actual concepts

            //cout << a[m] <<" ";
            } a[9]=0; // As it is training data
        //cout << endl;
        t=0;
        while(t<3){//total two increments


        for (m = 0; m < 10; m++)            {//caliculating activation of each func

            for (n=0; n < 10; n++)                {
                 net += a[n]*w[n][m];
                }
            //cout << m <<" "<< net <<" " << t << endl;
            a1[m] = 1/(1+ pow((net*(-1.0)),2)) ;
            //cout << a1[m] <<endl;
            }

        memcpy(a,a1,sizeof(a1));
        /*for (m = 0; m < 10; m++){// updating concepts
            a[m]=a1[m];
            }*/
        //cout << a1[9] << " "<< t<<endl;
        t++;
        }
        /*Here we put The Weight learning Algorithm
                 The Hebbian learning rule */
       /* if ((a2[9]=1.0 && a1[9]<0.5)||(a2[9]<=0.0 && a1[9]>=0.5)){
            for (m=0; m<10; m++){
                for(n=0; n<10; n++){
                    w[n][m] += 0.9*(a2[m]-a1[m])*a2[n];
                }
            }
        }*/

        toterror = toterror + sqrt(pow((a2[9]-a1[9]),2.0));
        //cout << l << " "<< a1[9] <<endl;
        }

        /*ofstream outwts ("weights1.csv");
        for (m=0; m<10; m++){ // print weights
                for(n=0; n<10; n++){
                   //cout << w[m][n] << endl;
                   outwts << w[m][n]<<"\t";
                }outwts << "\n";
                }*/

        return toterror/700.0;
}
void pso(){
    int dmnsns = 100;
    int prtcls = 20;
    double g[dmnsns], p[prtcls][dmnsns], x[prtcls][dmnsns];
    for(int i=0; i < prtcls; i++){
        for(int j = 0; j < dmnsns; j++){
            x[i][j]= ((double)(rand() % 1000))/1000.0;
            cout << x[i][j]<<endl;
        }
    }

    memcpy(p,x,sizeof(x));
    //cout << p[19][98];
    //g[dmnsns] = {0.0};
    for(int i= 0; i < prtcls; i++){
    	cout<< fitness(x[i])<<endl;
    	if ( fitness(p[i]) > fitness( g ) ){
    		//cout << fitness(p[i]) << endl;
    		memcpy(g,p[i],sizeof(p[i]));
    		//cout << "gan"<< endl;
    	}
    }

    //cout << g[39];


}
int main(){
    //fitness();
    pso();
    return 0;
}
