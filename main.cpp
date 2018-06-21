/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<cstring>
using namespace std;
void admin ();
void member ();
void book ();			//record of all boooks
void iss_ret ();		//issue and return of books
void modifyrec ();		//modifying student records
void modifybook ();		//modifying book records
int
main ()
{
  int ad_mem;
  cout << "\n1)Admin\n2)Member\nchoose 1 or 2\n";
  cin >> ad_mem;
  if (ad_mem != 1 || ad_mem != 2)
    cout << "Invalid response. Choose either 1 or 2";
  cin >> ad_mem;
  switch (ad_mem)
    {
    case 1:
      admin ();
      break;
    case 2:
      member ();
      break;
    }
  return 0;
}

void admin ()//allowed to modify book and student records
{
  char password[5], pass[5];
  password = "12345";
//cout<<"enter password";
//cin>>pass;
//password check
//if(strcmp(password,pass!=0))
//{cout<<"Wrong password.try again";

  do
    {
      cout <<
	"Welcome.Choose your option\n1)Books list\n2)Modify student record";
      cout << "\n3)Modify book record";
      int choice;
      cin >> choice;
      switch (choice)
	{
	case 1:
	  book ();
	  beak;
	case 2:
	  modifyrec ();//add,modify or delete student records
	  break;
	case 3:
	  modifybook ();//add,modify or delete books from the list
	  break;
	default:
	  cout << "wrong choice.Try again";
	}
      char res;
      cout << "Do you want to continue (y or n)";
      cin >> res;
    } while (res == 'y' || res == 'Y');
}
void member()//portal for member to do the activities mentioned from the given choice
{
    do{
        cout<<"\n1)Books in the library\n2)Issue or return of books";
  int ch;
  cin>>ch;
  switch(ch)
  {case 1:
    books();
    break;
   case 2:
    iss_ret();
    break;
   default:
   cout<<"wrong choice .enter again";
   break;
  }
  cout<<"do you want to continue?(y or n)";
  char ch;
  cin>>ch;
  }while(ch=='y' ||ch=='Y');
}
void modifybook()//to add more books,at the beg no books in the library
    { cout<<"\n1)add books\n2)delete book\n3)modify book detail";
    
        
    }
 
 

