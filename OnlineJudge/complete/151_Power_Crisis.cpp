#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){

    int n, m, off = 0;

    while(cin >> n && n != 0){
        n--;
        for(m = 1; m < n; m++){
            off = 0;
            for(int i = 1; i <= n ; i++){
                off = (off + m)%i;
            }
            if(off == 11) break;
        }
        cout << m << endl;
    }

    return 0;
}