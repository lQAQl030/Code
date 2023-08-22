#include<bits/stdc++.h>
using namespace std;

char mine[10][10] = {};
char hit[10][10] = {};
char sweep[10][10] = {'.'};

void solve(int x , int y){
    int sum = 0;
    if(mine[x-1][y] == '*') sum++;
    if(mine[x-1][y+1] == '*') sum++;
    if(mine[x][y+1] == '*') sum++;
    if(mine[x+1][y+1] == '*') sum++;
    if(mine[x+1][y] == '*') sum++;
    if(mine[x+1][y-1] == '*') sum++;
    if(mine[x][y-1] == '*') sum++;
    if(mine[x-1][y-1] == '*') sum++;
    char a = sum + '0';
    sweep[x][y] = a;
    return;
}

int main(){
    int game;
    cin >> game;
    for(int i = 0 ; i < game ; i++){
        int n;
        bool over = 0;
        cin >> n;
        for(int j = 0 ; j < 10 ; j++){
            for(int k = 0 ; k < 10 ; k++){
                mine[j][k] = '.';
                hit[j][k] = '.';
                sweep[j][k] = '.';
            }
        }
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                cin >> mine[j][k];
            }
        }
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                cin >> hit[j][k];
            }
        }
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                if(hit[j][k] == 'x'){
                    if(mine[j][k] == '*') over = 1;
                    else solve(j,k);
                }
            }
        }
        
        if(i) cout << endl;
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                if(over){
                    if(mine[j][k] == '*') cout << '*';
                    else cout << sweep[j][k];
                }else{
                    cout << sweep[j][k];
                }
            }
            cout << endl;
        }
        continue;
    }


    return 0;
}