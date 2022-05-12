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
	bool equals(const Address& address);
	void print_address();
	Address copy_address();

	Address(std::string house, std::string street, std::string city, std::string country);
	Address() {}
};
