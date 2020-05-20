//
//  main.cpp
//  assignment 2
//
//  Created by Toka Magdy on 3/10/20.
//  Copyright © 2020 Toka Magdy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

char charXor(char first, char second) {
    if (first == second)
        return '0';
    return '1';
}

string stringXor(string first, string second) {
    string result = "";
    
    for (int i = 0; i < first.length(); i++)
        result += charXor(first[i], second[i]);
    
    return result;
}

int getDecimal(string num) {
    int decimalNumber = 0, j = 0, temp;
    for (int i = num.length()-1; i >= 0; i--) {
        if (num[j] == '0')
            temp = 0;
        else temp = 1;
        decimalNumber += temp * pow(2, i);
        j++;
    }
    return decimalNumber;
}

string getBinary(int num) {
    string binary = "";
    
    while (num > 0) {
        if (num%2 == 0)
            binary += '0';
        else binary += '1';
        
        num /= 2;
    }
    reverse(binary.begin(), binary.end());
    while (binary.length() < 4)
        binary = '0' + binary;
    return binary;
}

string sbox(string key) {
    string result = "";
    
    int s1[4][16] = {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7}, {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8}, {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0}, {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}};
    int s2[4][16] = {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10}, {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5}, {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15}, {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}};
    int s3[4][16] = {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8}, {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1}, {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7}, {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}};
    int s4[4][16] = {{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15}, {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9}, {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4}, {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}};
    int s5[4][16] = {{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9}, {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6}, {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14}, {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}};
    int s6[4][16] = {{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11}, {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8}, {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6}, {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}};
    int s7[4][16] = {{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1}, {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6}, {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2}, {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}};
    int s8[4][16] = {{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7}, {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2}, {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8}, {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}};
    
    int c = 0, num;
    for (int i = 0; i < 8; i++) {
        string sub = key.substr(c,6);
        int row = getDecimal(sub.substr(0,1) + sub.substr(5,1));
        int col = getDecimal(sub.substr(1, 4));
        
        if (i == 0)
            num = s1[row][col];
        else if (i == 1)
            num = s2[row][col];
        else if (i == 2)
            num = s3[row][col];
        else if (i == 3)
            num = s4[row][col];
        else if (i == 4)
            num = s5[row][col];
        else if (i == 5)
            num = s6[row][col];
        else if (i == 6)
            num = s7[row][col];
        else num = s8[row][col];
        result += getBinary(num);
        c += 6;
    }
    return result;
}

string expand(string key) {
    int eBitSelectionTable[8][6] = {{32, 1, 2, 3, 4, 5}, {4, 5, 6, 7, 8, 9}, {8, 9, 10, 11, 12, 13}, {12, 13, 14, 15, 16, 17}, {16, 17, 18, 19, 20, 21}, {20, 21, 22, 23, 24, 25}, {24, 25, 26, 27, 28, 29},{28, 29, 30, 31, 32, 1}};
    string result = "";
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 6; j++)
            result += key[eBitSelectionTable[i][j]-1];
    
    return result;
}

string p(string key) {
    int p[8][4] = {{16, 7, 20, 21}, {29, 12, 28, 17}, {1, 15, 23, 26}, {5, 18, 31, 10}, {2, 8, 24, 14}, {32, 27, 3, 9}, {19, 13, 30, 6}, {22, 11, 4, 25}};
    string result = "";
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 4; j++)
            result += key[p[i][j]-1];
    return result;
}

int main(int argc, const char * argv[]) {
    int pc1[8][7] = {{57, 49, 41, 33, 25, 17, 9}, {1, 58, 50, 42, 34, 26, 18},
        {10, 2, 59, 51, 43, 35, 27}, {19, 11, 3, 60, 52, 44, 36},
        {63, 55, 47, 39, 31, 23, 15}, {7, 62, 54, 46, 38, 30, 22},
        {14, 6, 61, 53, 45, 37, 29}, {21, 13, 5, 28, 20, 12, 4}};
    
    int pc2[8][6] = {{14, 17, 11, 24, 1, 5},{3, 28, 15, 6, 21, 10},{23, 19, 12, 4, 26, 8},{16, 7, 27, 20, 13, 2}, {41, 52, 31, 37, 47, 55}, {30, 40, 51, 45, 33, 48}, {44, 49, 39, 56, 34, 53}, {46, 42, 50, 36, 29, 32}};
    
    int ip[8][8] = {{58, 50, 42, 34, 26, 18, 10, 2}, {60, 52, 44, 36, 28, 20, 12, 4}, {62, 54, 46, 38, 30, 22, 14, 6}, {64, 56, 48, 40, 32, 24, 16, 8}, {57, 49, 41, 33, 25, 17, 9, 1}, {59, 51, 43, 35, 27, 19, 11, 3}, {61, 53, 45, 37, 29, 21, 13, 5}, {63, 55, 47, 39, 31, 23, 15, 7}};
    
    int numOfShifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    
    int ipInverse[8][8] = {{40, 8, 48, 16, 56, 24, 64, 32}, {39, 7, 47, 15, 55, 23, 63, 31}, {38, 6, 46, 14, 54, 22, 62, 30}, {37, 5, 45, 13, 53, 21, 61, 29}, {36, 4, 44, 12, 52, 20, 60, 28}, {35, 3, 43, 11, 51, 19, 59, 27}, {34, 2, 42, 10, 50, 18, 58, 26}, {33, 1, 41, 9, 49, 17, 57, 25}};
    
    string key = "0001001100110100010101110111100110011011101111001101111111110001", pcKey = "", cd[17], pc2key[16];
    string message = "0000000100100011010001010110011110001001101010111100110111101111", ipMessage = "", encryptedData = "", originalMessage = "", finalBlock;
    
    //key generation
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 7; j++)
            pcKey += key[pc1[i][j]-1];
    
    vector<string> c, d, l, r, l2, r2;
    c.push_back(pcKey.substr(0,28));
    d.push_back(pcKey.substr(28, 28));
    
    for (int i = 1; i <= 16; i++) {
        int num = numOfShifts[i-1];
        c.push_back(c[i-1].substr(num, 28-num) + c[i-1].substr(0,num));
        d.push_back(d[i-1].substr(num, 28-num) + d[i-1].substr(0,num));
    }
    
    for (int i = 1; i <= 16; i++) {
        cd[i] = c[i] + d[i];
        pc2key[i] = "";
        
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < 6; k++)
                pc2key[i] += cd[i][pc2[j][k]-1];
    }
    
    //encryption
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            ipMessage += message[ip[i][j]-1];
    
    l.push_back(ipMessage.substr(0, 32));
    r.push_back(ipMessage.substr(32, 32));
    
    for (int i = 1; i <= 16; i++) {
        l.push_back(r[i-1]);
        r.push_back(stringXor(l[i-1], p(sbox(stringXor(pc2key[i], expand(r[i-1]))))));
    }
    
    finalBlock = r[16] + l[16];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            encryptedData += finalBlock[ipInverse[i][j]-1];
    
    cout << "encrypted data: " << encryptedData << endl;
    
    //decryption
    ipMessage = "";
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            ipMessage += encryptedData[ip[i][j]-1];
    
    l2.push_back(ipMessage.substr(0, 32));
    r2.push_back(ipMessage.substr(32, 32));
    
    for (int i = 16, j = 1; i > 0; i--, j++) {
        l2.push_back(r2[j-1]);
        r2.push_back(stringXor(l2[j-1], p(sbox(stringXor(pc2key[i], expand(r2[j-1]))))));
    }
    
    finalBlock = r2[16] + l2[16];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            originalMessage += finalBlock[ipInverse[i][j]-1];
    
    cout << "original message: " << originalMessage << endl;
    
    return 0;
}
