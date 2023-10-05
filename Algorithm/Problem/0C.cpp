#include <iostream>
using namespace std;

int main(){
    long long a, b, m;
    cin >> a >> b >> m;
    long long ans = 1;
    a %= m;
    while(b > 0){
        if(b % 2 == 1){
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    cout << ans;
    return 0;
}