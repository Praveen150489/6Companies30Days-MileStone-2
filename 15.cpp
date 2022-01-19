//  Delete N nodes after M nodes of a linked list .

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here
        if(M==0){
            head=NULL;
            return;
        }
        if(N==0){
            return;
        }
        Node* p=head;
        int count1=0;
        int count2=0;
        Node* q=NULL;
        bool flag=true;
        while(p!=NULL){
            if(flag==true){
                count1++;
                if(count1==M){
                    q=p;
                    count1=0;
                    flag=false;
                }
                p=p->next;
                if(count1==0){
                    q->next=NULL;
                }
            }
            else if(flag==false){
                count2++;
                p=p->next;
                if(count2==N){
                    q->next=p;
                    count2=0;
                    flag=true;
                }
            }
        }
    }
};
