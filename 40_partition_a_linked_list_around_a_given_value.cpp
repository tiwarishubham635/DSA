struct Node* partition(struct Node* head, int x) 
{
    Node* lessStart=NULL, *lessEnd = NULL;
    Node* equalStart=NULL, *equalEnd = NULL;
    Node* greaterStart=NULL, *greaterEnd = NULL;
    Node* tmp = head;
    while(head!=NULL)
    {
        if(head->data < x)
        {
            if(lessStart==NULL)
                lessStart=lessEnd=head;
            else
                lessEnd->next = head, lessEnd = head;
        }
        else if( head->data == x)
        {
            if(equalStart==NULL)
                equalStart=equalEnd=head;
            else
                equalEnd->next = head, equalEnd = head;
        }
        else
        {
            if(greaterStart==NULL)
                greaterStart=greaterEnd=head;
            else
                greaterEnd->next = head, greaterEnd = head;
        }
        head = head->next;
    }
    
    if(greaterEnd!=NULL)
        greaterEnd->next = NULL;
    if(lessStart==NULL)
    {
        if(equalStart==NULL)
            return greaterStart;
        equalEnd->next = greaterStart;
        return equalStart;
    }
    else
    {
        if(equalStart==NULL)
        {
            if(greaterStart==NULL)
            {
                lessEnd->next = NULL;
                return lessStart;
            }
            else
            {
                lessEnd->next = greaterStart;
                return lessStart;
            }
        }
        else
        {
            lessEnd->next = equalStart;
            if(greaterStart==NULL)
            {
                equalEnd->next = NULL;
                return lessStart;
            }
            else
            {
                equalEnd->next = greaterStart;
                return lessStart;
            }
        }
    }
}
