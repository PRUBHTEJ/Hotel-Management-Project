//C++ PROJECT ON HOTEL MANAGEMENT SYSTEM 


#include<dos.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iostream.h>

class hotel
{
	introom_no;
	char name[30];
	char address[50];
	char phone[10];

	public:
	voidmain_menu();		//to dispay the main menu
	void add();			//to book a room
	void display(); 		//to display the customer record
	void rooms();		//to display alloted rooms
	void edit();			//to edit the customer record
	int check(int);		//to check room status
	void modify(int);		//to modify the record
	voiddelete_rec(int);           //to delete the record
	voidscreenheader();
};

void hotel::main_menu()
{
	int choice;
	while(choice!=5)
	{
		clrscr();
		cout<<"\n\t\t\t\t********************";
		cout<<"\n\t\t\t\t*    HOTEL GRAND   *";
		cout<<"\n\t\t\t\t*  { CATEGORIES }  *";
		cout<<"\n\t\t\t\t********************";
		cout<<"\n\n\n\t\t\t1.Book A Room";
		cout<<"\n\t\t\t2.Customer Record";
		cout<<"\n\t\t\t3.Rooms Allotted";
		cout<<"\n\t\t\t4.Edit Record";
		cout<<"\n\t\t\t5.Exit";
		cout<<"\n\n\t\t\tEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:	add();
				break;
			case 2: display();
				break;
			case 3: rooms();
				break;
			case 4:	edit();
				break;
			case 5: cout<<"\n \n saving changes please wait.....";
				cout<<"\n \n Thank You";
				sleep(2);
				break;
			default:
				{
					cout<<"\n\n\t\t\tWrong choice.....!!!";
					cout<<"\n\t\t\tPress any key to continue....!!";
					getch();
				}

	}
	}
}


void hotel::screenheader()
{
hotel p;
cout<<"\n\n\n                             WELCOMES YOU..............";
cout<<"\n\n\n\tHotel GRAND is one of the newest Hotel in NEW DELHI. The Hotel is \t\tequipped with with";
cout<<"all the general amenities and facilities that go \t\talong with memorable stay. Set amidst beautifully";
cout<<" landscaped gardens, \t\tit proves to be a ideal dream destination for perceptive traveller.";
cout<<"\n\n\tThe Hotel have well furnished rooms along with rooms providing pleasent \tviews of the city.";
cout<<" The hotel satisfies the needs of business as well \t\tas the leisure traveller. All the rooms at";
cout<<" the hotel are furnished \t\tbeautifully. All the rooms are fitted with amenities.";
cout<<"\n\n                             AMENITIES .......\n";
cout<<"\n\t\t\t1. 100% Power backup.\n";
cout<<"\t\t\t2. Automatic lift.\n";
cout<<"\t\t\t3. Ample parking space.\n";
cout<<"\t\t\t4. Round the clock security.\n";
cout<<"\t\t\t5. Running hot and cold water.\n";
cout<<"\t\t\t6. Free internet service.\n";
cout<<"\t\t\t7. 24 hours room service.\n";
cout<<"\t\t\t8. Laundary service.\n";
cout<<"\nPress any character to continue:";
getch();
p.main_menu();
   }

void hotel::add()
{
	clrscr();
	intr,flag;
	ofstreamfout("Record.dat",ios::app);

	cout<<"\n Enter Customer Detalis";
	cout<<"\n ----------------------";
	cout<<"\n\n Room no: ";
	cin>>r;
	flag=check(r);

	if(flag)
		cout<<"\n Sorry..!!!Room is already booked";

	else
	{
		room_no=r;
		cout<<" Name: ";
		gets(name);
		cout<<" Address: ";
		gets(address);
		cout<<" Phone No: ";
		gets(phone);
		fout.write((char*)this,sizeof(hotel));
		cout<<"\n Room is booked...!!!";
	}

	cout<<"\n Press any key to continue.....!!";
	getch();
	fout.close();
}

void hotel::display()
{
	clrscr();
	ifstream fin("Record.dat",ios::in);
	intr,flag;
	cout<<"\n Enter room no: ";
	cin>>r;

	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			clrscr();
			cout<<"\n Customer Details";
			cout<<"\n ----------------";
			cout<<"\n\n Room no: "<<room_no;
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone no: "<<phone;
			flag=1;
			break;
		}
	}

	if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant....!!";

	cout<<"\n\n Press any key to continue....!!";
	getch();
	fin.close();

}


void hotel::rooms()
{
	clrscr();
	ifstream fin("Record.dat",ios::in);
	cout<<"\n\t\t\t    List Of Rooms Allotted";
	cout<<"\n\t\t\t    ----------------------";
	cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";
	fin.read((char*)this,sizeof(hotel));
	while(!fin.eof())
	{
		cout<<"\n\n "<<room_no<<"\t\t"<<name;
		cout<<"\t\t"<<address<<"\t\t"<<phone;
		fin.read((char*)this,sizeof(hotel));
	}
	cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
	getch();
	fin.close();
}

void hotel::edit()
{
	clrscr();
	intchoice,r;

	cout<<"\n EDIT MENU";
	cout<<"\n ---------";
	cout<<"\n\n 1.Modify Customer Record";
	cout<<"\n 2.Delete Customer Record";

	cout<<"\n Enter your choice: ";
	cin>>choice;
	clrscr();
	cout<<"\n Enter room no: " ;
	cin>>r;

	switch(choice)
	{
		case 1:	modify(r);
			break;
		case 2:	delete_rec(r);
			break;
		default: cout<<"\n Wrong Choice.....!!";
	}
	cout<<"\n Press any key to continue....!!!";
	getch();
}


int hotel::check(int r)
{
	int flag=0;
	ifstream fin("Record.dat",ios::in);
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			flag=1;
			break;
		}
	}

	fin.close();
	return(flag);
}


void hotel::modify(int r)
{
	longpos,flag=0;
	fstream file("Record.dat",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			cout<<"\n Enter New Details";
			cout<<"\n -----------------";
			cout<<"\n Name: ";
			gets(name);
			cout<<" Address: ";
			gets(address);
			cout<<" Phone no: ";
			gets(phone);

			file.seekg(pos);
			file.write((char*)this,sizeof(hotel));
			cout<<"\n Record is modified....!!";
			flag=1;
			break;
		   }
	}

	if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant...!!";
	file.close();
}

void hotel::delete_rec(int r)
{
	int flag=0;
	charch;
	ifstream fin("Record.dat",ios::in);
	ofstreamfout("temp.dat",ios::out);
	fin.read((char*)this,sizeof(hotel));
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Pone No: "<<phone;
			cout<<"\n\n Do you want to delete this record(y/n): ";
			cin>>ch;

			if(ch=='n')
				fout.write((char*)this,sizeof(hotel));
			flag=1;
		}
		else
			fout.write((char*)this,sizeof(hotel));
	}

	fin.close();
	fout.close();
	if(flag==0)
		cout<<"\n Sorry room no. not found or vacant...!!";
	else
	{
		remove("Record.dat");
		rename("temp.dat","Record.dat");
	}
}


void main()
{
	hotel h;
	clrscr();
	cout<<"\n\t\t\t****************************";
	cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
	cout<<"\n\t\t\t****************************";

	cout<<"\n\n\n\n\t\tMade By:";
	cout<<"\tprubhtejsingh (XII-A)";
	cout<<"\n\n\t\tSubmitted To:";
	cout<<"\tMs. Shikha Thakur";
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
cout<<"*************************************
                    ***********************
                        *************
                               *****
                              ***
                                *";
	getch();
	h.screenheader();
}
