#include <stdio.h>
#include <stdlib.h>

typedef struct ToDo todo;
char *gets(char *str);

struct ToDo{
    char data[100];
    todo *link;
    int count;
};
todo *start=NULL;
void fixcount(){
  todo *temp;
  int i=1;
  temp=start;
  while(temp!=NULL){
    temp->count=i;
    i++;
    temp=temp->link;
  }

}

void seeToDo(){
   system("cls");
   todo *temp;
   temp=start;
        if(start==NULL){
           printf("\nEmpty TODO\n\n");
        }

       while(temp!=NULL){
          printf("%d)",temp->count);
          puts(temp->data);
          fflush(stdin);
          temp=temp->link;
       }
       printf("\n\n\n");
       system("pause");
   }

void createToDo(){
    char k;
    todo *t,*temp;
    system("cls");
    while(1){
        printf("\nWant to add?y/n");
        fflush(stdin);
        scanf("%c",&k);
        if(k=='n')
            break;
       else{
        if(start==NULL){
        t=(todo *)calloc(1,sizeof(todo));
        start=t;
        printf("\nADD it..\n");
        fflush(stdin);
        gets(t->data);
        t->count=1;
        start->link=NULL;
       }
       else{
       temp=(todo *)calloc(1,sizeof(todo));
       printf("\nADD it..\n");
       fflush(stdin);
       gets(temp->data);
       temp->link=NULL;
       t->link=temp;
       t=t->link;
     }
     fixcount();
    }
   }
}

void delToDo(){
  system("cls");
  int d;
  todo *temp1,*temp;
  printf("\nEnter the no of the todo you want to remove\n");
  scanf("%d",&d);
  temp1=start;
  temp=start->link;
  while(1){
  if(temp1->count==d){
    start=start->link;
    free(temp1);
    fixcount();
    break;
  }
    if(temp->count==d){
        temp1->link=temp->link;
        free(temp);
        fixcount();
        break;
    }
    else{
        temp1=temp;
        temp=temp->link;
    }
}
system("pause");
}



void updateToDo(){
  system("cls");
  todo *temp,*t;
  char k;
  while(1){
        printf("\nWant to add?y/n");
        fflush(stdin);
        scanf("%c",&k);
        if(k=='n')
            break;
       printf("\nADD it..\n");
       temp=(todo *)calloc(1,sizeof(todo));
       fflush(stdin);
       gets(temp->data);
       temp->link=NULL;
       t=start;
      while(t->link!=NULL){
        t=t->link;
      }
      t->link=temp;
      fixcount();
}
printf("\n\n");
system("pause");
}

int main()
{
    int choice;
    while(1){
        system("color 3F");
        system("cls");
        printf("\n1.See Your ToDo List");
        printf("\n2.Create Your ToDos");
        printf("\n3.Delete Your ToDos");
        printf("\n4.Update Your ToDos");
        printf("\n5.Exit");
        printf("\n\nEnter your choice..");
        scanf("%d",&choice);
        switch(choice){
      case 1:
          seeToDo();
        break;
      case 2:
          createToDo();
        break;
      case 3:
          delToDo();
        break;
      case 4:
         updateToDo();
         break;
      case 5:
        exit(0);
        }
    }
}
