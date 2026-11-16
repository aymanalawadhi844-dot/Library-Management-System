
#include <iostream>
#include <string>
using namespace std;
//Library Management System
// ‰Ÿ«„ ≈œ«—… «·„ﬂ »… «·–ﬂÌ

class Media// «·«»
{
protected:
	string title;
	int id;
public:
	//constructor
	Media(string t, int i):title(t),id(i)
	{
	}
	//function
	int getID()
	{
		return id;
	}

	//function virtual
	virtual void display()
	{
		cout << "ID: " << id << " | Title: " << title;
	
	}
};

class Book :public Media
{
private:
	string author;// «·„ƒ·›
public:
	//constructor
	Book(string t, int i,string au):Media(t,i),author(au)//author = au
	{
		
	}
	//function
	void display()override
	{ 
		// «” œ⁄«¡ œ«·… «·«» «Ê·«
		Media::display();
		cout << " | Author: " << author << endl;
	}
};

class Magazine :public Media
{
private:
	int issueNumber;
public:
	//constructor
	Magazine(string t, int i, int iss):Media(t,i),issueNumber(iss)
	{

	}
	//function
	void display()override
	{
		Media::display();
		cout << " | IssueNumber: " << issueNumber << endl;
	}
};
int main()
{
	// „’›Ê›… „‰ «·„ƒ‘—« 
	Media* library[3];

	library[0]=new Book("C++ programming", 101, "Ayman Saeed");
	library[1]=new Magazine("C++ algrothm", 102, 2);
	library[2] = new Book("Data Structures", 103, "Ali");

	cout << "=== Welcome to Ayman's Smart Library ===\n";

	int choice;
	do {
		cout <<"\n=======================================\n";
		cout << "            Menu Library         ";
		cout << "\n=======================================\n";
		cout << "1. Search element ID\n";
		cout << "2. Show all \n";
		cout << "3. Exit\n";
		cout << "Chose number (from 1 to 3): ";
		cin >> choice;

		switch (choice) {
		case 1: {


			// ÿ·» —ﬁ„ «·»ÕÀ „‰ «·„” Œœ„
			int searchID;
			cout << "Enter ID to search: ";
			cin >> searchID;

			// 
			bool found = false;
			try {
				for (int i = 0; i < 3; i++)
				{
					if (searchID == library[i]->getID())
					{
						cout << "\n[Success] Item found: " << endl;

						library[i]->display();
						found = true;
						break;
					}
				}
				if (!found)
				{
					throw "Error: Serial number not found in our database!";

				}
			}
			catch (const char* msg) {
				cout << "\n[!] System Aletr: " << msg << endl;
			}

		}
				break;

		case 2:
			cout << "\n=== All library ===\n";
			for (int i = 0; i < 3; i++)
			{
				library[i]->display();
				cout << "---------------------\n";
			}
			break;

		case 3:
			cout << "\n Thank You using Library System, GoodBye!\n";
			break;

		default:
			cout << "\n[!] Error chose false , again Number between 1 and 3\n";
		}

	} while (choice != 3);

	return 0;
}
