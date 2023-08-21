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