#include <stdio.h>
#include <stdlib.h>
#define max 4
int front = 0, rear = -1, count = 0;
int item, q[max];

void insert()
{
    if (count == max)
    {
        printf("the queue is full\n");
    }
    else
    {
        rear = (rear + 1) % max;
        q[rear] = item;
        count++;
    }
}
void delete()
{
    if (count == 0)
        printf("the queue is empty\n");
    else if (front > rear && rear == max - 1)
    {
        front = 0;
        rear = -1;
        count = 0;
    }
    else
    {
        item = q[front];
        printf("the item deleted is %d\n", item);
        front = (front + 1) % max;
        count--;
    }
}
void display()
{
    if (count == 0)
        printf("the queue is empty\n");
    else
    {
        int i = front, r = rear;
        while(i!=rear)
        {
            printf("%d ",q[i]);
            i=(i+1)%max;
        }
        printf("%d \n",q[rear]);
        
    }
}
int main()
{
    int ch;
    do
    {
        printf("enter your choice\n1.insert\n2.delete\n3.display\n4.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the data\n");
            scanf("%d", &item);
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("you have entered the wrong choice\n");
            break;
        }
    } while (ch != 4);

    return 0;
}
