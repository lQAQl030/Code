#include<bits/stdc++.h>
using namespace std;

bool land[100][100] = {};
int cland[100][100] = {};

void count(int m , int n){
    int sum = 0;
    for(int i = 0; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = j; k < n ; k++){
                if(land[i][k] == 0) sum++;
                else break;
            }
            cland[i][j] = sum;
            sum = 0;
        }
    }
}

int main(){

    int m, n;
    while(cin >> m >> n && m && n){
        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                cin >> land[i][j];
            }
        }
        // cout << "-------------------------" << endl;

        int max = 0;
        int current = 0;
        int cx = 101;
        int sum = 0;
        bool flag = 0;
        count(m,n);
        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                for(int k = i ; k < m ; k++){
                    if(cland[k][j]){
                        if(cland[k][j] < cx){
                            cx = cland[k][j];
                        }
                        flag = 1;
                        sum++;
                    }
                    else break;
                    if(flag){
                    current = cx * sum;
                    if(current > max) max = current;
                    // cout << cx << " " << sum << " " << current << " " << max << endl;
                    
                    current = 0;
                }
                }
                cx = 101;
                    flag = 0;
                    sum = 0;
            }
        }


        // cout << "-------------------------" << endl;
        // for(int i = 0; i < m ; i++){
        //     for(int j = 0 ; j < n ; j++){
        //         cout << cland[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << max << endl;
    }

}