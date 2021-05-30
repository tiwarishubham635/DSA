bool isPalindrome(Node *head)
    {
        /*if(head==NULL)
            return true;
        if(head->next==NULL)
            return true;
        Node* tmp = head;
        Node* prev = NULL;
        while(tmp->next!=NULL)
        {
            prev = tmp;
            tmp= tmp->next;
        }
        if(tmp->data!=head->data)
            return false;
        else
        {
            prev->next = NULL;
            return isPalindrome(head->next);
        }*/
        if(head->next==NULL)
            return true;
        Node* slow = head;
        Node* fast = head;
        
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast==NULL)
        {
            Node* prev = NULL;
            Node* curr = slow;
            Node* future = curr->next;
            while(future!=NULL)
            {
                curr->next = prev;
                prev = curr;
                curr = future;
                future = future->next;
            }
            curr->next = prev;
            Node* newHead = curr;
            
            Node* tmp = head;
            while(tmp!=slow&&curr!=NULL)
            {
                if(tmp->data!=curr->data)
                    return false;
                tmp = tmp->next;
                curr = curr->next;
            }
            return true;
        }
        else
        {
            Node* prev = NULL;
            Node* curr = slow->next;
            Node* future = curr->next;
            while(future!=NULL)
            {
                curr->next = prev;
                prev = curr;
                curr = future;
                future = future->next;
            }
            curr->next = prev;
            Node* newHead = curr;
            
            Node* tmp = head;
            while(tmp!=slow&&curr!=NULL)
            {
                if(tmp->data!=curr->data)
                    return false;
                tmp = tmp->next;
                curr = curr->next;
            }
            return true;
        }
    }
