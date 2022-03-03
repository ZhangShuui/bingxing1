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
        long long start,end,freq;
        int counter=0;
        QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
        QueryPerformanceCounter((LARGE_INTEGER*)&start);
        QueryPerformanceCounter((LARGE_INTEGER*)&end);
        while(end-start<100000){
            counter++;
            countit(i);
            QueryPerformanceCounter((LARGE_INTEGER*)&end);
        }
        cout<<i<<","<<counter<<","<<double (end-start)/ double (freq)<<","<<double (end-start)/double (freq)/(double)counter<<endl;
        if (i==100)
            step=100;
    }
    return 0;
}
