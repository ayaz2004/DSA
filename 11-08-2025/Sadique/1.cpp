/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
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
  ListNode* removeElements(ListNode* head, int val){
    if(head==nullptr) return head;
    while(head!=nullptr && head->val==val) head=head->next;
    ListNode* curr=head;
    while(curr!=nullptr && curr->next!=nullptr){
        if(curr->next->val==val) curr->next=curr->next->next;
        else curr=curr->next;
    }
    return head;
  }
   
};

void print_list(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
   int n;
   cin>>n;
   ListNode* head=nullptr;
   ListNode* tail=nullptr;
   for(int i=0; i<n; i++){
    int x;
    cin>>x;
    ListNode* newNode = new ListNode(x);
    if(!head) head=tail=newNode;
    else{
        tail->next=newNode;
        tail=newNode;
    }
   }
   int val;
   cin>>val;

   Solution sol;
   head=sol.removeElements(head, val);
   print_list(head);

   return 0;
}