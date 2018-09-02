d#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
int input(){
int i;
do{
int is;      fflush(stdin);
i=scanf("%d",&is);
if(i<1){cout<<"please enter a valid value...\nEnter again :";}else{return is;}
               }while(i==0);
   return 0;
}
class travel{
int adults,child,dist,t_code;
float fare;
char name1[30],surname[30];
public:
int code(){return t_code;}
void enter(int);
void assignfare(int,int,int);
void show();
void del();
};
void travel::assignfare(int x,int y,int z){


if(z>=1000){fare=(x*500)+(y*250);}

if(z<1000&&z>=500){fare=(x*300)+(y*150);}

if(z<500){fare=(x*200)+(y*100);}

}
  void travel::enter(int c){

                       clrscr();
                       t_code=c;
                    cout<<"Enter bookers first name : ";        scanf("%s",name1);
                    cout<<"enter bokers surname: ";             scanf("%s",surname);
                    cout<<"enter number of adults : ";          adults=input();
                    cout<<"enter no. of children : ";           child=input();
                    cout<<"enter distance : ";                  dist=input();
        assignfare(adults,child,dist);

}
void travel::show(){
     clrscr();
              cout<<"your travel code is : "<<t_code<<endl;
              cout<<"This booking was made by : "<<name1<<" "<<surname;
                       cout<<endl<<"your number of adults is : "<<adults;
                       cout<<endl<<"your no of children is : "<<child;
                       cout<<endl<<"total distance is : "<<dist;
                       cout<<endl<<"your total fare is : "<<fare;
                       cout<<endl<<endl<<"Press Enter....";
                       getch();
}

void main(){fstream f;
     int x;
     travel t;
do{
clrscr();
cout<<"**********************Welcome**********************"<<endl<<endl;
cout<<"Enter any one of your choices..."<<endl;
cout<<"1)Enter details and assign fare. "<<endl;
cout<<"2)Show details and fare."<<endl;
cout<<"3)Cancel booking"<<endl;
cout<<"4)Exit"<<endl;
x=input();
switch(x){
case 1: int coode;f.open("true.dat",ios::out|ios::app);f.close();
      cout<<"enter travel code : ";
      int i=scanf("%d",&coode);//tthis
      if(i<1){cout<<"please enter a proper input..";getch();break;}
                   f.open("true.dat",ios::in);
                    f.seekg(0);        int chk=0;
                     while(!f.eof()){
                      f.read((char*)&t,sizeof(t));
                      if(t.code()==coode){cout<<"The Booking already exists ..please use another code..\npress enter...";getch();chk++;}     if(chk==1)break; } f.close();
     if(chk==0){   f.open("true.dat",ios::out|ios::app);
        t.enter(coode);
        f.write((char*)&t,sizeof(t));
        f.close();}
 break;
 case 2:int code=0;
      cout<<"enter travel code : "; cin>>code;
                   f.open("true.dat",ios::in);
                    f.seekg(0);        int chk1=0;
                     while(!f.eof()){
                      f.read((char*)&t,sizeof(t));
                      if(t.code()==code){ t.show();chk1++;}     if(chk1==1)break; }if(chk1==0){cout<<"record not found..";getch();} f.close();
 break;
 case 3: ifstream inp;
 inp.open("true.dat",ios::in);
 ofstream temp("temp.dat",ios::out);
int tcode;
cout<<"Enter travel code of the booking which is to be deleted : ";
tcode=input();
while(!inp.eof())
{
inp.read((char*)&t,sizeof(t));
if(tcode==t.code())
{
t.show();
char ans;
cout<<endl<<"Are you sure if you want to delete booking(Y/N)?";
cin>>ans;
if(ans=='n'||ans=='N'){
temp.write((char*)&t,sizeof(t));

}
}
else{temp.write((char*)&t,sizeof(t));}
}//wile
temp.close();
inp.close();
remove("true.dat");
rename("temp.dat","true.dat");
}//switch

}while(x!=4);//do


}//main