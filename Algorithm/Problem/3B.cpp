#include<bits/stdc++.h>
using namespace std;

int main(){
    // freopen("./out.txt", "w", stdout);
    int q, k, task;
    priority_queue<int, vector<int>, greater<int>> arr;
    priority_queue<int, vector<int>> kth;
    cin >> q >> k;
    for(int i = 0 ; i < q ; i++){
        cin >> task;
        if(task == 1){
            cin >> task;
            if(kth.size() == 0) kth.push(task);
            else if(kth.size() == k){
                if(kth.top() > task){
                    arr.push(kth.top());
                    kth.pop();
                    kth.push(task);
                }else{
                    arr.push(task);
                }
            }else{
                kth.push(task);
            }
        }else{
            if(kth.size() < k) cout << -1 << endl;
            else{
                cout << kth.top() << endl;
                kth.pop();
                if(!arr.empty()){
                    kth.push(arr.top());
                    arr.pop();
                }
                
            }
        }
    }

    return 0;
}