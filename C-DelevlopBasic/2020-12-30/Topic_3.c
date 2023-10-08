int countcs(struct ListNode *head ){// 指向第一个结构体地址
    int count = 0;
    struct ListNode *p = head;
    while(p != NULL){
        if(p->code[1]=='0' && p->code[2]=='2')
            count++;
        p=p->next;
    }
    return count;
}