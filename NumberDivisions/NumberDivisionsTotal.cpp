#include <iostream>
#include <math.h>
#include <chrono>
using namespace std;

int division(int k, int n){
    if(k==n || n==1){return 1;}
    else if(n>k ||  n<=0 || k<=0){
        return 0;
    }
    else{
        int sum=0;
        for(int i=1; i<=n; i++){
            sum+=division(k-n, i);
        }
        //sum=100;
        return sum;
    }
}

int main() {
cout<<"Interesuje mnie liczba roznych zapisow liczby k jako sumy niezerowych skladnikow."<<endl;

int number;
cout<<"k = ";
cin>>number;

    auto start = chrono::steady_clock::now();

int part=0;
for(int i=1; i<=number; i++){
    part+=division(number, i);
}
cout<<"Istnieje "<<part<<" takich zapisow."<<endl;
    auto end = chrono::steady_clock::now();
cout<<"Obliczenia zajely "<<chrono::duration_cast<chrono::microseconds>(end - start).count()<<" mikrosekund."<<endl;

cout<<endl;
cout << "Press any key to exit.";
cin.ignore();
cin.get();
return 0;
}