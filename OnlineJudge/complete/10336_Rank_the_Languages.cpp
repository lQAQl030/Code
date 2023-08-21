#include<bits/stdc++.h>
using namespace std;

char grid[100][100] = {};
bool visited[100][100] = {0};

char lrank(int x , int y , int h , int w){
    if(x == h || y == w) return '0';
    visited[x][y] = 1;
    if(grid[x-1][y] == grid[x][y] && !visited[x-1][y]) lrank(x-1,y,h,w);
    if(grid[x+1][y] == grid[x][y] && !visited[x+1][y]) lrank(x+1,y,h,w);
    if(grid[x][y-1] == grid[x][y] && !visited[x][y-1]) lrank(x,y-1,h,w);
    if(grid[x][y+1] == grid[x][y] && !visited[x][y+1]) lrank(x,y+1,h,w);
    return grid[x][y];
}

int main(){

    int n,h,w;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> h >> w;

        for(int j = 0 ; j < h ; j++){
            for(int k = 0 ; k < w ; k++){
                cin >> grid[j][k];
            }
        }
        map<char,int> count;
        for(int j = 0 ; j < h ; j++){
            for(int k = 0 ; k < w ; k++){
                if(visited[j][k] == 0) count[lrank(j,k,h,w)]++;
            }
        }
        
        int max = 0;
        for(map<char,int>::iterator it = count.begin() ; it != count.end() ; it++){
            if(it -> second > max) max = it -> second;
        }
        cout << "World #" << i+1 << endl;
        for(int j = max ; j > 0 ; j--){
            for(map<char,int>::iterator it = count.begin() ; it != count.end() ; it++){
                if(it -> second == j) cout << it -> first << ": " << it -> second << endl;
            }
        }
        memset(visited,0,sizeof(visited));
    }

    return 0;
}