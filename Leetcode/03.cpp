#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len[1000][1000];
        int flag = 0;
        int size = 1;
        for(int i=0;i<s.length();i++){
            len[i][i]=1;
            for(int j=0;j<i;j++){
                len[i][j] = 0;
            }
        }
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j] && len[i+1][j-1]==j-i-1){
                    //len[i][j] = max(max(len[i][j-1]+1, len[i+1][j]+1), len[i+1][j-1]+2);
                    len[i][j] = len[i+1][j-1] + 2;
                    if(len[i][j]>size){
                        flag = i; 
                        size = len[i][j];
                    }
                }else{
                    len[i][j] = max(len[i][j-1], len[i+1][j]);
                }
            }
        }
        return s.substr(flag, size);
    }
};