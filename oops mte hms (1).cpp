#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

class patient
{
public:
int ID;
string firstname;
string lastname;
int age;
char blood[5];
char gender;
patient* next;
};

class linkedqueue: public patient
{
patient* head;
patient* tail;
public:
linkedqueue() //constructor
{
head=NULL;
tail=NULL;
}
    patient input();
    void insertatend();
    void insertatbeg();
    void getpatientout();
    void listofpatients();
    int search(int);
    string departmentname;
};

int linkedqueue :: search(int item)
{
     if(head==NULL)
     return false;
     else
     {
      patient* p=new patient();
      p=head;
     while( p->next!=NULL && p->ID!=item )
     {
        p=p->next;
     }
     if(p->ID==item)
     {
       return true;
     }
     }
       return false;
}

int readnumber()
{
   char b[2];
   cin.getline(b, sizeof(b));
   return atoi(b);
}

patient linkedqueue :: input()
{
    int flag=0;
    patient* p=new patient();
   cout << "\n   Please enter data for patient\n";
   cout<<"\n   First name     : ";
   getline(cin,p->firstname);
   cout << "   Last name      : ";
   getline(cin,p->lastname);
   again :
   cout << "   Blood Group    : ";
   cin>>p->blood;
   if((strcmp(p->blood,"A+")==0)||(strcmp(p->blood,"a+")==0)||(strcmp(p->blood,"A-")==0)||(strcmp(p->blood,"a-")==0)||
      (strcmp(p->blood,"B+")==0)||(strcmp(p->blood,"b+")==0)||(strcmp(p->blood,"B-")==0)||(strcmp(p->blood,"b-")==0)||
      (strcmp(p->blood,"O+")==0)||(strcmp(p->blood,"o+")==0)||(strcmp(p->blood,"O-")==0)||(strcmp(p->blood,"o-")==0)||
      (strcmp(p->blood,"AB+")==0)||(strcmp(p->blood,"ab+")==0)||(strcmp(p->blood,"AB-")==0)||(strcmp(p->blood,"ab-")==0))
             flag=1;
    if(flag==0)
    {
        cout<<"\n   Invalid Blood Group Try Again..\n\n";
        goto again;

    }
   cout<<"   Gender(m/f)    : ";
   cin>>p->gender;
   cout<<"   Age            : ";
   cin>>p->age;
   cout<<"   Patient ID  : ";
   cin>>p->ID;

if(search(p->ID))
{
p->ID=0;
cout << "\n   Data not valid. Admission cancelled.";
}
return *p;
}

void output(patient *p)
{
cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
cout<<"\n   Patient data:\n";
cout<<"\n   First Name         : "<<p->firstname;
cout<<"\n   Last Name          : "<<p->lastname;
cout<<"\n   Gender             : "<<p->gender;
cout<<"\n   Age                : "<<p->age;
cout<<"\n   Blood Group        : "<<p->blood;
cout<<"\n   Patient ID     : "<<p->ID;
cout<<"\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
}
void linkedqueue :: insertatbeg()
{
     patient* p=new patient();
     *p=input();
     if(p->ID==0)
     return;

     if(head==NULL)

     {
         head=p;
         tail=p;
         p->next=NULL;
     }
     else
     {
        p->next=head;
        head=p;
     }
     system("cls");
     cout << "\n\tPatient added:";
     output(p);
}
void linkedqueue:: insertatend()
{
     patient* p=new patient();
     *p=input();
     if(p->ID==0)
     return;

     if(head==NULL)
     {
        head=p;
        tail=p;
        p->next=NULL;
     }
     else
     {
        p->next=NULL;
        tail->next=p;
        tail=p;
     }
     system("cls");
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
     cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
     cout <<"\n  ----------PATIENT ADDED-----------";
     output(p);
}
void linkedqueue :: getpatientout()
{
system("cls");
     if(head==NULL)
     {
     cout<<"\n  No Patient to attend";
     }
     else
     {
     patient* p=new patient();
     p=head;
     head=head->next;
    cout << "\n  Patient to attend:";
        output(p);
}
}

void linkedqueue :: listofpatients()
{
     if(head==NULL)
     {
     cout<<"\n  No patient";
}
      system("cls");
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
     cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
     patient* p=new patient();
     p=head;
     while(p!=NULL)
     {
        cout<<"\n   Patient data:\n";
cout<<"\n   First Name       : "<<p->firstname;
cout<<"\n   Last Name        : "<<p->lastname;
cout<<"\n   Gender           : "<<p->gender;
        cout<<"\n   Age              : "<<p->age;
        cout<<"\n   Blood Group      : "<<p->blood;
cout<<"\n   Patient ID    : "<<p->ID;
cout<<"\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        p=p->next;
     }
     cout<<"\n";
}


void departmentmenu (linkedqueue* q)
{
    int choice = 0;
    while (choice != 5)
  {
    system("cls");
    cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout<<"\n\n   "<<q->departmentname;
    cout<<"\n   [1] Add normal patient\n";
    cout<<"   [2] Add critically ill patient\n";
    cout<<"   [3] Take patient to Doctor\n";
    cout<<"   [4] Display list\n";
    cout<<"   [5] Change department or exit\n";
    cout<<"\n   Please enter your choice : ";
    choice=readnumber();
    cout<<"  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";

switch (choice)
{
  case 1: q->insertatend();
          cout << "\n   Press any key";
          getch();
          break;

  case 2: q->insertatbeg();
          cout << "\n   Press any key";
          getch();
          break;

  case 3: q->getpatientout();
          cout<<"\n   Press any key";
          getch();
          break;

  case 4: system("cls");
          q->listofpatients();
          cout<<"\n   Press any key";
          getch();
          break;
 }
}
}

int main ()
{
    int i;
    int choice = 0;
    linkedqueue departments[4];
   departments[0].departmentname="GENERAL DEPARTMENT";
   departments[1].departmentname="CARDIAC DEPARTMENT";
   departments[2].departmentname="GENERAL SURGERY DEPARTMENT";
   departments[3].departmentname="RADIOLOGY DEPARTMENT";

while(choice!=5)
{
   system("cls");
   cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
   cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
   cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
   cout<<"   Main Menu\n\n";
   for (i=0; i<4; i++)
   {
     cout<<"   "<<(i+1)<<": "<<departments[i].departmentname<<"\n";
   }
   cout<<"   5: Exit";
   cout<<"\n\n   Please enter your choice : ";
   choice=readnumber();
   if(choice>=1 && choice<=4)
   {
     departmentmenu(&departments[choice-1]);
   }

}
   if(choice==5)
   cout<<"\n\t\tThank you! \n";
   return 0;
}
