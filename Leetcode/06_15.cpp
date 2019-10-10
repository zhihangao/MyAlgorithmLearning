#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

/*
我的第一反应真的就是暴力啊啊啊啊，而且感觉自己没法好的实现查重。
解决这道题的时候明显出现了思路受限。
所以我的第一反应是   看下别人咋想的~
    排序加双指针    的做法真的想不到啊
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solution;
        for(int i = 0;i<nums.size()-2;i++){
            for(int j = i+1;j<nums.size-1;j++){
                for(int k = j+1;k<nums.size();k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        solution.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return solution;
    }
};
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3){
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0){
                break;
            }else
            {
                if( i>0 && nums[i] == nums[i-1]){
                    continue;
                }
                int l = i+1;
                int r = nums.size()-1;
                while(l<r){
                    if(nums[i] + nums[l] + nums[r] == 0){
                        ans.push_back(vector<int>{nums[i], nums[l], nums[r]});
                        while(l<r && nums[l]==nums[l+1]){
                            l++;
                        }
                        while(l<r && nums[r]==nums[r-1]){
                            r--;
                        }
                        l++;
                        r--;
                    }
                    else if(nums[i] + nums[l] + nums[r] < 0)
                    {
                        l++;
                    }else
                    {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};