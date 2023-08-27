#include <stdio.h>
#include <cstdlib>
struct student{
  int id;
  float cgpa;
  struct student *next;
};

int main(){
    struct student *head, *two, *three;
    head=(struct student*)malloc(sizeof(struct student));
    two=(struct student*)malloc(sizeof(struct student));
    three=(struct student*)malloc(sizeof(struct student));
    head->id=1632;
    head->cgpa=3.00;
    head->next=two;
    two->id=1155;
    two->cgpa=2.00;
    two->next=three;
    three->id=1003;
    three->cgpa=2.80;
    three->next=NULL;
    struct student *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d-> ",temp->id);
        temp=temp->next;
    }
    printf("NULL\n");
    temp=head;
    while(temp!=NULL){
        printf("%0.2f-> ",temp->cgpa);
        temp=temp->next;}
        printf("NULL\n");
         while(temp!=NULL){
        printf("%d-> ",temp->id);
        temp=temp->next;
    }

  return 0;
}
