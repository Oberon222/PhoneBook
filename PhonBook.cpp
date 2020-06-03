#include <iostream>
#include <fstream>
#include "PhonBook.h"
using namespace std;



	PhoneBook ::PhoneBook()
	{
		book = nullptr;
		countContacts = 0;

	}

	PhoneBook:: PhoneBook(Contact newnewContact)
	{
		countContacts = 1;
		book = new Contact[countContacts];
		book[0] = newnewContact;
	}

	PhoneBook :: ~PhoneBook()
	{
		if (book != nullptr) delete[]book;
	}

	void PhoneBook::AddContact(Contact newContact)
	{
		Contact* newBook = new Contact[countContacts + 1];
		for (int i = 0; i < countContacts; i++) {
			newBook[i] = book[i];
		}

		newBook[countContacts] = newContact;
		delete[] book;
		book = newBook;
		countContacts++;

	}

	void PhoneBook::DeleteContact(int numbPosition)
	{
		if (numbPosition > 0 && numbPosition <= countContacts) {

			for (int i = numbPosition - 1; i < countContacts - 1; i++) {
				book[i] = book[i + 1];
			}
			countContacts--;
		}
	}

	void PhoneBook::Print(Contact contact)const // виводити тільки один контакт
	{

			cout << contact.name << endl;
			cout << contact.mobileNumber << endl;
			cout << contact.homeNumber << endl;
		
	}

	void PhoneBook::SerchContactName(const char* _name) const
	{
		for (int i = 0; i < countContacts; i++) {
			if (strcmp(book[i].name, _name) == 0) {
				Print(book[i]);
			}
		}

	}

	void PhoneBook::SerchContactPhoneNumb(const char* _mobileNumber) const
	{
		for (int i = 0; i < countContacts; i++) {
			if (strcmp(book[i].mobileNumber, _mobileNumber) == 0)
			{
				Print(book[i]);

			}
		}
	}

	void PhoneBook::ShowContacts() const
	{
		for (int i = 0; i < countContacts; i++) {
			cout << i + 1 << ")" << book[i].name << endl;
			cout << book[i].mobileNumber << endl;
			cout << book[i].homeNumber << endl;
		}
		cout << endl;
	}

	void PhoneBook::Save() const
	{
		ofstream fout;
		fout.open("PhoneBook.txt");
		bool isOpen = fout.is_open();
		if (!isOpen) {
			cout << "Error" << endl;
		}

		for (int i = 0; i < countContacts; i++) {
			fout << book[i].name << endl;
			fout << book[i].mobileNumber << endl;
			fout << book[i].homeNumber << endl;
		}

		fout.close();
	}

	void PhoneBook::Load()
	{
		ifstream fin;
		fin.open("PhoneBook.txt");
		if (!fin.is_open()) {
			cout << "Error" << endl;
		}

		Contact info_from_file;

		while (!fin.eof())
		{
				fin >> info_from_file.name;
				fin >> info_from_file.mobileNumber;
				fin >> info_from_file.homeNumber;
				AddContact(info_from_file);

		}
		fin.close();
	}

