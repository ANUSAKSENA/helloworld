/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <cstdio>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<conio.h>


using namespace std;
class book
{
  char bno[6], bname[50], aname[20];
public:
  void create_book ();
  void show_book ();
  void modify_book ();
  char *retbno ()
  {
    return bno;
  }
  void report ();
};				//class ends here

class student
{
  char admno[6], name[20], stbno[6];
  int token;
public:
  void create_student ();
  void show_student ();
  void modify_student ();
  char *retadmno ();
  char *retstbno ();
  int rettoken ();
  void addtoken ()
  {
    token = 1;

  }
  void resettoken ()
  {
    token = 0;

  }
  void getstbno (char t[])
  {
    strcpy (stbno, t);
  }
  void report ()
  {
    cout << "\t" << admno << setw (20) << name << setw (10) << token << endl;

  }
};				//class ends here

class admin:public book, public student	//admin makes changes to the entire record
{
  int ar[];			//req members will be added
};
void book::create_book ()
{
  clrscr ();
   cout << "\nNEW BOOK ENTRY...\n";
   cout << "\nEnter The book no.";
     cin >> bno;
   cout << "\n\nEnter The Name of The Book ";
     getline (bname);
   cout << "\n\nEnter The Author's Name ";
     getline(aname);
   cout << "\n\n\nBook Created..";
}

void book::show_book ()
{
    cout << "\nBook no. : " << bno;
    cout << "\nBook Name : ";
      puts (bname);
    cout << "Author Name : ";
      puts (aname);
}

void book::modify_book ()
{
    cout << "\nBook no. : " << bno;
    cout << "\nModify Book Name : ";
      fgets (bname);
    cout << "\nModify Author's Name of Book : ";
     fgets (aname);
}

void book::report ()			//formatting output
{
    cout << bno << setw (30) << bname << setw (30) << aname << endl;
}

void student::create_student ()
{
  clrscr ();
    cout << "\nNEW STUDENT ENTRY...\n";
    cout << "\nEnter The admission no. of the student";
      cin >> admno;
    cout << "\n\nEnter the name of the student ";
      getline(name);
  token = 0;			//no book issued
  stbno[0] = '\0';
   cout << "\n\nStudent record has been created";
}

void student::show_student ()
{
    cout << "\nAdmission no. : " << admno;
    cout << "\nStudent Name : ";
      puts (name);
    cout << "\nNo of Book issued : " << token;
  	if (token == 1)		//if a book is issued
    	 cout << "\nBook No " << stbno;

}

char* student::retadmno ()
{
  return admno;

}

char* student::retstbno ()
{
  return stbno;
}

int student::rettoken ()
{
  return token;
}

//declaration of class objects globally
book bks[50];
student stu[50];
int b = 1;			//for record of number of books
int s = 1;			//for record of number of students
 //writing  book and student records
 //books
void write_book ()			//might need to keep parameter for sizeof()
{
  char ch;
  	do
   	 {
     	   bks[b].create_book ();	//bth book
      	     cout << "Are there more records to be entered(y or n)?";
               cin >> ch;
      		b++;
	 }while (ch == 'y' || ch == 'Y');
}

void write_student ()
{
  char ch1;
   	do
   	 {
     	   stu[s].create_student ();
      	    cout << "Are there more student records to be added(y or n)?";
              cin >> ch1;
   	 } while (ch1 == 'y' || ch1 == 'Y');
}

void disp_bdet (char n[])		//to display details of particular book
{
  int n = sizeof (bks);
  int r, f = 0;			//flag
  	for (r = 0; r < n; r++)
    	 {
     		 if (strcmpi (bks[r].retbno (), n) == 0)
		  {
	 	    bks[r].show_book ();
	 	     f = 1;
		  }
         }
  if (f == 0)
    cout << "\n\n Sorry.Book does not exist in this library";
}

void disp_sdet (char n[])		//to display details of a particular student
{
    cout << "\nSTUDENT DETAILS\n";
  int f = 0, c;
  int n = sizeof (stu);//size of  class object
  	for (c = 0; c < n; c++)
  	  {
     		 if ((strcmpi (stu[c].retadmno (), n) == 0))
	          {
	            stu[c].show_student ();
	 	    f = 1;

		  }
  	  }
      if (f == 0)
	cout << "\n\nStudent record does not exist";
    }
  void mod_book ()		//function to call modify fn if book exists
  {
    char n[6];
    int found = 0;
     clrscr ();
      cout << "\n\n\tMODIFY BOOK REOCORD ";
      cout << "\n\n\tEnter the book number";
        cin >> n;
    int k = sizeof (bk);
    int r;
    	for (r = 0; r < k; r++)
         {
		if (strcmpi (bks[r].retbno (), n) == 0)
	 	 {
	  	   bks[r].show_book ();
	   	    cout << "\nEnter The New Details of book" << endl;
	   	   bks[r].modify_book ();
	            cout << "\n\n\t Record updated";
	           found = 1;

	          }
        }
    if (found == 0)
      cout << "\n\n Record not found ";
  }

  void mod_stu ()		//modify stu rec if student exists. will add for wrong entry by mistake
  {
    char n[6];
    int f = 0;			//found
    clrscr ();
     cout << "\n\n\tMODIFY STUDENT RECORD... ";
     cout << "\n\n\tEnter the admission no. ";
      cin >> n;
    int s = sizeof (stu);
    int c;
   	 for (c = 0; c < s; c++)
          {
		if (strcmpi (stu[c].retadmno (), n) == 0)
	  	{
	   	  stu[c].show_student ();
	   	   cout << "\nEnter The New Details of student" << endl;
	    	  stu[c].modify_student ();
	   	   cout << "\n\n\t Record Updated";
	   	  f = 1;
	 	 }
         }
    if (f == 0)
      cout << "\n\n record not found ";
  }






int
main ()
{

  return 0;
}
