#include<bits/stdc++.h>
using namespace std;

long long mergeArr(vector<long long> &a, int low, int mid, int high){
    int n1 = mid - low + 1, n2 = high - mid;
    int right_count = 0;
    long long right_sum = 0;
    vector<long long> left(n1), right(n2);
    for(int i = 0 ; i < n1 ; i++) left[i] = a[low + i];
    for(int i = 0 ; i < n2 ; i++){
        right[i] = a[mid + i + 1];
        right_sum += right[i];
        right_count++;
    }

    // TEST
    // cout << "left" << endl;
    // for(int n : left) cout << n << " "; cout << endl;
    // cout << "right" << endl;
    // for(int n : right) cout << n << " "; cout << endl;

    long long sum = 0;
    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            sum += right_sum - right_count * left[i];
            a[k++] = left[i++];
        }else{
            right_sum -= right[j];
            right_count--;
            a[k++] = right[j++];
        }
    }
    
    while(i < n1) a[k++] = left[i++];
    while(j < n2) a[k++] = right[j++];

    // TEST
    // cout << "array" << endl;
    // for(int n : a) cout << n << " "; cout << endl;
    
    return sum;
}

long long solve(vector<long long> &a, int low, int high){
    long long sum = 0;
    if(low < high){
        int mid = (low + high) / 2;
        sum += solve(a, low, mid);
        sum += solve(a, mid+1, high);
        sum += mergeArr(a, low, mid, high);

        //TEST
        // cout << "------------------------------------" << endl;
    }
    return sum;
}

int main(){
    // FILE *fp1 = freopen("in.txt", "r", stdin);
    // FILE *fp2 = freopen("out.txt", "w", stdout);
    // clock_t start, end;
    // start = clock();

    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    //TEST
    // cout << "------------------------------------" << endl;

    cout << solve(a, 0, n-1) << endl;

    // fclose(fp1);
    // end = clock();
    // double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    // cout << "Time taken by program is : " << fixed 
    //      << time_taken << setprecision(5);
    // cout << " sec " << endl;
    // fclose(fp2);
    return 0;
}