#include<bits/stdc++.h>
using namespace std;

class Vector{
    private:
        int x, y, z;
    public:
        Vector(){}
        Vector(int x, int y, int z):x(x),y(y),z(z){}
        Vector operator+(Vector &v);
        Vector operator-(Vector &v);
        int operator*(Vector &v);
        friend ostream &operator<<(ostream &out, const Vector &v);
};

Vector Vector::operator+(Vector &v){
    Vector sum;
    sum.x = x + v.x;
    sum.y = y + v.y;
    sum.z = z + v.z;
    return sum;
}

Vector Vector::operator-(Vector &v){
    Vector sum;
    sum.x = x - v.x;
    sum.y = y - v.y;
    sum.z = z - v.z;
    return sum;
}

int Vector::operator*(Vector &v){
    int sum = x * v.x + y * v.y + z * v.z;
    return sum;
}

ostream &operator<<(ostream &out, const Vector &v){
    out << v.x << " " << v.y << " " << v.z;
    return out;
}

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    Vector v1(x, y, z);
    cin >> x >> y >> z;
    Vector v2(x, y, z);

    string oper;
    while(cin >> oper){
        if(oper == "add"){
            cout << v1 + v2 << endl;
        }else if(oper == "sub"){
            cout << v1 - v2 << endl;
        }else if(oper == "dot"){
            cout << v1 * v2 << endl;
        }else{
            cout << "Invalid operation: " << oper << endl;
        }
    }

    return 0;
}


