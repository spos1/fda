#include<stdio.h>
void accept(int[10],int);
void display(int[10],int);
int union1(int[10],int ,int[10],int ,int set3[]);
int inter1(int[10],int ,int[10],int ,int set4[]);
int diff1(int[10],int ,int[10],int ,int set5[]);
int main(){
int
M[10],d1,S[10],d2,ch,MUS[10],d3,MandS[10],d4,M_S[10],d5,S_M[10],d6,M_SUS_M[10],d7;
do{
printf(" 1.accept students\n 2.display students\n 3.exit\n");
scanf("%d",&ch);
switch(ch){
case 1:{
printf("Enter no of student who like maths: ");
scanf("%d",&d1);
accept(M,d1);
printf("Enter no of student who like science: ");
scanf("%d",&d2);
accept(S,d2);
break;
}
case 2:{
int ch2;
printf(" 1.Maths\n 2.Science\n 3.Either Math or Science\n 4.Both Math and Science\n
5.Only maths\n 6.Only Science\n 7.Either one subject\n ");
scanf("%d",&ch2);
switch(ch2){
case 1:{
display(M,d1);
printf("\n");
break;
}
case 2:{
display(S,d2);
printf("\n");
break;
}
case 3:{
d3=union1(M,d1,S,d2,MUS);
display(MUS,d3);
printf("\n");
break;
}
case 4:{
d4=inter1(M,d1,S,d2,MandS);
display(MandS,d4);
printf("\n");
break;
}
case 5:{
d5=diff1(M,d1,S,d2,M_S);
printf("\n A-B: ");
display(M_S,d5);
printf("\n");
break;
}
case 6:{
d6=diff1(S,d2,M,d1,S_M);
printf("\n B-A: "); 
display(S_M,d6);
printf("\n");
break;
}
case 7:{
d3=union1(M_S,d5,S_M,d6,M_SUS_M);
printf("\n A-B U B-A: ");
display(M_SUS_M,d3);
printf("\n");
break;
}
}
break;
}
}
}while(ch!=3);
}
void accept(int set[10],int n){
for(int i=0;i<n;i++){
scanf("%d",&set[i]);
}printf("\n");
}
void display(int set[10],int n){
printf("{");
for(int i=0;i<n;i++){
printf("%d, ",set[i]);
}printf("}");
printf("\n");
}
int union1(int set1[10],int n,int set2[10],int n2,int set3[10]){
int d3=0;
for(int i=0;i<n;i++){
set3[d3]=set1[i];
d3++;
}
d3=n;
for(int i=0;i<n2;i++){
for(int j=0;j<=d3;j++){
if(set2[i]==set3[j]){
break;
}
if(j==d3){
set3[d3]=set2[i];
d3++;
break;
}
}
}
return d3;
}
int inter1(int set1[10],int n1,int set2[10],int n2,int set3[]){
int d4=0;
for(int i=0;i<n2;i++){
for(int j=0;j<n1;j++){
if(set2[i]==set1[j]){
set3[d4]=set2[i];
d4++;
break;
}
if(j==(n1-1)){
break;
}
}
}
return d4;
}
int diff1(int set1[10],int n1,int set2[10],int n2,int set3[]){
int d5=0;
for(int i=0;i<n1;i++){
for(int j=0;j<n2;j++){
if(set1[i]==set2[j]){
break;
}
if(j==(n2-1)){
set3[d5]=set1[i];
d5++;
break;
}
}
}
return d5;
}