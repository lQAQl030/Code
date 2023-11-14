#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    int n;
    while(cin >> n && n != 0){
        vector<int> nums;
        int num;
        for(int i = 0 ; i < n ; i++){
            cin >> num;
            nums.push_back(num);
        }
        sort(nums.begin(), nums.end());

        for(int d = n-1 ; d >= 0 ; d--)
        for(int a = 0 ; a < n ; a++){
            for(int b = a+1 ; b < n ; b++){
                for(int c = b+1 ; c < n ; c++){
                    if(nums[a] + nums[b] + nums[c] == nums[d] && a != d && b != d && c != d){
                        cout << nums[d] << endl;
                        goto exit;
                    }
                }
            }
        }
        cout << "no solution" << endl;
        exit:
            continue;
    }
    

    return 0;
}