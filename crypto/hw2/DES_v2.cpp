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

int E_TABLE[] = { 32, 1, 2, 3, 4, 5,
                  4, 5, 6, 7, 8, 9,
                  8, 9, 10, 11, 12, 13,
                  12, 13, 14, 15, 16, 17,
                  16, 17, 18, 19, 20, 21,
                  20, 21, 22, 23, 24, 25,
                  24, 25, 26, 27, 28, 29,
                  28, 29, 30, 31, 32, 1 };

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

int S_BOXES[8][4][16] = {
    {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    },
    {
        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
        {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
        {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
        {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
    },
    {
        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
        {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
        {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
        {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
    },
    {
        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
    },
    {
        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
    },
    {
        {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
        {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
        {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
        {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
    },
    {
        {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
        {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
        {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
        {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
    },
    {
        {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
        {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
        {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
        {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
    }
};

int P_BOX[] = { 16, 7, 20, 21,
                29, 12, 28, 17,
                1, 15, 23, 26,
                5, 18, 31, 10,
                2, 8, 24, 14,
                32, 27, 3, 9,
                19, 13, 30, 6,
                22, 11, 4, 25 };

int final_permutation[] = { 40, 8, 48, 16, 56, 24, 64, 32,
                             39, 7, 47, 15, 55, 23, 63, 31,
                             38, 6, 46, 14, 54, 22, 62, 30,
                             37, 5, 45, 13, 53, 21, 61, 29,
                             36, 4, 44, 12, 52, 20, 60, 28,
                             35, 3, 43, 11, 51, 19, 59, 27,
                             34, 2, 42, 10, 50, 18, 58, 26,
                             33, 1, 41, 9, 49, 17, 57, 25 };

bitset<64> initialPermutation(bitset<64> plaintext) {
    bitset<64> permuted_text;
    for(int i = 0 ; i < 64 ; i++){
        permuted_text[63 - i] = plaintext[64 - initial_permutation[i]];//
    }
    // cout << "initP: " << permuted_text << endl;//test
    return permuted_text;
}

bitset<48> expansionPbox(bitset<32> bitstr){
    bitset<48> expanded;
    for(int i = 0 ; i < 48 ; i++){
        expanded[47 - i] = bitstr[32 - E_TABLE[i]];//
    }
    // cout << "expand: " << expanded << endl;//test
    return expanded;
}

bitset<56> PC1(bitset<64> key){
    bitset<56> permuted_key;
    for(int i = 0 ; i < 56 ; i++){
        permuted_key[55 - i] = key[64 - pc1[i]];//
    }
    // cout << "key : " << key << endl;//test
    // cout << "Per : " << permuted_key << endl;//test
    return permuted_key;
}

void keyShift(bitset<56> &permuted_key, int shift){
    // cout << hex << uppercase << permuted_key << endl;//test
    bitset<28> left, right;
    for(int i = 0 ; i < 28 ; i++){
        left[i] = permuted_key[i];
        right[i] = permuted_key[i + 28];
    }
    left = left << shift | left >> (28-shift);
    right = right << shift | right >> (28-shift);
    for(int i = 0 ; i < 28 ; i++){
        permuted_key[i] = left[i];
        permuted_key[i + 28] = right[i];
    }
    // cout << "key: " << permuted_key << endl;//test
    return;
}

bitset<48> PC2(bitset<56> permuted_key){
    bitset<48> subkey;
    for(int i = 0 ; i < 48 ; i++){
        subkey[47 - i] = permuted_key[56 - pc2[i]];//
    }
    // cout << "pc2: " << subkey << endl;//test
    return subkey;
}

bitset<32> Sbox(bitset<48> first_xor){
    bitset<32> substituted;
    for(int box = 0 ; box < 8 ; box++){
        bitset<6> input;
        for(int i = 0 ; i < 6 ; i++) input[5 - i] = first_xor[(7 - box) * 6 + 5 - i];
        // cout << input << " ";//test

        int row = (((input & bitset<6>("100000")) >> 4) | (input & bitset<6>("000001"))).to_ulong();
        int col = ((input & bitset<6>("011110")) >> 1).to_ulong();
        // cout << dec << "row = " << row << ", col = " << col << endl;//test

        bitset<4> output(S_BOXES[box][row][col]);
        // cout << "bit: " << output << endl;//test
        for(int i = 0 ; i < 4 ; i++) substituted[(7 - box) * 4 + i] = output[i];
    }
    // cout << endl;//test
    return substituted;
}

bitset<32> strightPbox(bitset<32> substituted){
    bitset<32> f_func;
    for(int i = 0 ; i < 32 ; i++){
        f_func[31 - i] = substituted[32 - P_BOX[i]];//
    }
    return f_func;
}

bitset<64> desEncrypt(bitset<64> plaintext, bitset<64> key){
    bitset<64> permuted_text = initialPermutation(plaintext);
    bitset<56> permuted_key = PC1(key);

    bitset<32> left, right, temp;
    // cout << permuted_text << endl;//test
    for(int i = 0 ; i < 32 ; i++) right[i] = permuted_text[i];
    for(int i = 32 ; i < 64 ; i++) left[i-32] = permuted_text[i];
    // cout << hex << uppercase << left << " " << right << endl;//test
    
    for(int round = 0 ; round < 16 ; round++){
        temp = right;

        bitset<48> expanded = expansionPbox(right);

        keyShift(permuted_key, shift_bit[round]);
        bitset<48> subkey = PC2(permuted_key);
        // cout << hex << uppercase << subkey.to_ullong() << endl;//test

        bitset<48> first_xor = expanded ^ subkey;
        // cout << "first_xor: " << first_xor << endl;//test
        
        bitset<32> substituted = Sbox(first_xor);
        // cout << "Sbox: " << substituted << endl;//test

        bitset<32> permuted = strightPbox(substituted);
        // cout << "Permutation: " << permuted << endl;//test

        right = left ^ permuted;
        left = temp;
        // cout << hex << uppercase << left.to_ullong() << " " << right.to_ullong() << endl;//test
    }

    bitset<64> swapped;
    for(int i = 0 ; i < 32 ; i++) swapped[i] = left[i];
    for(int i = 0 ; i < 32 ; i++) swapped[i + 32] = right[i];
    // cout << "swap: " << swapped << endl;//test

    bitset<64> ciphertext;
    for(int i = 0 ; i < 64 ; i++){
        ciphertext[63 - i] = swapped[64 - final_permutation[i]];//
    }
    return ciphertext;
}

bitset<64> desDecrypt(bitset<64> ciphertext, bitset<64> key){
    
}

string stob(string s){
    string b_string = "";
    for(int i = 0 ; i < s.size() ; i++){
        b_string += bitset<8>(s.c_str()[i]).to_string();
    }
    return b_string;
}

bitset<64> htob(string s){
    string b_string;
    stringstream ss;
    ss << hex << s;
    unsigned long long n;
    ss >> n;
    return bitset<64>(n);
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    string input_str;
    for(int i = 0 ; i < 5 ; i++){
        getline(cin, input_str, ' ');
        bitset<64> key(stob(input_str));
        // bitset<64> key(htob(input_str));//hex input
        getline(cin, input_str);
        bitset<64> plaintext(stob(input_str));
        // bitset<64> plaintext(htob(input_str));//hex input

        bitset<64> ciphertext = desEncrypt(plaintext, key);

        cout << hex << uppercase << setw(16) << setfill('0') << ciphertext.to_ullong();
        if(i < 4) cout << endl;
    }

    return 0;
}