bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
if(head1!= 0 && head2 == 0 || head1 == 0 && head2!=0 )
    return 0;
else
{

    while(head1!=0 && head2!=0)
    {
        if(head1->data == head2->data)
        {   head1 = head1->next;
            head2 = head2->next;}

        else
            break;
    }
    if(head1 == head2)
        return 1;
    else
        return 0;
}
