/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.


Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]


Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


 
Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {} 
};

class Solution{
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* ans=new ListNode(0);
    ListNode* curr=ans;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry){
        int sum=carry;
        if(l1){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->val;
            l2=l2->next;
        }
        carry=sum/10;
        curr->next=new ListNode(sum%10);
        curr=curr->next;
    }
    return ans->next;
   }
};

ListNode* create_list(vector<int>& nums){
    ListNode* head=new ListNode(0);
    ListNode* tail=head;
    for(int it:nums){
        tail->next=new ListNode(it);
        tail=tail->next;
    }
    return head->next;
}

void print_list(ListNode* head){
    while(head){
        cout<<head->val;
        if(head->next) cout<<"->";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    vector<int> v1{2, 4, 3}, v2={5, 6, 4};
    ListNode* l1=create_list(v1);
    ListNode* l2=create_list(v2);
    Solution sol;
    ListNode* ans=sol.addTwoNumbers(l1, l2);
    cout<<"The final list : ";
    print_list(ans);
    return 0;
}