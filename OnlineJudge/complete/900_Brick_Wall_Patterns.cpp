#include<bits/stdc++.h>
using namespace std;

double fact(int n,int a,int b){
    // cout << "n = " << n << " , a = " << a << " , b = " << b << endl;
    if(n == 0 || n == 1) return 1;
    if(b > a) swap(a,b);
    double sum = 1;
    for(int i = n ; i > a ; i--){
        sum *= i;
        sum /= (i-a);
    }
    // cout << fixed << "fact c = " << sum << endl;
    // cout << fixed << "ceil = " << ceil(sum) << endl;
    return sum;
}

double solve(int n){
    int b = 1;
    double sum = 1;
    for(int i = n-2 ; i >= 0 ; i -= 2){
        sum += fact(i+b,i,b);
        // cout << "part = " << sum << endl;
        b++;
    }
    return sum;
}

int main(){

    int n;
    while(cin >> n && n){
        cout << fixed << setprecision(0) << solve(n) << endl;
    }

    return 0;
}

//easier way is to count the fibonacci sequence(I was stupid qwq)