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


/*
之前做过两个有序链表的合并，这个题我的思路就是不断地合并当前链表和下一个链表。
但是这样做时间成本还是很大。
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        ListNode* ans = lists[0];
        for(int i=1;i<lists.size();i++){
            if(ans == NULL){
                ans = lists[i];
            }
            if(lists[i]==NULL){
                continue;
            }
            ListNode* s;
            if(ans->val>lists[i]->val){
                s = ans;
                ans = lists[i];
                lists[i] = s;
            }
            s = ans;
            ListNode* cursor1 = s->next;
            ListNode* cursor2 = lists[i];
            while (cursor2!=NULL)
            {
                if(cursor1==NULL){
                    s->next = cursor2;
                    break;
                }
                else if(cursor1->val<cursor2->val){
                    s = cursor1;
                    cursor1 = cursor1->next;
                }
                else{
                    s->next = cursor2;
                    while(cursor2!=NULL && cursor2->val<=cursor1->val){
                        cursor2 = cursor2->next;
                        s = s->next;
                    }
                    cursor2 = cursor1;
                    cursor1 = s->next;
                }
            }
        }
        return ans;
    }
};