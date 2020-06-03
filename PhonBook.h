#pragma once
#include <iostream>
#include <fstream>
#include "PhonBook.h"
using namespace std;

struct Contact
{
	char name[50];
	char mobileNumber[20];
	char homeNumber[10];
};

class PhoneBook
{
private:
	Contact* book;
	int countContacts;


public:
	PhoneBook();
	

	PhoneBook(Contact newnewContact);
	

	~PhoneBook();
	

	void AddContact(Contact newContact);
	

	void DeleteContact(int numbPasition);
	

	void Print(Contact contact)const;
	

	void SerchContactName(const char* _name) const;
	

	void SerchContactPhoneNumb(const char* _mobileNumber) const;
	

	void ShowContacts() const;
	

	void Save() const;
	

	void Load();
	
};


