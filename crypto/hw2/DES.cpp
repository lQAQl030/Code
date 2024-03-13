#include<bits/stdc++.h>
using namespace std;

int initial_permutation[] = { 58, 50, 42, 34, 26, 18, 10, 2,
                              60, 52, 44, 36, 28, 20, 12, 4,
                              62, 54, 46, 38, 30, 22, 14, 6,
                              64, 56, 48, 40, 32, 24, 16, 8,
                              57, 49, 41, 33, 25, 17, 9, 1,
                              59, 51, 43, 35, 27, 19, 11, 3,
                              61, 53, 45, 37, 29, 21, 13, 5,
                              63, 55, 47, 39, 31, 23, 15, 7 };

int pc1[] = { 57, 49, 41, 33, 25, 17, 9,
              1, 58, 50, 42, 34, 26, 18,
              10, 2, 59, 51, 43, 35, 27,
              19, 11, 3, 60, 52, 44, 36,
              63, 55, 47, 39, 31, 23, 15,
              7, 62, 54, 46, 38, 30, 22,
              14, 6, 61, 53, 45, 37, 29,
              21, 13, 5, 28, 20, 12, 4 };

int shift_bit[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

int pc2[] = { 14, 17, 11, 24, 1, 5,
              3, 28, 15, 6, 21, 10,
              23, 19, 12, 4, 26, 8,
              16, 7, 27, 20, 13, 2,
              41, 52, 31, 37, 47, 55,
              30, 40, 51, 45, 33, 48,
              44, 49, 39, 56, 34, 53,
              46, 42, 50, 36, 29, 32 };



bitset<64> initialPermutation(bitset<64> plaintext) {
    bitset<64> permuted_text;
    for(int i = 0 ; i < 64 ; i++){
        permuted_text[63 - i] = plaintext[64 - initial_permutation[i]];
    }
    return permuted_text;
}

bitset<56> PC1(bitset<64> key){
    bitset<56> permuted_key;
    for(int i = 0 ; i < 56 ; i++){
        permuted_key[55 - i] = key[64 - pc1[i]];
    }
    return permuted_key;
}

void keyShift(bitset<56> &permuted_key, int shift){
    vector<int> hold(2);
    for(int i = 0 ; i < shift ; i++) hold[i] = permuted_key[i];
    for(int i = shift ; i < 28 ; i++) permuted_key[i - shift] = permuted_key[i];
    for(int i = 28 - shift ; i < 28 ; i++) permuted_key[i] = hold[i + shift - 28];

    for(int i = 0 ; i < shift ; i++) hold[i] = permuted_key[28 + i];
    for(int i = 28 + shift ; i < 56 ; i++) permuted_key[i - shift] = permuted_key[i];
    for(int i = 56 - shift ; i < 56 ; i++) permuted_key[i] = hold[i + shift - 56];

    return;
}

bitset<48> PC2(bitset<56> permuted_key){
    bitset<48> subkey;
    for(int i = 0 ; i < 48 ; i++){
        subkey[47 - i] = permuted_key[56 - pc2[i]];
    }
    return subkey;
}

bitset<64> desEncrypt(bitset<64> plaintext, bitset<64> key){
    bitset<64> permuted_text = initialPermutation(plaintext);
    bitset<56> permuted_key = PC1(key);

    bitset<32> left;
    
    for(int round = 0 ; round < 16 ; round++){
        keyShift(permuted_key, shift_bit[round]);
        bitset<48> subkey = PC2(permuted_key);
    }
}

string stob(string s){
    string b_string;
    for(int i = 0 ; i < s.size() ; i++){
        b_string += bitset<8>(s.c_str()[i]).to_string();
    }
    return b_string;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    string input_str;
    while(getline(cin, input_str, ' ')){
        bitset<64> plaintext(stob(input_str));
        getline(cin, input_str);
        bitset<64> key(stob(input_str));

        bitset<64> ciphertext = desEncrypt(plaintext, key);

        cout << hex << ciphertext.to_ullong() << endl;
    }

    return 0;
}