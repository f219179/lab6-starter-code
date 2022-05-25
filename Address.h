#pragma once
#include <iostream>
#include <string>
class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;
public:
	Address(std::string house, std::string street, std::string city, std::string country);
	void set_house(std::string house);
	void set_street(std::string street);
	void set_city(std::string city);
	void set_country(std::string country);
	std::string get_house();
	std::string get_street();
	std::string  get_city();
	std::string get_country();
	bool equals(const Address& address);
	void print_address();
	Address *copy_address();
	Address();
};
