/*
Thamer Allahabi
Csci 230 
Home Work 7 & 8 
Topic ( Linked List and correcting words from a file ) 
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Define struct for poem
struct node{
char *word;
struct node *next;
};

//define struct for codes
struct codex{
char *word1, *word2;
struct codex *next;
};

// head node for both poem and codes
struct node *FirstHead=NULL;
struct node *SecondHead=NULL;

//Function to create poem linked list
void LIST_INSERT_POEM(char *chr){
struct node *curr=(struct node *)malloc(sizeof(struct node *));
curr->word=(char *)malloc(strlen(chr)*sizeof(char *));
strcpy(curr->word,chr);
curr->next=NULL;
if(FirstHead==NULL){
FirstHead=curr;
}
else{
struct node *t=FirstHead;
while(t->next!=NULL){
t=t->next;
}
t->next=curr;
}
}

//function to create codes linked list
void LIST_INSERT_CODEX(char *chr, char *chr2){
struct codex *curr=(struct codex *)malloc(sizeof(struct codex *));
curr->word1=(char *)malloc(strlen(chr)*sizeof(char *));
curr->word2=(char *)malloc(strlen(chr2)*sizeof(char *));
strcpy(curr->word1,chr);
strcpy(curr->word2,chr2);
curr->next=NULL;
if(SecondHead==NULL){
SecondHead=curr;
}
else{
struct codex *t=SecondHead;
while(t->next!=NULL){
t=t->next;
}
t->next=curr;
}
}

//function to correct the poem
void LIST_CORRECT(){
struct node *curr=FirstHead;
while(curr!=NULL){
int count=0; 
if(curr->word[strlen(curr->word)-1]==','){
count=1;
}
else if(curr->word[strlen(curr->word)-1]=='.'){
count=2;
}
struct codex *c=SecondHead;
while(c!=NULL){
if(count==1){
strcat(c->word1,",");
}
else if(count==2){
strcat(c->word1,".");
}
if(strcmp(curr->word,c->word1)==0){
if(strcmp(c->word2,"skip")==0){
strcpy(curr->word,"\0");
}
else{
curr->word=(char *)malloc(strlen(c->word2)*sizeof(char *));
strcpy(curr->word,c->word2);
// if common or skip is found we need to store it in word
if(count==1){
strcat(curr->word,",");
}
else if(count==2){
strcat(curr->word,".");
}
}
if(count==1 || count==2){
c->word1[strlen(c->word1)-1]='\0';
}
break;
}
if(count==1 || count==2){
c->word1[strlen(c->word1)-1]='\0';
}
c=c->next;
}
curr=curr->next;
}
}

// display the poem
void LIST_DISPLAY(){
struct node *t=FirstHead;
while(t!=NULL){
printf("%s ",t->word);
t=t->next;
}
}

// free poem linked list
void LIST_FREE_POEM(){
struct node *curr=FirstHead;
while(FirstHead->next!=NULL){
curr=FirstHead;
FirstHead=FirstHead->next;
free(curr);
}
}
// free codex linked list
void LIST_FREE_CODEX(){
struct codex *curr=FirstHead;
while(FirstHead->next!=NULL){
curr=FirstHead;
FirstHead=FirstHead->next;
free(curr);
}
}

int main(){

FILE *fp1=fopen("hw8data.txt","r");
FILE *fp2=fopen("hw8codex.txt","r");
char ch[42],ch2[42];

while(fscanf(fp1,"%s",ch)!=EOF){
LIST_INSERT_POEM(ch);
}
while(fscanf(fp2,"%s%s",ch,ch2)!=EOF){
LIST_INSERT_CODEX(ch, ch2);
}

LIST_CORRECT();
LIST_DISPLAY();
LIST_FREE_POEM();
LIST_FREE_CODEX();
return 0;
}
