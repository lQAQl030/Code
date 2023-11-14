#include <bits/stdc++.h>
using namespace std;

#define msize 100000

vector<pair<int,int>> maja(msize);
vector<pair<int,int>> ways = {{0,1},{-1,1},{-1,0},{0,-1},{1,-1},{1,0}};

void bee(){
    maja[1] = {0,0};
    int way = 0;
    int count = 1;
    int i = 2;
    while(i < msize){
        int times = (way == 1) ?count-1 :count;
        for(int j = 0 ; j < times ; j++){
            maja[i] = {maja[i-1].first + ways[way].first, maja[i-1].second + ways[way].second};
            i++;
            if(i >= msize) break;
        }
        if(++way >= 6){
            way %= 6;
            count++;
        }
    }
};


int main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    bee();
    int n;
    while(cin >> n) cout << maja[n].first << " " << maja[n].second << endl;

    return 0;
}