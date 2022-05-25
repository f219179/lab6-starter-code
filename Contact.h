#pragma once

#ifndef BASIC_LIB
#define BASIC_LIB
	#include <iostream>
	#include <string>
#endif // !BASIC_LIB

#include "Address.h"
class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	Address *address;

public:
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address);
	
	Address* return_add();
	void set_address(Address* address);
	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_mobile_number(std::string mobile_number);
	void set_email_address(std::string email_address);
	void set_house(Address* address);
	void set_street(Address* address);
	void set_city(Address* address);
	void set_country(Address* address);
	std::string get_first_name();
	std::string get_last_name();
	std::string get_mobile_number();
	std::string get_email_address();
	std::string get_house();
	std::string get_street();
	std::string get_city();
	std::string get_country();
	bool equals(Contact contact);
	Contact* copy_contact();
	Contact() {
		address = new Address;
	}
	
};
