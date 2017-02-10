#include<bits/stdc++.h>
using namespace std;



double arrF_x[2][2];
double arrFx[2];
double X1[2];
double X0[2];
double temp[2];

double f1(double x, double y){
    return (x*x*x) - 3*(x*y*y) + 1;
}

double f2(double x, double y){
    return 3*(x*x*y) - (y*y*y);
}

double f1_x(double x, double y){
    return  3*(x*x) - 3*(y*y);
}

double f1_y(double x, double y){
    return -6*(x*y);
}

double f2_x(double x, double y){
    return 6*(x*y);
}

double f2_y(double x, double y){
    return 3*(x*x) - 3*(y*y);
}

void inverse(double arr[2][2]){
    double det = (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);
    //switch a,da
    arr[0][0] = arr[0][0] + arr[1][1];
    arr[1][1] = arr[0][0] - arr[1][1];
    arr[0][0] = arr[0][0] - arr[1][1];
    //reverse signs b,c
    arr[0][1] *= -1;
    arr[1][0] *= -1;
    //devide by det
    arr[0][0] /= det;
    arr[0][1] /= det;
    arr[1][0] /= det;
    arr[1][1] /= det;
    
    arrF_x[0][0] = arr[0][0];
    arrF_x[0][1] = arr[0][1];
    arrF_x[1][0] = arr[1][0];
    arrF_x[1][1] = arr[1][1];
}

void multiply(double arr1[2][2], double arr2[2]){
    double arr[2];
    arr[0] = (arr1[0][0] * arr2[0]) + (arr1[0][1] * arr2[1]);
    arr[1] = (arr1[1][0] * arr2[0]) + (arr1[1][1] * arr2[1]);
    
    temp[0] = arr[0];
    temp[1] = arr[1];
    
}

void printFx(){
    cout<<"Fx"<<endl;
    cout << arrFx[0] << endl;
    cout << arrFx[1] << endl;
    cout<<endl;
}

void printF_x(){
    cout<<"F_x"<<endl;
    cout << arrF_x[0][0] << " " << arrF_x[0][1] << endl;
    cout << arrF_x[1][0] << " " << arrF_x[1][1] << endl;
    cout<<endl;
}

void printTemp(){
    cout<<"temp"<<endl;
    cout << temp[0] << endl;
    cout << temp[1] << endl;
    cout<<endl;
}

void makeF_x(double x0, double y0){
    arrF_x[0][0] = f1_x(x0, y0);
    arrF_x[0][1] = f1_y(x0, y0);
    arrF_x[1][0] = f2_x(x0, y0);
    arrF_x[1][1] = f2_y(x0, y0);
}

void makeFx(double x0, double y0){
    arrFx[0] = f1(x0, y0);
    arrFx[1] = f2(x0, y0);
}

int main(){
    double x0 = 0.25, y0 = 0.25;
    X0[0] = x0;
    X0[1] = y0;
    makeFx(x0, y0);
    makeF_x(x0, y0);
    printF_x();
    
    int count = 100;
    
    while(count--){
        //X1 = X0 - inv(F_x)*F;
    
        inverse(arrF_x);
        printF_x();
    
        multiply(arrF_x, arrFx);
        printTemp();
        
        X1[0] = X0[0] - temp[0];
        X1[1] = X0[1] - temp[1];       
        X0[0] = X1[0];
        X0[1] = X1[1];
        makeF_x(X0[0], X0[1]);
        makeFx(X0[0], X0[1]);
    }
    
    cout << X1[0] << " " << X1[1] << " " << f1(X0[0], X0[1]) << " " <<f2(X0[0], X0[1]) << endl;
    return 0;
}
