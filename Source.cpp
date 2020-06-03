#include <iostream>
#include <fstream>
#include "PhonBook.h"

using namespace std;


int main() {
	PhoneBook p1;
	p1.AddContact({ "Vova","097-111-11-11","22-22-22" });
	p1.AddContact({ "Dima", "097-222-22-22","33-33-33" });
	p1.ShowContacts();
	p1.Save();


	system("pause");
	return 0;
}