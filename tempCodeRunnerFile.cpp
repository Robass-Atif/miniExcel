for(int i=0;i<5;i++)
            {
                  t1->next=t2;
                  t2->prev=t1;
                  t1=t1->down;
                  t2=t2->down;  
            }