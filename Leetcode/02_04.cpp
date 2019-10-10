#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

/*
终于解决了溢出问题：对数组是否越界的问题应该优先判断！！！
这个题最开始的解法写在后面的注释里面，当时的想法是往数组一里面插入数组二的元素，
但是这将要遍历两个数组的所有元素。
我TM怎么就是没想到可以再用一个数组呢。。。
这样一来，创建的新数组只要元素达到一半就可以计算出中位数，没有必要继续填入元素😑
话说，困扰已久的溢出问题，在学会调试以后也就没有那么麻烦了。
*/


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		vector<int> nums3;
		if (len1 == 0) {
			if (len2 % 2 == 0) {
				return (nums2[len2 / 2 - 1] + nums2[len2 / 2]) / 2.0;
			}
			else
			{
				return nums2[len2 / 2];
			}
		}
		else if (len2 == 0)
		{
			if (len1 % 2 == 0) {
				return (nums1[len1 / 2 - 1] + nums1[len1 / 2]) / 2.0;
			}
			else
			{
				return nums1[len1 / 2];
			}
		}
		else
		{
			int count = 0;
			int i = 0;
			int j = 0;
			int len3 = len1 + len2;
			while (count <= len3 / 2) {
				if (i < len1 && j < len2 && nums1[i] < nums2[j]) {
					nums3.push_back(nums1[i++]);
				}
				else if (j < len2)
				{
					nums3.push_back(nums2[j++]);
				}
				else
				{
					nums3.push_back(nums1[i++]);
				}
				count++;
			}
			if (len3 % 2 == 0) {
				return (nums3[len3 / 2 - 1] + nums3[len3 / 2]) / 2.0;
			}
			else
			{
				return nums3[len3 / 2];
			}
		}

	}
};








// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         if(nums1.size()==0){
//             int len2 = nums2.size();
//             if(len2%2==0){
//                 return (nums2[len2/2-1]+nums2[len2/2])/2.0;
//             }
//             else
//             {
//                 return nums2[len2/2];
//             }
//         }
//         else{
//             if(nums2.size()!=0){
//                 int j=0;
//                 for(int i=0;i<nums1.size();i++){
//                     if(nums1[i]>nums2[j]){
//                         nums1.insert(nums1.begin()+i, nums2[j]);
//                         j++;
//                     }
//                 }
//                 for(;j<nums2.size();j++){
//                     nums1.push_back(nums2[j]);
//                 }
//             }
//             int len = nums1.size();
//             if(len%2==0){
//                 return (nums1[len/2]+nums1[len/2-1])/2.0;
//             }
//             else
//             {
//                 return nums1[len/2];
//             }  
//         }
//     }
// };