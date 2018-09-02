#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
void main(){clrscr();
char *p;
char us[22];
char ch;
int n=0;
cout<<"Usename : ";gets(us);
cout<<"Enter Password : ";while(n!=6){
ch=getch();
if(ch=='\n'){break;}
cout<<"*";
p[n]=ch;
n++;
}  char s[]={"sohams"};
fflush(stdin);
if(strcmp(p,s)==0){cout<<endl<<"Access Greanted ;)";}
else{cout<<endl<<"Access denied";}                 getch();
}