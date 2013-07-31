#include "fitness.h"

double fitness(array<double, 100> dmns)
{
    ifstream inrec ("test-data/wbc.csv");
    //ifstream inwts ("weights1.csv");
    //ofstream outrec ("wbcrec.csv");

    // TODO: l,m,n,t say nothing about what the variables are.

    const int size = 10;

    int l, m, n, t;
    double net, toterror = 0.0;
    array<double, 10> a, a1, a2;
    array<array<double, size>, size> w;

    //int a1[50][10000];
    /*
      for(int x=0; x < 100 ; x++){
      cout << dmns[x]<<"  "<< x << endl;
      }
    */

    for(m = 0; m < 10; m++)    { //import the weights
        for(n = 0; n < 10; n++)        {
            w[m][n] = dmns[m*10 + n];
            //cout <<m*10 + n <<" " << dmns[m*10 + n] << endl;
            //cout << w[m][n] << endl ;
        }
    }

    for (l = 0; l < 699 ; l++) { // iterate for each record
        for (m = 0; m < 10; m++)            {// loading the concepts within records
            inrec >> a[m];
            //outrec << a[m] << "\t";
            a2[m] = a[m]; //saving original values to the actual concepts

            //cout << a[m] <<" ";
        }
        //outrec << endl;
        //a[9]=0; // As it is training data
        //cout << endl;
        t = 0;
        while (t < 3) {//total two increments
            // Calculating activation of each function
            for (m = 0; m < 10; m++) {
                for (n=0; n < 10; n++) {
                    net += a[n] * w[n][m];
                }
                //cout << m <<" "<< net <<" " << t << endl;
                a1[m] = 1.0 / (1.0 + exp(net * -0.5));
                //cout << m <<" "<< a1[m] <<" " << t << endl;
            }

            a = a1;
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

        toterror += sqrt(pow(a2[9] - a1[9], 2.0));
        //cout << l << " "<< toterror <<" "<<  a2[9] <<" "<< a1[9] <<endl;
    }

    /*ofstream outwts ("weights1.csv");
      for (m=0; m<10; m++){ // print weights
      for(n=0; n<10; n++){
      //cout << w[m][n] << endl;
      outwts << w[m][n]<<"\t";
      }outwts << "\n";
      }*/
    //cout << toterror/700.0 << endl;
    return toterror / 700.0;
}
