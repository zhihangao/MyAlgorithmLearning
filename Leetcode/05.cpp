#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

/*
直接暴力做，循环遍历所有开始和结束的情况，这个是我的思路。
但是提交的结果很不理想，1732ms蹦出来吓一大跳。
想康康别人是怎么写的。
评论提到了双指针，我之前想到过，但是觉得双指针最后好像还是沦为了暴力
看了别人的做法，发现指针的移动和转移的条件还有初始化都没想明白。
两条垂直线的距离越远越好，高度越高越好。
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0; 
        int j = height.size() - 1;
        int maxArea = (j - i) * min(height[i], height[j]);
        while(i < j){
            if(height[i] < height[j]){
                i++;
            }else
            {
                j--;
            }
            maxArea = max(maxArea, (j - i) * min(height[i], height[j]));
        }
        return maxArea;
    }
};




// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int area = 0;
//         int maxArea = 0;
//         for(int i=0;i<height.size()-1;i++){
//             for(int j = i+1;j<height.size();j++){
//                 if(height[j]<height[i]){
//                     area = (j-i)*height[j];
//                 }else
//                 {
//                     area = (j-i)*height[i];
//                 }
//                 if(maxArea< area){
//                     maxArea = area;
//                 }
//             }
//         }
//         return maxArea;
//     }
// };