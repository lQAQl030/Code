class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> visited;
        int x = 0, y = 0;
        visited.insert({0,0});
        for(char &c : path){
            if(c == 'N') y++;
            else if(c == 'S') y--;
            else if(c == 'E') x++;
            else x--;

            pair<int,int> temp = {x,y};
            if(visited.find(temp) == visited.end()) visited.insert(temp);
            else return true;
        }

        return false;
    }
};