#include<bits/stdc++.h>
using namespace std;
//a
double a[4][4] = {6, -2, 2, 4, 12, -8, 6, 10, 3, -13, 9, 3, -6, 4, 1, -18};
double b[4] = {16, 26, -19, -34};
double x[4] = {0,0,0,0};

void printA(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void printB(){
    for(int i=0; i<4; i++)
        cout << b[i] << " ";
}

int main(){
    for(int n=0; n<4; n++){
        cout<<"Eliminating x"<<n<<endl;
        for(int i=n + 1; i<4; i++){
            int f = a[i][n];
            for(int j=n; j<4; j++){
                a[i][j] -= (f / a[n][n]) * a[n][j];
                
            }
            b[i] -= (f / a[n][n]) * b[n];
        }
    cout << endl;
    printA();
    
    }
    printB();
    cout << endl;
    
    for(int m=3; m > -1; m--){
        int sum = 0;
        for(int j=m; j<4; j++)
            sum += a[m][j] * x[j];
        x[m] = b[m] - sum;
        x[m] /= a[m][m];
        cout << x[m] << " ";
    }
        
    return 0;
}
