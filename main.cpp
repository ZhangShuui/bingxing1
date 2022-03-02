#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <iostream>
using namespace std;
double a[1000];
double b[1000][1000];
double sum[1000];
void countit(int n){
    for(int i=0;i<n;i++){
        sum[i]=0.0;
        for(int j=0;j<n;j++){
            sum[i]+=b[j][i]*a[i];
        }
    }
}
int main()
{

    for(int i=0;i<1000;i++){
        a[i]=double (i);
        for(int j=0;j<1000;j++){
            b[i][j]=double (i*j);
        }
    }
    int step=10;
    for(int i=10;i<1000;i+=step){
        clock_t start,end;
        start=clock();
        int counter=0;
        while(clock()-start<10){
            counter++;
            countit(i);
        }
        end=clock();
        float seconds=(end-start)/float(CLOCKS_PER_SEC);
        cout<<i<<" "<<counter<<" "<<float (seconds/counter)<<endl;
        if (i==100)
            step=100;
    }
    return 0;
}
