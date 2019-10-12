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
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }
        if(target>=nums[0]){
            int i = 0;
            while(i<nums.size()-1 && nums[i+1]>nums[i]){
                if(nums[i]==target){
                    return i;
                }
                i++;
            }
            if(i<nums.size() && nums[i]==target){
                return i;
            }
        }
        else
        {
            int i = nums.size()-1;
            while (i>0 && nums[i-1]<nums[i])
            {
                if(nums[i]==target){
                    return i;
                }
                i--;
            }
            if(i>=0 && nums[i]==target){
                return i;
            }
        }
        return -1;
    }
};