#include<bits/stdc++.h>
using namespace std;

struct info{
    int low,high;
    long long int sum;
    info(): low(0), high(0), sum(0){}
    info(int low, int high, long long int sum): low(low), high(high), sum(sum){}
};

info find_max_cross_subarr(int* a, int low, int mid, int high){
    long long int leftsum = -LLONG_MAX, rightsum = -LLONG_MAX, sum = 0;
    int maxleft = 0, maxright = 0;

    for(int i = mid ; i >= low ; i--){
        sum += a[i];
        if(sum > leftsum){
            leftsum = sum;
            maxleft = i;
        }
    }

    sum = 0;
    for(int j = mid + 1 ; j <= high ; j++){
        sum += a[j];
        if(sum > rightsum){
            rightsum = sum;
            maxright = j;
        }
    }

    return info(maxleft, maxright, leftsum + rightsum);
}

info find_max_subarr(int* a, int low, int high){
    int mid = 0;
    if(high == low) return info(low, high, a[low]);
    else mid = (low + high) / 2;

    info left = find_max_subarr(a, low, mid);
    info right = find_max_subarr(a, mid + 1, high);
    info cross = find_max_cross_subarr(a, low, mid, high);

    if(left.sum >= right.sum && left.sum >= cross.sum) return left;
    else if(right.sum >= left.sum && right.sum >= cross.sum) return right;
    else return cross;
}

int main(){

    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    info ans = find_max_subarr(a, 0, n-1);
    
    cout << ans.sum << endl << ++ans.low << " " << ++ans.high << endl;

    return 0;
}