#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int x,y;
    while(cin >> x >> y){
        int gcd = __gcd(x,y);
        bool swp = 0;

        if(x > y){
            swap(x,y);
            swp = 1;
        }

        if(x-y == 0){
            x = 0;
            y = 1;
            goto exit;
        }else{

            for(int i = 1 ; ; i++){
                long long int dis = (i*y) % x;
                // cout << "i = " << i << " , j = " << j << " , dis = " << dis << endl;
                if(dis == gcd){
                    x = -((i*y) / x); y = i;
                    break;
                }
            }
        }
        if(swp) swap(x,y);
        exit:
        cout << x << " " << y << " " << gcd << endl;
    }
    
    return 0;
}