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
        printf("\n Выберите действие:\n");
        printf("1. Вывести список на экран\n");
        printf("2. Добавить элемент в начало списка \n");
        printf("3. Добавить элемент в конец списка \n");
        printf("4. Добавить элемент после заданного \n");
        printf("5. Добавить элемент до заданного \n");
        printf("6. Удалить первый элемент \n");
        printf("7. Удалить последний элемент \n");
        printf("8. Удалить элемент по его id \n");
        printf("9. Удалить все отрицательные элементы (индивидуальное задание) \n");
         printf("10. Очистить память и завершить работу программы \n ");
        scanf("%d",&n);
        switch(n)
   {
    case 1:
        print(L);
        break;
    case 2:
        printf("Введите id элемента \n");
        scanf("%d",&id);
        push(&L,id);
        break;
    case 3:
        printf("Введите id элемента \n");
        scanf("%d",&id);
        if (L!=NULL)
        pushback(L,id);
        else
            push(&L,id);
        break;
    case 4:
        printf("Введите id элемента который хотите добавить \n");
        scanf("%d",&id);
        printf("Введите id элемента после которого осущетвить вставку \n");
        scanf("%d",&point);
        insafter(L,id,point);
        break;
    case 5:
        printf("Введите id элемента который хотите добавить \n");
        scanf("%d",&id);
        printf("Введите id элемента до которого осущетвить вставку \n");
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
        printf("Введите id элемента который хотите удалить \n");
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
