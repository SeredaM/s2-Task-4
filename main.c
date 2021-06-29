#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef struct node
{
    int id;
    struct node *next;
} list;

 list *new (int set_id)
{
      list *tmp = (list*)malloc(sizeof(list));
     tmp -> id = set_id;
     tmp -> next = NULL;
      return tmp;
}


 void push (list **L,int set_id)
{
    list *tmp = new(set_id);
    tmp -> next = *L;
    *L=tmp;
}
 void pushback (list *L,int set_id)
{
      list *ptr = new(set_id);
      while (L->next != NULL)
        L = L->next;
      L->next = ptr;
}
 void print (list *L)
{
      while (L!=NULL)
      {
          printf("%d ",L -> id);
          L = L -> next;
      }
      printf("\n");
}
 void insafter(list *L, int set_id, int point)
{
      list *tmp = new(set_id);
     while ((L -> id) != point)
        L = L->next;
    if (L -> next == NULL)
         L -> next = tmp;
    else
    {
     tmp -> next = L -> next;
     L -> next = tmp;
    }
}
 void insbefore(list **head, int set_id, int point)
{
     list *tmp = *head;
     if ((*head) -> id == point)
     {
      push(head,set_id);
       return;
     }
    list *ptr = new(set_id);
     while (tmp -> next -> id != point)
     tmp = tmp -> next;
     ptr -> next = tmp -> next;
     tmp -> next = ptr;
}

 void pop(list **head)
{
  list *tmp = *head;
  *head = (*head) -> next;
  free(tmp);
}

 void poplast(list *head)
{
  list *prev;
 list *tmp=head;
  while (tmp->next != NULL)

  {
      prev=tmp;
      tmp=tmp ->next;
  }
  free(tmp);
  prev->next = NULL;

}

 void popid (list **head,int del_id)
{
    list *tmp = *head;
    list *prev;
    if ((*head)->id == del_id)
    {
        pop(head);
        return;
    }
    while (tmp -> id != del_id)
    {
        prev = tmp;
        tmp = tmp -> next;
    }
    if (tmp -> next == NULL)
    {
        poplast(*head);
    }
    prev -> next = tmp -> next;
    free(tmp);

}

void popneg (list **head)
{
    list *tmp=*head;
    list *check;
    while (tmp -> next != NULL)
    {
        check = tmp;
        tmp = tmp -> next;
        if (check -> id <0)
            popid(head,check -> id);
    }
    if (tmp -> id < 0)
    {
        if ((*head)->next!=NULL)
        poplast(*head);
        else
        pop(head);
    }
}
list *randoml()
{
    int s,id;
    s=rand()%6+5;
    id = rand()%100 - 50;
    list *L = new(id);
    for (int i=1;i<s;i++)
    {
        id = rand()%100 - 50;
        pushback(L,id);
    }
    return L;
}

void main()
{
    int n=1,id,point;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list *L=randoml();
    while (n!=NULL)
    {
        printf("\n �������� ��������:\n");
        printf("1. ������� ������ �� �����\n");
        printf("2. �������� ������� � ������ ������ \n");
        printf("3. �������� ������� � ����� ������ \n");
        printf("4. �������� ������� ����� ��������� \n");
        printf("5. �������� ������� �� ��������� \n");
        printf("6. ������� ������ ������� \n");
        printf("7. ������� ��������� ������� \n");
        printf("8. ������� ������� �� ��� id \n");
        printf("9. ������� ��� ������������� �������� (�������������� �������) \n");
         printf("10. �������� ������ � ��������� ������ ��������� \n ");
        scanf("%d",&n);
        switch(n)
   {
    case 1:
        print(L);
        break;
    case 2:
        printf("������� id �������� \n");
        scanf("%d",&id);
        push(&L,id);
        break;
    case 3:
        printf("������� id �������� \n");
        scanf("%d",&id);
        if (L!=NULL)
        pushback(L,id);
        else
            push(&L,id);
        break;
    case 4:
        printf("������� id �������� ������� ������ �������� \n");
        scanf("%d",&id);
        printf("������� id �������� ����� �������� ���������� ������� \n");
        scanf("%d",&point);
        insafter(L,id,point);
        break;
    case 5:
        printf("������� id �������� ������� ������ �������� \n");
        scanf("%d",&id);
        printf("������� id �������� �� �������� ���������� ������� \n");
        scanf("%d",&point);
        insbefore(&L,id,point);
        break;
    case 6:
        pop(&L);
        break;
    case 7:
        if (L->next!=NULL)
        poplast(L);
        else
            pop(&L);
        break;
    case 8:
        printf("������� id �������� ������� ������ ������� \n");
        scanf("%d",&id);
        popid(&L,id);
        break;
    case 9:
        popneg(&L);
        break;
    case 10:
        free(L);
        n=NULL;
        break;
   }

    }

}
