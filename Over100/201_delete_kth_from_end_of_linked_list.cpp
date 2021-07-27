#include<bits/stdc++.h>
LinkedListNode<int>* reverse(LinkedListNode<int> *head)
{
    if(!head or !head->next)
        return head;
    
    LinkedListNode<int>* prev = NULL, *curr = head, *future = curr->next;
    while(future)
    {
        curr->next = prev;
        prev = curr;
        curr = future;
        future = future->next;
    }
    curr->next = prev;
    return curr;
}
LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    if(k==0 or !head)
        return head;
	
    LinkedListNode<int> *orig = head, *node = head, *prev = NULL;
    /*int n = 0;
    while(head)
        n++, head = head->next;
    head = orig;
    int pos = n-k, i = 0;
    if(pos==0)
    {
        node = head;
        head = head->next;
        delete(node);
        return head;
    }
    while(i<pos-1)
        i++, head = head->next;
    node = head->next;
    head->next = node->next;
    delete(node);
    return orig;*/
    
    /*stack<LinkedListNode<int>*>st;
    while(head)
        st.push(head), head = head->next;
    while(k--)
        node = st.top(), st.pop();
    if(node==orig)
    {
        head = node->next;
        delete(node);
        return head;
    }
    st.top()->next = node->next;
    delete(node);
    return orig;*/
        
    /*head = reverse(head);
    orig = head;
    if(k==1)
    {
        node = head;
        head = head->next;
        orig = head;
    }
    else
    {
        while(--k!=1)
            head = head->next;
        node = head->next;
        head->next = node->next;
    }
    delete(node);
    head = reverse(orig);
    return head;*/
    
    while(--k)
        node = node->next;
    while(node->next)
        prev = head, head = head->next, node = node->next;
    if(prev==NULL)
    {
        node = head;
        head = node->next;
        delete(node);
        return head;
    }
    node = head;
    prev->next = node->next;
    head = orig;
    delete(node);
    return head;
}
