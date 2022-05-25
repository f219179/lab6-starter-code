#include "Contact.h"
//using namespace Contact;
/*
*	Implement a constructor that initializes all the Contact parts, including address. Call the setter to set values
*	as they have the logic to check correct input
*	Declaration is given in Contact.h
*/
Contact::Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->mobile_number = mobile_number;
	this->email_address = email_address;
	this->address->set_house(address->get_house());
	this->address->set_street(address->get_street());
	this->address->set_city(address->get_city());
	this->address->set_country(address->get_country());
}
/*
*	Implement getter/setters for all the member variables of Contact. Also declare them in the Contact.h header file
*	In each setter, do not set value if string is empty ("" 0 size). 
*   Check in phone number setter, Phone number must be 11 digits
*/ 
void Contact::set_first_name(std::string first_name)
{
	if (first_name == "0")
	{
		std::cout << "Empty string" << std::endl;
	}
	this->first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
	if (last_name == "0")
	{
		std::cout << "Empty string" << std::endl;
	}
	this->last_name = last_name;
}

void Contact::set_mobile_number(std::string mobile_number)
{
	int no;
	no = mobile_number.length();
	if (no == 11)
	{
		this->mobile_number = mobile_number;
	}
	while(no!=11)
	{
		std::cout << "Incorrect Number.";
		std::cin >> this-> mobile_number;

	}
}
void Contact::set_address(Address* address) { this->address = address; }
Address* Contact::return_address()
{
	return address;
}
void Contact::set_email_address(std::string email_address)
{
	if (email_address == "0")
	{
		std::cout << "Empty string" << std::endl;
	}
	this->email_address = email_address;
}

void Contact::set_house(Address *address) {
	return_address()->Address::set_house(address->get_house());
}

void Contact::set_street(Address* address) {
	return_address()->Address::set_street(address->get_street());
}

void Contact::set_city(Address* address) {
	return_address()->Address::set_city(address->get_city());
}

void Contact::set_country(Address* address) {
	return_address()->Address::set_country(address->get_country());
}


std::string Contact::get_first_name()
{
	return first_name;
}

std::string Contact::get_last_name()
{
	return last_name;
}

std::string Contact::get_mobile_number()
{
	return mobile_number;
}

std::string Contact::get_email_address()
{
	return email_address;
}

std::string Contact::get_house() {
	return return_address()->get_house();
}

std::string Contact::get_street() {
	return return_address()->get_street();
}
std::string Contact::get_city() {
	return return_address()->get_city();
}


std::string Contact::get_country() {
	return return_address()->get_country();
}

/*
*	Implement the equals function(as declared in header file) that takes a 
*   Contact object and checks if it is equal to current object refered by (this pointer). 
*   Compare all the attributes.
*   For comparing address of contact you can call the equals function of the Address object;
*   For example: this.address.equals
*/
bool Contact::equals(Contact contact)
{
	if (this->first_name == contact.first_name && this->last_name == contact.last_name && this->mobile_number == contact.mobile_number && this->email_address == contact.email_address)
	{
		
		if (this->address->equals( *contact.return_address()))
		{
			return 1;
		}
	}
	return 0;
}

Contact* Contact::copy_contact()
{
	/*
		Return a new object(deep copy of "this"[due to Address pointer, which should also be copied])
	*/
	Contact* obj;
	obj = new Contact;
	obj -> first_name = this -> first_name;
	obj -> last_name = this -> last_name;
	obj -> mobile_number = this -> mobile_number;
	obj -> email_address = this -> email_address;
	obj -> address = address -> copy_address();
	return obj;
}

