#include<bits/stdc++.h>
using namespace std;

char field[101][101] = {};
char land[101][101] = {};

char sweep(int x,int y){
    int sum = 0;
    if(field[x][y] == '*') return '*';
    if(field[x-1][y] == '*') sum++;
    if(field[x-1][y-1] == '*') sum++;
    if(field[x-1][y+1] == '*') sum++;
    if(field[x+1][y] == '*') sum++;
    if(field[x+1][y-1] == '*') sum++;
    if(field[x+1][y+1] == '*') sum++;
    if(field[x][y-1] == '*') sum++;
    if(field[x][y+1] == '*') sum++;
    char a = sum + '0';
    return a;
}

int main(){

    int n,m;
    int count = 0;
    while(cin >> n >> m && n && m){
        memset(field , '0' , sizeof(field));

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                cin >> field[i][j];
            }
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                land[i][j] = sweep(i,j);
            }
        }

        if(count) cout << endl;
        count++;
        cout << "Field #" << count << ":" << endl;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                cout << land[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}