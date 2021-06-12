#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insertion(int value);
void del();
struct node
{
    int data;
    struct node *link;
}*f,*l,*n,*temp;
 
int main(){
    int select;
    int no;
    int enterNumber;
    printf("Press 1 to start the game\n");
    printf("Press 2 to end the game\n");
    printf("Enter your choice:\t");
    scanf("%d",&select);
    switch(select){
        case 1:{
         while(1){
          no=(rand() % (100 - 1 + 1)) + 1;
          printf(" %d\n",no);
          printf("Enter the number:\t");
          scanf("%d",&enterNumber);
          insertion(enterNumber);
          if(no==enterNumber){
          del();
          continue;
          }else{
              printf("Wrong input.\n");
              break;
          }
        }
     }
    
     case 2:{
            return 0;
            break;
        }
        default:{
            printf("Invalid\n");
            break;
        }
    }
    return 0;
}

void insertion(int value){
     if(f==NULL){
        f=new node();
        f->data=value;
        f->link=NULL;
        l=f;
     }
     else{
        n=new(node);
        n->data=value;
        n->link=NULL;
        l->link=n;
        l=n;

     }
}
void del(){
   temp=f;
   f=f->link;

}

