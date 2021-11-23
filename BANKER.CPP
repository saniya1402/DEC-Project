//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include <fstream>
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class account
{
	int acno;
	char name[50];
	char pass[6];
	long int deposit;
	char type;

public:
	int create_account(); //function to get data from user
	void bal_initial();	  //function to get initial deposite
	void show_account();  //function to show data on screen
	void modify();		  //function to get new data
	int new_acc();		  //function to input new account number
	void dep(int);		  //function to accept amount and add to balance amount
	void draw(int);		  //function to accept amount and subtract from balance amount
	void report();		  //function to show data in tabular format
	int retacno();		  //function to return account number
	int retdeposit();	  //function to return balance amount
	char rettype();		  //function to return type of account
	char *retpass();	  //function to return passcode
};

int account::create_account()
{
	int i = 0;
	cout << "\n\nEnter The Name of The account Holder : ";
	fflush(stdin);
	gets(name);
	cout << "\nEnter Passcode(3 characters only) :";
	for (i = 0; i < 4; i++)
	{
		pass[i] = getch();
		cout << "*";
	}
	pass[i] = '\0';
	cout << endl;
	cout << "\nEnter Type of The account (C/S) : ";
	cin >> type;
	type = toupper(type);
	bal_initial();
	return new_acc();
}

int account::new_acc()
{
	cout << "Enter account Number:";
	cin >> acno;
	account ac;
	int flag = 0;
	ifstream inFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return -1;
	}
	while (inFile.read((char *)&ac, sizeof(account)))
	{
		if (ac.retacno() == acno)
		{
			flag = 1;
			break;
		}
		inFile.close();
	}
	if (flag == 0)
		return flag;
	else
	{
		cout << "Account Already Exists\n";
		return flag;
	}
}

void account::bal_initial()
{
	if (type == 'S')
	{
		while (deposit < 500)
		{
			cout << "Enter amount(>=500)\t";
			cin >> deposit;
			if (deposit < 500)
				cout << "Inadequate amount ,Please Enter at least 500\n\n";
		}
	}
	else
	{
		while (deposit < 1000)
		{
			cout << "Enter amount(>=1000)\t";
			cin >> deposit;
			if (deposit < 1000)
				cout << "Inadequate amount ,Please Enter at least 1000\n\n";
		}
	}
}

void account::show_account()
{
	cout << "\nAccount No. : " << acno;
	cout << "\nAccount Holder Name : ";
	cout << name;
	cout << "\nType of Account : " << type;
	cout << "\nBalance amount : " << deposit;
}

void account::modify()
{
	int i = 0;
	cout << "\nThe account No.:" << acno;
	cout << "\n\nEnter The Name of The account Holder : ";
	fflush(stdin);
	gets(name);
	cout << "\nEnter Type of The account (C/S) : ";
	cin >> type;
	type = toupper(type);
	cout << "\nEnter The amount : ";
	cin >> deposit;
	cout << "Enter pin(for executive):";
	for (i = 0; i < 4; i++)
	{
		pass[i] = getch();
		cout << "*";
	}
	pass[i] = '\0';
	cout << endl;
}

void account::dep(int x)
{
	deposit += x;
}

void account::draw(int x)
{
	deposit -= x;
}

void account::report()
{
	cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(10) << deposit << endl;
}

int account::retacno()
{
	return acno;
}

int account::retdeposit()
{
	return deposit;
}

char account::rettype()
{
	return type;
}

char *account::retpass()
{
	return pass;
}

class emp
{
	char ename[20];
	char epass[6];
	int ecode;
	float sal;

public:
	int hire();		 //Enter details of employee
	int new_emp();	 //Enter Unique Employee code
	void modify();	 //Modify employee details;
	void erep();	 //Display tabular employee data
	void show_rec(); //Display employee details
	char *retpass(); //Return Employee Passcode
	int retecode();	 //Return employee code
};

int emp::hire()
{
	int i = 0;
	cout << "\n\nEnter The Name of Employee : ";
	fflush(stdin);
	gets(ename);
	cout << "\nEnter The passcode(3 characters only) :";
	for (i = 0; i < 4; i++)
	{
		epass[i] = getch();
		cout << "*";
	}
	epass[i] = '\0';
	cout << endl;
	cout << "\nEnter Salary:";
	cin >> sal;
	return new_emp();
}
int emp::new_emp()
{
	cout << "Enter Employee Code:";
	cin >> ecode;
	emp e1;
	int flag = 0;
	ifstream inFile;
	inFile.open("emp.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return -1;
	}

	while (inFile.read((char *)&e1, sizeof(emp)))
	{
		if (e1.retecode() == ecode)
		{
			flag = 1;
			break;
		}
		inFile.close();
	}
	if (flag == 0)
		return flag;
	else
	{
		cout << "Account Already Exists\n";
		return flag;
	}
}

void emp::show_rec()
{
	cout << "Employee code: " << ecode;
	cout << "\nEmployee name: " << ename;
	cout << "\nSalary : " << sal;
}

void emp::modify()
{
	int i = 0;
	cout << "\n\nEnter The Name of Employee : ";
	fflush(stdin);
	gets(ename);
	cout << "\nEnter The passcode: ";
	for (i = 0; i < 4; i++)
	{
		epass[i] = getch();
		cout << "*";
	}
	epass[i] = '\0';
	cout << endl;
	cout << "\nEnter Salary:";
	cin >> sal;
}

int emp::retecode()
{
	return ecode;
}

void emp::erep()
{
	cout << ecode << setw(10) << " " << ename << setw(10) << " " << sal << setw(10) << epass;
}

char *emp::retpass()
{
	return epass;
}

//***************************************************************
//    	function declaration
//****************************************************************

//1. Employee Functions

void write_account();			   //function to write record in binary file
void display_sp(int);			   //function to search and display account details given by user
void modify_account(int);		   //function to modify record of file
void delete_account(int);		   //function to delete record of file
void display_all();				   //function to display all account details
void deposit_withdraw(int, int);   // function to desposit/withdraw amount for given account

//2. Manager functions

void write_emp();				   //function to write emp details
void delete_emp(int n);			   //funtion to delete employee
void display_emp(int n);		   //function to search and display employee
void display_allemp();			   //funtion to display list of all employee
void modify_emp(int n);			   //function to modify employee details

//3. Menu Functions
void exemenu();					   //executive menu
void manmenu();					   //manager menu
int passcheck(char a[], char b[]); //function to check password or pin
void intro();					   //introductory screen function

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
	char ch;
	int num;
	system("CLS");
	intro();
	do
	{
		system("CLS");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. DEPOSIT AMOUNT";
		cout << "\n\n\t02. WITHDRAW AMOUNT";
		cout << "\n\n\t03. BALANCE ENQUIRY";
		cout << "\n\n\t04. EXECUTIVE OPTIONS";
		cout << "\n\n\t05. MANAGER OPTIONS";
		cout << "\n\n\t06. EXIT";
		cout << "\n\n\tSelect Your Option (1-6): ";
		cin >> ch;
		system("CLS");
		switch (ch)
		{
		case '1':
			cout << "\n\n\tEnter The account No. : ";
			cin >> num;
			deposit_withdraw(num, 1);
			break;
		case '2':
			cout << "\n\n\tEnter The account No. : ";
			cin >> num;
			deposit_withdraw(num, 2);
			break;
		case '3':
			cout << "\n\n\tEnter The account No. : ";
			cin >> num;
			display_sp(num);
			break;
		case '4':
			exemenu();
			break;

		case '5':
			manmenu();
			break;

		case '6':
			cout << "\n\n\tThanks for using bank managemnt system";
			break;
		default:
			cout << "\a";
		}
		getch();
	} while (ch != '6');
	return 0;
}

//***************************************************************
//    	   function to write in file
//****************************************************************

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.txt", ios::binary | ios::app);
	if (ac.create_account() == 0)
	{
		cout << "Account Created";
		outFile.write((char *)&ac, sizeof(account));
		outFile.close();
	}
	else
		cout << "Account not created";
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	account ac;
	int flag = 0;
	char b[6];
	int i = 0;
	ifstream inFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}

	while (inFile.read((char *)&ac, sizeof(account)))
	{
		if (ac.retacno() == n)
		{
			cout << "Enter Pin:";
			for (i = 0; i < 4; i++)
			{
				b[i] = getch();
				cout << "*";
			}
			b[i] = '\0';
			cout << endl;
			if ((passcheck(ac.retpass(), b)) == 0)
			{
				cout << "\nBALANCE DETAILS\n";
				ac.show_account();
				flag = 1;
			}
			else
			{
				cout << "Incorrect PIN!!";
				flag = 1;
				break;
			}
		}
	}
	inFile.close();
	if (flag == 0)
		cout << "\n\nAccount number does not exist";
}

//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_account(int n)
{
	int found = 0;
	account ac;
	fstream File;
	File.open("account.txt", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key......";
		return;
	}
	while (File.read((char *)&ac, sizeof(account)) && found == 0)
	{
		if (ac.retacno() == n)
		{
			ac.show_account();
			cout << "\n\nEnter The New Details of account" << endl;
			ac.modify();
			int pos = (-1) * sizeof(account);
			File.seekp(pos, ios::cur);
			File.write((char *)&ac, sizeof(account));
			cout << "\n\n\t Record Updated";
			found = 1;
		}
	}
	File.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_account(int n)
{
	account ac;
	int found = 0;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key.......";
		return;
	}
	outFile.open("Temp.txt", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read((char *)&ac, sizeof(account)))
	{
		if (ac.retacno() != n)
		{
			outFile.write((char *)&ac, sizeof(account));
		}
		else
		{
			found = 1;
		}
	}
	inFile.close();
	outFile.close();
	remove("account.txt");
	rename("Temp.txt", "account.txt");
	if (found == 1)
		cout << "\n\n\tRecord Deleted ..";
	else
		cout << "\n\n\tRecord Not found ..";
}

//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "====================================================\n";
	cout << "A/c no.      NAME           Type  Balance\n";
	cout << "====================================================\n";
	while (inFile.read((char *)&ac, sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

//***************************************************************
//    	function to deposit and withdraw amounts
//****************************************************************

void deposit_withdraw(int n, int option)
{
	int amt;
	int found = 0;
	char b[6];
	int i = 0;
	account ac;
	fstream File;
	File.open("account.txt", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (File.read((char *)&ac, sizeof(account)) && found == 0)
	{
		if (ac.retacno() == n)
		{
			cout << "Enter Pin:";
			for (int i = 0; i < 4; i++)
			{
				b[i] = getch();
				cout << "*";
			}
			b[i] = '\0';
			cout << endl;
			if ((passcheck(ac.retpass(), b)) == 0)
			{
				ac.show_account();
				if (option == 1)
				{
					cout << "\n\n\tTO DEPOSITE AMOUNT ";
					cout << "\n\nEnter The amount to be deposited:";
					cin >> amt;
					ac.dep(amt);
				}
				if (option == 2)
				{
					cout << "\n\n\tTO WITHDRAW AMOUNT ";
					cout << "\n\nEnter The amount to be withdrawn:";
					cin >> amt;
					int bal = ac.retdeposit() - amt;
					if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C'))
						cout << "Insufficience balance!!!!!!";
					else
						ac.draw(amt);
				}
				int pos = (-1) * sizeof(ac);
				File.seekp(pos, ios::cur);
				File.write((char *)&ac, sizeof(account));
				cout << "\n\n\t Record Updated";
				found = 1;
			}
			else
			{
				cout << "Incorrect PIN!!";
				found = 1;
				break;
			}
		}
	}
	File.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";
}

//***************************************************************
//    	function to Hire employee
//****************************************************************

void write_emp()
{
	emp e1;
	ofstream outFile;
	outFile.open("emp.txt", ios::binary | ios::app);
	if (e1.hire() == 0)
	{
		cout << "Employee Details Added";
		outFile.write((char *)&e1, sizeof(emp));
	}
	else
		cout << "Employee not Added";
	outFile.close();
}

//***************************************************************
//    	function to Delete employee Records
//****************************************************************

void delete_emp(int n)
{
	emp e1;
	int found = 0;
	ifstream inFile;
	ofstream outFile;
	inFile.open("emp.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key......";
		return;
	}
	outFile.open("Temp.txt", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read((char *)&e1, sizeof(emp)))
	{
		if (e1.retecode() != n)
		{
			outFile.write((char *)&e1, sizeof(emp));
		}
		else
		{
			found = 1;
		}
	}
	inFile.close();
	outFile.close();
	remove("emp.txt");
	rename("Temp.txt", "emp.txt");
	if (found == 1)
		cout << "\n\n\tRecord Deleted .........";
	else
		cout << "\n\n\tRecord Not found .......";
}

//***************************************************************
//    	function to Search and display employee records
//***************************************************************

void display_emp(int n)
{
	emp e1;
	int flag = 0;
	ifstream inFile;
	inFile.open("emp.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key.........";
		return;
	}
	cout << "\nEMPLOYEE DETAILS\n";
	while (inFile.read((char *)&e1, sizeof(emp)))
	{
		if (e1.retecode() == n)
		{
			e1.show_rec();
			flag = 1;
		}
	}
	inFile.close();
	if (flag == 0)
		cout << "\n\nEmployee does not exist";
}

//***************************************************************
//    	function to  display all employee
//***************************************************************

void display_allemp()
{
	emp e1;
	ifstream inFile;
	inFile.open("emp.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key........";
		return;
	}
	else
	{
		cout << "\n\n\t\tEMPLOYEE LIST\n\n";
		cout << "====================================================\n";
		cout << "ECODE.      NAME           SALARY        Pass     \n";
		cout << "====================================================\n";
		while (inFile.read((char *)&e1, sizeof(emp)))
		{
			e1.erep();
			cout << endl;
		}
	}
	inFile.close();
}

//***************************************************************
//		function to Modify an employee data
//***************************************************************

void modify_emp(int n)
{
	int found = 0;
	emp e1;
	fstream File;
	File.open("emp.txt", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key......";
		return;
	}
	while (File.read((char *)&e1, sizeof(emp)) && found == 0)
	{
		if (e1.retecode() == n)
		{
			e1.show_rec();
			cout << "\n\nEnter The New Details of account:" << endl;
			e1.modify();
			int pos = (-1) * sizeof(emp);
			File.seekp(pos, ios::cur);
			File.write((char *)&e1, sizeof(emp));
			cout << "\n\n\t Record Updated";
			found = 1;
			getch();
		}
	}
	File.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";
}

//***************************************************************
//                    Executive  menu
//***************************************************************

void exemenu()
{
	int num;
	emp e1;
	char e, b[6];
	cout << "Enter Employee Number:";
	cin >> num;
	int flag = 0;
	int i = 0;
	ifstream inFile;
	inFile.open("emp.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key.....";
	}

	while (inFile.read((char *)&e1, sizeof(emp)))
	{
		if (e1.retecode() == num)
		{
			flag = 1;
			break;
		}
	}

	inFile.close();
	if (flag == 0)
		cout << "\n\nEmployee does not exist........";
	else
	{
		cout << "Enter pin:";
		for (i = 0; i < 4; i++)
		{
			b[i] = getch();
			cout << "*";
		}
		b[i] = '\0';
		cout << endl;
		system("CLS");
		if (passcheck(e1.retpass(), b) && flag == 1)
		{
			do
			{
				system("CLS");
				e1.show_rec();
				cout << "\n\n\tEXRCUTIVE MENU";
				cout << "\n\n\t01. NEW ACCOUNT";
				cout << "\n\n\t02. ALL ACCOUNT HOLDER LIST";
				cout << "\n\n\t03. MODIFY AN ACCOUNT";
				cout << "\n\n\t04. CLOSE AN ACCOUNT";
				cout << "\n\n\t05. RETURN TO MAIN MENU";
				cout << "\n\n\tEnter your choice(1-5):";
				cin >> e;
				switch (e)
				{
				case '1':
					write_account();
					getch();
					break;
				case '2':
					display_all();
					getch();
					break;
				case '3':
					cout << "\n\n\tEnter The account No. : ";
					cin >> num;
					modify_account(num);
					getch();
					break;
				case '4':
					cout << "\n\n\tEnter The account No. : ";
					cin >> num;
					delete_account(num);
					getch();
					break;

				case '5':
					break;
				}
			} while (e != '5');
		}
		else
			cout << "Incorrect pin!!";
	}
}

//***************************************************************
//                    Manager menu
//****************************************************************

void manmenu()
{
	int num, i = 0;
	char m, b[6];
	cout << "Enter Manager pin:";
	for (int i = 0; i < 6; i++)
	{
		b[i] = getch();
		cout << "*";
	}
	b[i] = '\0';
	cout << endl;
	if (passcheck("12345\0", b) == 0)
	{
		do
		{
			system("CLS");
			cout << "\n\n\tMANAGER MENU";
			cout << "\n\n\t01. HIRE EMPLOYEE";
			cout << "\n\n\t02. FIRE EMPLOYEE";
			cout << "\n\n\t03. SEARCH EMPLOYEE";
			cout << "\n\n\t04. MODIFY EMPLOYEE DETAILS";
			cout << "\n\n\t05. DISPLAY ALL EMPLOYEES";
			cout << "\n\n\t06. RETURN TO MAIN MENU";
			cout << "\n\n\tEnter tour choice(1-6):";
			cin >> m;
			switch (m)
			{
			case '1':
				write_emp();
				getch();
				break;
			case '2':
				cout << "\n\n\tEnter The Employee code : ";
				cin >> num;
				delete_emp(num);
				getch();
				break;
			case '3':
				cout << "\n\n\tEnter The Employee code : ";
				cin >> num;
				display_emp(num);
				getch();
				break;
			case '4':
				cout << "\n\n\tEnter The Employee code : ";
				cin >> num;
				modify_emp(num);
				break;
			case '5':
				display_allemp();
				getch();
				break;
			}
		} while (m != '6');
	}
	else
		cout << "Incorrect Pin!!";
}

//***************************************************************
//    	function to check password or pin
//****************************************************************

int passcheck(char a[], char b[])
{
	int flag = 1;
	for (int i = 0; i < 6 && a[i] != '\0'; i++)
	{
		if (a[i] != b[i])
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
	cout << "\n\n\n\t  BANK";
	cout << "\n\n\tMANAGEMENT";
	cout << "\n\n\t  SYSTEM";
	cout << "\n\n\n\nMADE BY :\n Astitva Agarwal & Saniya Saggar ";
	getch();
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************