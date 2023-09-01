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
void delete(struct student *head, int position);

int main(){
    struct student *head;
    head=(struct student*)malloc(sizeof(struct student));
    head->id=1632;
    head->next=NULL;
print(head);
head = insertAtHead(head, 1199);
insertAtEnd(head, 1219);
head = insertAtPosition(head, 1, 1003);
head = insertAtPosition(head, 2, 1632);
print(head);
delete(head, 3);
search(head, 1632);


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
  int flag=0;
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
  else if(flag==0)
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
void delete(struct student *head, int position){
  struct student *temp=head;
  int val=1;
  while(temp!=NULL)
  {
    if(val == position)
    {
      temp->next=temp->next->next;
      printf("Deleted Index: %d\n",position);
      return;
    }
    val++;
    temp=temp->next;
  }
  };
