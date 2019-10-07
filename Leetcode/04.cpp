#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

/*
这个题就是要不停地防止溢出，同时一定要记得加的时候要转换字符到数字减去48.
这里最让人烦的地方在最后214748364后判断溢出。
如果后面这个数小于7/8那么是没有溢出的。此时要注意：
得先转换字符到数字，也就是说，得先减去48，不然还是会溢出。
*/

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()){
            return 0;
        }
        else
        {
            int solution = 0;
            int cursor = 0;
            str.erase(0, str.find_first_not_of(" "));
            if(str[0]==45 || str[0]==43){
                cursor = 1;
            }
            while(cursor<str.length() && str[cursor]>47 && str[cursor]<58){
                solution = solution*10 + (str[cursor]-48);
                cursor++;
                if(solution>=214748364){
                    break;
                }
            }
            if(cursor>=str.length() || str[cursor]<=47 || str[cursor]>=58){
                if(str[0]==45){
                    return solution*(-1);
                }else
                {
                    return solution;
                }
            }
            else{
                if(solution==214748364){
                    if(str[0]==45 && str[cursor]<56){
                        solution = (solution*10 + (str[cursor] - 48))*(-1);
                        cursor++;
                    }else if(str[cursor]<55){
                        solution = solution*10 + (str[cursor] - 48);
                        cursor++;
                    }
                    if(cursor>=str.length() || str[cursor]<=47 || str[cursor]>=58){
                        return solution;
                    }
                }
                if(str[0]==45){
                    return INT_MIN;
                }else
                {
                    return INT_MAX;
                }
            }
        }
    }
};