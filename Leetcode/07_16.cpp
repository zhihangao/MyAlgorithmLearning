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
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[nums.size()-1];
        for(int i=0;i<nums.size()-2;i++){
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum>target){
                    r--;
                }else if(sum<target){
                    l++;
                }else{
                    ans = target;
                    break;
                }
                if(abs(sum-target)<abs(ans-target)){
                    ans = sum;
                }
            }
            if(ans == target){
                break;
            }
        }
        return ans;
    }
};