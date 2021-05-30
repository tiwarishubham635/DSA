void deleteNode(Node *del)
{
   if(del->next==NULL)
    {
        del=NULL;
        return;
    }
    del->data = del->next->data;
    del->next = del->next->next;
}
