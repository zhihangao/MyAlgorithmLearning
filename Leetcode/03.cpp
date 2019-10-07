#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

/*
这个题动态规划我填的表格太蠢了。
直接填入0/1判断从i到j的字符串是否是回文串，我是填入了回文串长度。
这个长度可以通过i和j得到，因此，一直为了记录长度变化如何更新，这个表格就变得特别奇怪。
*/

class Solution {
public:
	string longestPalindrome(string s) {
		int len[1000][1000];
		int flag = 0;
		int size = 1;
		for (int i = 0; i < s.length(); i++) {
			len[i][i] = 1;
			for (int j = 0; j < i; j++) {
				len[i][j] = 0;
			}
		}
		for (int i = s.length() - 2; i >= 0; i--) {
			for (int j = i + 1; j < s.length(); j++) {
				if (s[i] == s[j] && len[i + 1][j - 1] == j-i-1) {
					//len[i][j] = max(max(len[i][j-1]+1, len[i+1][j]+1), len[i+1][j-1]+2);
					len[i][j] = len[i + 1][j - 1] + 2;
                    if(size<len[i][j]){
                        flag = i;
                        size = len[i][j];
                    }
				}
				else {
					len[i][j] = max(len[i][j - 1], len[i + 1][j]);
				}
			}
		}
		return s.substr(flag, size);
	}
};