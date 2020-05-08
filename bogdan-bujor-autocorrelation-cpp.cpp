#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

void ReadDanubeSignal (double f[], int &n)
{
    ifstream txt;
    double readVar = 0;
    int i = 0;

    txt.open("C:\\Users\\Bogdan\\Documents\\Signal Analysis project\\.vscode\\Signal Analysis - Autocorrelation\\interest-rate\\interest-rate.txt");
    while(txt>>readVar)
    {
        f[i++] = readVar;
    }
    
    n = i;

    txt.close();
}

void WriteSignal (double r[], int N)
{
    ofstream txt;
    txt.open("C:\\Users\\Bogdan\\Documents\\Signal Analysis project\\.vscode\\Signal Analysis - Autocorrelation\\interest-rate\\interest-rate-out.csv");

    for(int i = 0; i<= N/2; i++)
        txt<<i+1<<","<<r[i]<<endl;

}

double CalculateSmallFBarred(double f[], int N, int d)
{
    double sum = 0;
    for(int i = 0; i <= N-d; i++)
    {
        sum = sum + f[i];
    }
    
    return 1.0/(N - d + 1) * sum;
}

double CalculateBigFBarred(double f[], int N, int d)
{
    double sum = 0;
    for(int i = 0; i <= N-d; i++)
    {
        sum = sum + f[d + i];
    }
    
    return 1.0/(N - d + 1) * sum;
}

void CalculateAutocorrelation (double r[], double f[], int N)
{
    int j = 0, d = 0;
    double upperFraction = 0, lowerFraction = 0, finalFraction = 0; //write as upperFraction = Lower =.. =0
    double leftLowerSum = 0, rightLowerSum = 0;
    double smallFBarred = 0, bigFBarred = 0;
    for(d = 0; d <= N/2; d++) //this is the big for, includes the whole fraction, d increments
    {
        finalFraction = 0; //resets every time d increases. d = 0, 1, ... [N/2]
        upperFraction = 0;
        lowerFraction = 0;
        leftLowerSum = 0;
        rightLowerSum = 0;
        
        smallFBarred = CalculateSmallFBarred(f, N, d);
        bigFBarred = CalculateBigFBarred(f, N, d);
        //calculate upper fraction start
        for(j = 0; j <= N-d; j++)
        {
            upperFraction = upperFraction + (f[j] - smallFBarred * (f[d+j] - bigFBarred));
        }
        //calculate upper fraction end
        //calculate lower  fraction start
        for(j = 0; j <= N-d; j++)
        {
            leftLowerSum = leftLowerSum + (f[j] * f[j] - 2 * (f[j] * smallFBarred) + smallFBarred * smallFBarred);
            rightLowerSum = rightLowerSum + (f[d+j] * f[d+j] - 2 * (f[d+j] * bigFBarred) + bigFBarred * bigFBarred);
            //(A-B)^2 = A^2 - 2*A*B + B^2
            lowerFraction = sqrt(leftLowerSum * rightLowerSum);
        }
        //calculate lower fraction end
        
        finalFraction = upperFraction / lowerFraction;

        r[d] = finalFraction;
        cout<<"d = "<<d<<", r[d] = "<<r[d]<<endl;
    }
}


int main(void)
{
    double f[310] = {0};
    int n = 0;
    ReadDanubeSignal(f, n);
    int const N = 309;
    double r[N] = {0};
    CalculateAutocorrelation(r, f, N);
    WriteSignal(r, N);
}