#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n){
    if(n % 2 == 0){
        return n == 2;
    }else if(n > 2){
        for(int i = 3 ; i <= floor(sqrt(n)) ; i += 2){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

int main(){

    int n = 0;
    vector<int> prime;
    for(int i = 2 ; i <= 10000 ; i++){
        if(is_prime(i)){
            prime.push_back(i);
        }
    }

    while(cin >> n && n){
        int valid = 0;
        for(int i = 0 ; i < prime.size() ; i++){
            int sum = 0;
            sum = 0;
            if(prime[i] > n) break;
            for(int j = i ; j < prime.size() ; j++){
                sum = sum + prime[j];
                if(sum == n){
                    valid++;
                    break;
                }else if(sum > n){
                    break;
                }
            }
        }
        cout << valid << endl;
    }

    return 0;
}