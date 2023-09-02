#include <stdio.h>
#include <stdlib.h>

struct student{
  int id;
  struct student *next;
};

void print(struct student *head);
struct student* insertAtHead(struct student *head, int data);
void insertAtEnd(struct student *head, int data);
void search(struct student *head, int value);
struct student* insertAtPosition(struct student *head, int position , int data);
struct student* delete(struct student *head, int position);

int main(){
    struct student *head;
    head=(struct student*)malloc(sizeof(struct student));
    head->id=1003;
    head->next=NULL;
print(head);
head = insertAtHead(head, 1199);
insertAtEnd(head, 1219);
head = insertAtPosition(head, 1, 1445);
head = insertAtPosition(head, 2, 1632);
print(head);
head = delete(head, 2);
print(head);
search(head, 1003);

  return 0;
};

//insart in head
struct student* insertAtHead(struct student *head, int data){
    struct student *temp;
    temp=(struct student *)malloc(sizeof(struct student));
    temp->id = data;
    temp->next = head;
    head=temp;
    print(head);
    return head;
  };

//search in list
void search(struct student *head, int value){
  struct student *temp;
  temp=head;
  int a=1;
  int flag = 0;
  while(temp!=NULL)
  { 
   if (temp->id == value)
   {
    flag=1;
       break;
   }
   a++;
   temp=temp->next;
  }
  if (flag==1)
   {
    printf("Found %d item in indax: %d\n", value, a);
   }
  else if(flag == 0)
  {
    printf("Not Found.\n");
  }
 };

// insart in the end
void insertAtEnd(struct student *head, int data){
  struct student *curent=head;
  while (curent->next!=NULL)
  {
    curent=curent->next;
  }
  struct student *temp;
  temp=(struct student *)malloc(sizeof(struct student));
  temp->id=data;
  curent->next=temp;
  temp->next=NULL;
  print(head);
};

//print list
void print(struct student *head){
    struct student *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d-> ",temp->id);
        temp=temp->next;
    }
    printf("NULL\n");
};

//insert at any position
struct student* insertAtPosition(struct student *head, int position, int data){
  struct student *newNode= (struct student*)malloc(sizeof(struct student));
int counter = 1;
struct student* temp=head;
while(temp!=NULL)
{
  if(counter == position)
  {
    newNode->id=data;
    newNode->next=temp->next;
    temp->next=newNode;
    print(head);
    return head;
  }
  counter++;
  temp=temp->next;
}
};

// delete a linklist
struct student* delete(struct student *head, int position){
  struct student *temp=head;
  int val=2;
  while(temp != NULL)
  {
    if(position == 1)
    {
      printf("Deleted item %d Index: %d\n", temp->id, position);
      temp=temp->next;
      return temp;
    }
    else if(val == position)
    {
      printf("Deleted item %d Index: %d\n", temp->id, position);
      temp->next=temp->next->next;
      return temp;
    }
    val++;
    temp=temp->next;
  }
  printf("Position not found\n");
  return head;
  };
