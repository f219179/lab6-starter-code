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
	bool equals(Contact contact);
	Contact* copy_contact();

	Contact() {}
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address *address);
};
