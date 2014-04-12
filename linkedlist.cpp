#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
}*head;

class single_llist
{
    public:
        single_llist()
        {
            head=NULL;
        }

        node* create_node(int value)
        {
            struct node *temp;
            temp = new (struct node);
            if(temp==NULL)
            {
                cout<<"Memory can't be allocated"<<"\n";
            }
            else
            {
                temp->data = value;
                temp->next = NULL;
                return temp;
            }       
        }

        void insert()
        {
            int value;
            cout<<"Enter value for data"<<"\n";
            cin>>value;
            struct node *temp;
            temp = create_node(value);
            if(head==NULL)
            {
                head=temp;
            }
            else
            {
                temp->next=head;
                head = temp;
            }
        }

        void insert_at_last()
        {
            int value;
            cout<<"Enter data to insert at last position"<<"\n";
            cin>>value;
            struct node *temp_node,*temp;
            temp=head;
            temp_node = create_node(value);
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next = temp_node;
        }

        void insert_at_position(int pos)
        {
            int value,i=1;
            cout<<"Enter data to insert at "<<pos<<"\n";
            cin>>value;
            struct node *temp_node, *temp,*prev;
            temp = head;
            temp_node = create_node(value);
            while(i!=pos &&  temp->next!=NULL)
            {
                i++;
                prev=temp;
                temp=temp->next;
            }

            temp_node->next = temp;
            prev->next = temp_node;
        }

        void delete_at_beginning()
        {
            struct node *temp;
            temp = head;
            head = temp->next;
            delete(temp);
        }

        void delete_at_end()
        {
            struct node *temp,*prev;
            temp = head;
            while(temp->next!=NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            
            prev->next = NULL;
            delete(temp);
        }

        void reverse()
        {
            struct node *newnode=NULL, *temp=NULL;
            while(head)
            {
                newnode = head->next;
                head->next = temp;
                temp= head;
                head= newnode;
            }
            head = temp;
        }

        void display()
        {
            struct node *temp;
            temp = head;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }

        void search(int number)
        {
            struct node *temp;
            temp =head;
            while(temp!=NULL)
            {
                if(temp->data == number)
                {
                    cout<<number<<" exist in Linked List";
                    break;
                }
            temp = temp->next;
            }
        }

};

int main()
{
    single_llist sl;
    sl.insert();
    sl.insert();
    sl.insert();
    sl.insert();
    sl.insert();
    sl.insert_at_last();
    sl.insert_at_position(4);
    sl.delete_at_beginning();
    sl.delete_at_end();
    sl.reverse();
    sl.search(8);
    sl.display();
    return 0;
}


