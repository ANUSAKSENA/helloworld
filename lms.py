import pymysql
import datetime
db=pymysql.connect("localhost","testuser","FiveCandles123!","Library")
cursor=db.cursor()
#cursor.execute("SELECT VERSION()")
#data=cursor.fetchone()
#print("database version %s" %data)
#db.close()
class Book():
  
  def __init__(self):
   pass
   
  def addbook(self):
   sql_cmd ="""CREATE TABLE IF NOT EXISTS Books(ISBN INTEGER PRIMARY KEY,Book_name VARCHAR(45),Author VARCHAR(45),Publication VARCHAR(45),Copies INTEGER)"""
   cursor.execute(sql_cmd)
   isbn=int(input("Enter ISBN number"))
   bookname=input("Enter the book name")
   author=input("Enter the author name")
   pub=input("Enter the publication")
   copies=input("Number of copies")
   sql_cmd ="""INSERT INTO Books VALUES('%d','%s','%s','%s','%d'),(isbn,bookname,author,pub,copies)"""
   cursor.execute(sql_cmd)
   db.commit()
  # db.close()
  def modifybook(self):
   isbn=input("Enter ISBN of book to be modified")
   pub1=input("Publication")
   cursor.execute("UPDATE Books set Publiction ='%s' where ISBN='%d'",(pub1,isbn))
   db.commit()

  def delbook(self):
   isbn=int(input("ISBN of book to be removed:"))
   cursor.execute("DELETE from Books where ISBN='%d'",(isbn))
   db.commit()
   cursor.execute("SELECT * from Books")
   cr=cursor.fetchall()
   for row in cr:
    print(row)

  def showdet(self):
   cursor.execute("select * from Books")
   print(cursor.fetchall())

class Member(Book):

   def __init__(self):
    pass
   
   def addmem(self):
    sql_cmd ="""CREATE TABLE IF NOT EXISTS Member(Member_id INTEGER PRIMARY KEY,First_Name VARCHAR(45),Last_Name VARCHAR(45),Issue_status VARCHAR(10))"""
    cursor.execute(sql_cmd)
    Member_id=int(input("Member_id :"))
    First_Name=input("First Name :")
    Last_Name=input("Last Name :")
    Issue_status="Not issued"
    sql_cmd="""INSERT INTO Member VALUES('%d','%s','%s','%s'),(Member_id,First_Name,Last_Name,Issue_status)"""
    cursor.execute(sql_cmd)
    db.commit()
   def modifymem(self):
    memid=int(input("member id :"))
    fname=input("first name")
    lname=input("last name")
    cursor.execute("UPDATE Member set First_Name ='%s' where Member_id='%d'",(fname,memid))
    cursor.execute("UPDATE Member set Lastt_Name ='%s' where Member_id='%d'",(lname,memid))
    db.commit()
#id
   def delmem(self):
    memid=input("Member id of member to be removed") 
    cursor.execute("DELETE from Member where Member_id='%d'",(memid))
    db.commit()
    cursor.execute("SELECT * from Member")
    cr=cursor.fetchall()
    for row in cr:
      print(row)

   def issue(self):
    sql_cmd="""CREATE TABLE IF NOT EXISTS Issue_det(Member_id INTEGER PRIMARY KEY,Name VARCHAR(45),ISBN INTEGER,Bookname VARCHAR (20) ,Issue_date DATE, Return_date DATE)""" 
    cursor.execute(sql_cmd)
    #ask member id
    memid=int(input("enter member id "))
    cursor.execute("SELECT First_Name from Member where Member_id='%d'",(memid))
    fname=cursor.fetchone()
    print(fname)
    str="Issued"
    cursor.execute("SELECT Issue_status from Member where Member_id='%d'",(memid))
    stat=cursor.fetchone()
    if stat.lower()==str.lower() :
     print("The user already has a book issued under their name")
    else :
     ISBN=("Enter ISBN")
     cursor.execute("SELECT Book_name from Books where Member_id='%d'",(memid))
     bname=cursor.fetchone()
     now=datetime.datetime.now()
     retdate=now + datetime.timedelta(days=15)
     print("Return date")
     print(retdate)
     sql_cmd="""INSERT INTO Issue_det VALUES('%d','%s','%d','%s',''%s'',''%s''),(memid,fname,ISBN,bname,now,retdate)"""
     cursor.execute(sql_cmd)
     db.commit()
     cursor.execute("UPDATE Member SET Issue_status='ISSUED' where Member_id='%d'",(Member_id))
     cursor.execute("UPDATE Books SET Copies=Copies-1 where ISBN='%d'",(isbn))
     db.commit()

   def retbk(self):
    memid=int(input("enter member id of the person returning"))
    cursor.execute("SELECT ISBN from Issue_det where Member_id='%d'",(memid))
    #finding the book borrowed
    isbn=cursor.fetchone()
    print(isbn)
    cursor.execute("SELECT Return_date from Issue_det where Member_id='%d'",(memid))
    retdt=cursor.fetchone()
    now1=datetime.datetime.now()
    delta=now1-retdt
    if now1<retdt:
     print("no fee due")
    else :
     fee= 2*delta.days
     print("your late fee is '%d'",fee)
    cursor.execute("DELETE from Issue_det  where Member_id='%d'",(memid))
    db.commit()
    cursor.execute("SELECT * from Issue_det")
    cr=cursor.fetchall()
    # for row in cr:
    # print(row)
    cursor.execute("UPDATE Member SET Issue_status=' NO ISSUE' where Member_id='%d'",(memid))
    cursor.execute("UPDATE Books SET Copies=Copies+1 where ISBN='%d'",(isbn))
    db.commit()


   def specific_mem(self):
    #display specific details
    cursor.execute("select * from Member where Member_id='%d'",(Member_id))
    print(cursor.fetchone())



   def showdets(self):
    cursor.execute("select * from Member")
    print(cursor.fetchall())


def main():
 
     em= Member()
     while 1:
       print("""\n1)Add a book\n2)Remove a book\n3)Modifying a book\n4)Show details of books
             \n5)Add a member\n6)Remove a member\n7)Modify member details\n8)Show detail of members\n9)Issue a book\n10)Return a book""")
        
       #show options do it
       
       #create dictionary switcher that calls functions
       switcher={
         1: em.addbook,
         2: em.delbook,
         3: em.modifybook,
         4: em.showdet,
         5: em.addmem,
         6: em.delmem,
         7: em.modifymem,
         8: em.showdets,
         9: em.issue,
         10: em.retbk
      
        }
       ch=int(input("Enter your choice"))
       #switcher.get(ch,errorhandler)()
       #switcher.get(ch,"invalid choice")
       switcher[ch]()
       #asking for more choices or to exit
       ch1=input("Do you want to exit(y/n)")
       if ch1=='y' or ch1=='Y':
        #if user does not want to do anything else then exit
        break
       
        
     db.close()

if __name__=="__main__":
    main()
 


#em=Book()
#em.addbook()
   

