#include<bits/stdc++.h>
using namespace std;

int btp(int bill){
    int pw = 0;
    if(bill >= 2*100){
        pw += 100;
        bill -= 2*100;
        if(bill >= 3*9900){
            pw += 9900;
            bill -= 3*9900;
            if(bill >= 5*990000){
                pw += 990000;
                bill -= 5*990000;
                pw += bill / 7;
            }else pw += bill / 5;
        }else pw += bill / 3;
    }else pw += bill / 2;
    return pw;
}

int ptb(int pw){
    int bill = 0;
    if(pw >= 100){
        bill += 2*100;
        pw -= 100;
        if(pw >= 9900){
            bill += 3*9900;
            pw -= 9900;
            if(pw >= 990000){
                bill += 5*990000;
                pw -= 990000;
                bill += 7*pw;
            }else bill += 5*pw;
        }else bill += 3*pw;
    }else bill += 2*pw;
    return bill;
}

int main(){

    // freopen("out.txt","w",stdout);
    int a, b;
    while(cin >> a >> b && a && b){
        int total_power = btp(a);
        int begin = 0 , end = total_power;
        int ans = 0;
        while(begin < end){
            int my_power = (begin + end)/2;
            int my_bill = ptb(my_power);
            int nei_bill = ptb(total_power - my_power);
            if(nei_bill - my_bill < b){
                end = my_power;
            }else if(nei_bill - my_bill > b){
                begin = my_power;
            }else{
                ans = ptb(my_power);
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}