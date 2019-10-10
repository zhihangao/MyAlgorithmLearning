#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }else if(l2==NULL){
            return l1;
        }else{
            ListNode* cursor1 = l1;
            ListNode* cursor2 = l2;
            int sum;
            int carry = 0;
            while(cursor1->next!=NULL&&cursor2->next!=NULL){
                sum = cursor1->val + cursor2->val +carry;
                cursor1->val = sum%10;
                if(sum>=10){
                    carry = 1;
                }else{
                    carry = 0;
                }
                cursor1 = cursor1->next;
                cursor2 = cursor2->next;
            }
            if(cursor1->next==NULL){
                cursor1->next = cursor2->next;
                cursor1->val = cursor1->val + cursor2->val;
            }else if(cursor2->next==NULL){
                cursor1->val = cursor1->val + cursor2->val;
            }
            while(cursor1->next!=NULL){
                sum = cursor1->val + carry;
                cursor1->val = sum%10;
                if(sum>=10){
                    carry = 1;
                }else{
                    carry = 0;
                }
                cursor1 = cursor1->next;
            }
            sum = cursor1->val + carry;
            cursor1->val = sum%10;
            if(sum>=10){
                ListNode* carryone = new ListNode(1);
                cursor1->next = carryone;
            }
            return l1;
        }
    }
};