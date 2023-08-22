#include<bits/stdc++.h>
using namespace std;

class pq{
    public:
        int val;
        int pos;
    public:
        pq(){}
        pq(int _val , int _pos):val(_val),pos(_pos){}
        bool operator<(const pq &q) const{
            return val > q.val;
        }
};

int main()
{
    // freopen("out.txt" , "w" , stdout);
    int n,a[760],b[670];
    while (cin >> n)
    {
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        sort(a,a+n);

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++)
                cin >> b[j];
            sort(b,b+n);

            priority_queue<pq> q;
            for(int j = 0 ; j < n ; j++){
                q.push({a[j] + b[0] , 0});
            }
            for(int j = 0 ; j < n ; j++){
                pq tmp = q.top();
                q.pop();
                a[j] = tmp.val;
                if(tmp.pos+1 < n){
                    q.push({tmp.val - b[tmp.pos] + b[tmp.pos+1] , tmp.pos+1});
                }
            }
        }
        for(int i = 0 ; i < n-1 ; i++){
            cout << a[i] << " ";
        }
        cout << a[n-1] << endl;
    }
    
    return 0;
}