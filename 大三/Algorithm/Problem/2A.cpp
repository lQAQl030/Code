#include<bits/stdc++.h>
using namespace std;

long long solve(long long a, long long b, long long k, long long low = 0, long long high = 1e18){
    long long mid = (low + high) / 2;
    long long num = mid/a + mid/b - (mid/(a*b))*2;
    if(mid % (a*b) != 0 && (mid % a == 0 || mid % b == 0) && num == k) {
        // cout << low << " " << mid << " " << high << " " << num << endl;
        // cout << "ans----------------";
        return mid;
    }
    else if(num >= k) {
        // cout << low << " " << mid << " " << high << " " << num << endl;
        return solve(a, b, k, low, mid);
    }
    else {
        // cout << low << " " << mid << " " << high << " " << num << endl;
        return solve(a, b, k, mid+1, high);
    }
}

int main(){
    // freopen("out.txt", "w", stdout);
    int t;
    long long a, b, k, common = 1;
    cin >> t;
    for(int i = 0 ; i < t ; i++){
        cin >> a >> b >> k;
        common = __gcd(a,b);
        cout << solve(a/common, b/common, k) * common << endl;
    }
    return 0;
}