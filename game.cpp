#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
int row;
int col;
node *next;
};

void insertionAtEnd(node **head,int row,int col);
void deletionOfQueue(node **head);
char score(char frontend[][6],char backend[][6],int row,int col,int level,int dr,int dc);
int check(int *i,int *j,char b[][6],char k,int level,int r,int c);
void levelone(char arr[][6],int dr,int dc,int row,int col);
void leveltwo(char arr[][6],int dr,int dc,int row,int col);
node* pop(node **head);
int main(){
char arr[7][6]={' ',' ',' ',' ',' ',' ',' ','-','-','-',' ',' ','-',' ','-',' ',' ',' ','-',' ','-',' ','-','-',' ',' ',' ',' ',' ',' ',' ','-','-','-','-',' ','-',' ',' ','-',' ','D'};
char frontend[7][6];
char frontend2[7][6];
char arr2[7][6];
for(int i=0;i<7;i++){
    for(int j=0;j<6;j++){
        frontend[i][j]=arr[i][j];
        frontend2[i][j]=arr[i][j];
        arr2[i][j]=arr[i][j];
    }
}

int row=7,col=6;
for(int i=0;i<7;i++){
    for(int j=0;j<6;j++){
        cout<<arr[i][j];
    }
    cout<<endl;
}
int dr=6,dc=5;
levelone(arr,dr,dc,7,6);
cout<<"\n\n";
 for(int i=0;i<7;i++){
    for(int j=0;j<6;j++){
        cout<<arr[i][j];
    }
    cout<<endl;
}
cout<<"Level One\n";
char c=score(frontend,arr,7,6,1,6,5);
if(c=='y'){
    system("CLS");
    cout<<"Level Two\n";
    leveltwo(arr2,dr,dc,7,6);
    score(frontend2,arr,7,6,2,6,5);
}
system("CLS");
cout<<"Game Over\n";
return 0;
}
void max_five(node **head,node **tail,int i,int j){
static int total=0;
node *n=new node;
n->next=NULL;
n->row=i;
n->col=j;
(*tail)->next=n;
*tail=n;
total++;
 if(total>5){
  struct node *temp=(*head);
  (*head)=(*head)->next;
   total--;
   delete temp;
 }
}
void leveltwo(char arr[][6],int dr,int dc,int row,int col){
node *start=NULL;
int i=0,j=0;
insertionAtEnd(&start,i,j);
arr[i][j]='#';

while(start){
        struct node *temp=pop(&start);
        i=temp->row;
        j=temp->col;
        delete temp;
        arr[i][j]='*';
        if(i==dr&&j==dc){///checking destination
            cout<<"Destination found\n";
           break;
        }

 if(arr[i][j+1]!='*'&&arr[i][j+1]!='#'&&j<col&&j+1>=0&&arr[i][j+1]!='-'){
    insertionAtEnd(&start,i,j+1);
    arr[i][j+1]='#';
 }

 if(arr[i][j-1]!='*'&&arr[i][j-1]!='#'&&j<col&&j-1>=0&&arr[i][j-1]!='-'){
    insertionAtEnd(&start,i,j-1);
    arr[i][j-1]='#';
 }

 if(arr[i+1][j]!='*'&&arr[i+1][j]!='#'&&i<row&&i+1>=0&&arr[i+1][j]!='-'){
    insertionAtEnd(&start,i+1,j);
    arr[i+1][j]='#';
 }

 if(arr[i-1][j]!=5&&arr[i-1][j]!='#'&&i<row&&i-1>=0&&arr[i-1][j]!='-'){
    insertionAtEnd(&start,i-1,j);
    arr[i-1][j]='#';
 }
}

}
void levelone(char arr[][6],int dr,int dc,int row,int col){
node *start=NULL;
int i=0,j=0;
insertionAtEnd(&start,i,j);
arr[i][j]='#';

while(start){
        i=start->row;
        j=start->col;
        arr[i][j]='*';
        if(i==dr&&j==dc){///checking destination
            cout<<"Destination found\n";
           break;
        }

 if(arr[i][j+1]!='*'&&arr[i][j+1]!='#'&&j<col&&j+1>=0&&arr[i][j+1]!='-'){
    insertionAtEnd(&start,i,j+1);
    arr[i][j+1]='#';
 }

 if(arr[i][j-1]!='*'&&arr[i][j-1]!='#'&&j<col&&j-1>=0&&arr[i][j-1]!='-'){
    insertionAtEnd(&start,i,j-1);
    arr[i][j-1]='#';
 }

 if(arr[i+1][j]!='*'&&arr[i+1][j]!='#'&&i<row&&i+1>=0&&arr[i+1][j]!='-'){
    insertionAtEnd(&start,i+1,j);
    arr[i+1][j]='#';
 }

 if(arr[i-1][j]!=5&&arr[i-1][j]!='#'&&i<row&&i-1>=0&&arr[i-1][j]!='-'){
    insertionAtEnd(&start,i-1,j);
    arr[i-1][j]='#';
 }
 deletionOfQueue(&start);
}

}
char score(char fronttemp[][6],char backend[][6],int row,int col,int level,int dr,int dc){
    int chances=3;
    char frontend[7][6];
again:
for(int i=0;i<7;i++){
    for(int j=0;j<6;j++){
        frontend[i][j]=fronttemp[i][j];
    }
}
system("CLS");
cout<<"Level one\n";
for(int i=0;i<7;i++){
       for(int j=0;j<6;j++){
        cout<<frontend[i][j];
         }
    cout<<endl;
}
char key;
int points=0;
int i=0,j=0;
frontend[i][j]='$';
backend[i][j]='@';

 while(chances){
cout<<"\nEnter key l,r,t or b or q to exit ";
cin>>key;
   if(key=='q'){
   return 'x';
   }else{
       int temp=check(&i,&j,backend,key,level,row,col);
       if(i==dr&&j==dc){
        cout<<"\nCongratulations you did it";
        return 'y';
       }
       frontend[i][j]='$';
       points=points+temp;
       system("CLS");
       if(temp==-5){
        chances--;
        cout<<"SMASHED\nStart Again\n";
        goto again;
       }
       cout<<"Score = "<<points<<endl;
       for(int i=0;i<7;i++){
       for(int j=0;j<6;j++){
        cout<<frontend[i][j];
         }
    cout<<endl;
    }
      }
 }
 return 'x';
}
int check(int *i,int *j,char b[][6],char k,int level,int r,int c){
    int row=*i,col=*j;
    if(k=='l')col--;
    if(k=='r')col++;
    if(k=='t')row--;
    if(k=='b')row++;
if(row<r&&row>=0&&col<c&&col>=0&&b[row][col]!='-'){
        *i=row;
        *j=col;
    if(b[*i][*j]=='@')return -2;
    if(b[*i][*j]=='#'){
        b[*i][*j]='@';
        return -1;
    }
    if(b[*i][*j]=='*'){
        b[*i][*j]='@';
        return 4;
    }
    if(level==2)
    return -3;
    else
     return 0;
}
return -5;
}
void insertionAtEnd(node **head,int r,int c){

    node *last=*head;
    node *new_node=new node;
    new_node->row=r;
    new_node->col=c;
    new_node->next=NULL;

  if(*head==NULL){
    *head=new_node;
  }else{

     while(last->next!=NULL){
        last=last->next;
     }

     last->next=new_node;
  }

}
node* pop(node **head){
    node *ret;
node *pre=*head;
if((*head)->next==NULL){
    ret=(*head);
    (*head)=NULL;
    return ret;
}

 while(pre->next->next){
    pre=pre->next;
 }

    ret=pre->next;
    pre->next=NULL;
    return ret;
}
void deletionOfQueue(node **head){
     node *temp=*head;
    *head=(*head)->next;
    delete temp;
}







