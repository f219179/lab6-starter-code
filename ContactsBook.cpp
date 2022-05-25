#include "ContactsBook.h"
#include <fstream>
void ContactsBook::add_contact(Contact& contact)
{
	/*
		- Check if the list is full, if it is full call the resize function
		- If list is not full add the contact to the end of the array 
		- (end means the place where last contact was inserted)
		- At start it will be 0th index as no contact has been inserted before so 
		- count is zero (contacts_count member)
		- Increment the count
		- As inserted successfully, return 1
	*/
	if (full())
	{
		resize_list();
	}
	else
	{
		contacts_list[contacts_count] = contact;
		this->contacts_count++;
	}
}
int ContactsBook::total_contacts()
{
	/*
	*	Return the total contacts currently stored
	*/

	/*
	*	Remove this return -1; before writing your code
	*/
	return contacts_count;
}
bool ContactsBook::full()
{
	/*
	* Return true if list is full, false otherwise
	*/
	if (contacts_count==size_of_contacts)
		return true;
	/*
	* 
	*	Remove this return false; before writing your code
	*/
	else 
	return false;
}

void ContactsBook::resize_list()
{
	/*
	*	Here you will resize the contact list, see example code given in lab manual to see how to resize arrays
	*	You will allocate a temporary new array of double the current size and copy the contacts from 
	*   previous array to this array one by one, get the copy of each contact using copy_contact 
	*   function of Contact class
	*	Delete the previous array
	*	Assign the new temporary array to the contacts_list pointer
	*	Updated the this->size_of_contacts with new size
	*/
	Contact *array;

	array = new Contact[size_of_contacts * 2];

	for (int i = 0;i < size_of_contacts;i++)
	{
		array[i]=contacts_list[i];
	}
	delete[]contacts_list;

	contacts_list = new Contact [size_of_contacts * 2];

	for (int i = 0;i < size_of_contacts;i++)
	{
		contacts_list[i] = array[i];
	}

	delete[]array;
}

Contact* ContactsBook::search_contact(std::string first_name, std::string last_name)
{
	for (int i = 0;i < contacts_count;i++)
	{
		if (contacts_list[i].get_first_name() == first_name && contacts_list[i].get_last_name() == last_name)
			return &contacts_list[i];
	}
	/*
	*	In all search functions perform the searching according the given parameter and return a copy of the contact using copy func
	*	Remove this return nullptr; before writing your code
	*/
}
void ContactsBook::print_contact() {
	for (int i = 0;i < contacts_count;i++)
	{
		std::cout << contacts_list[i].get_first_name() << std::endl;
		std::cout << contacts_list[i].get_last_name() << std::endl;
		std::cout << contacts_list[i].get_email_address() << std::endl;
		std::cout << contacts_list[i].get_mobile_number() << std::endl;

		std::cout << contacts_list[i].return_address()->get_house() << std::endl;
		std::cout << contacts_list[i].return_address()->get_street() << std::endl;
		std::cout << contacts_list[i].return_address()->get_city() << std::endl;
		std::cout << contacts_list[i].return_address()->get_country() << std::endl;
	}
}
/*Contact* ContactsBook::search_contact(std::string phone)
{
	
	//	Remove this return nullptr; before writing your code
	
for (int i = 0; i < contacts_count; i++)
{
	if (contacts_list[i].get_mobile_number() == phone)
	{
		return &contacts_list[i];
	}
}
}*/


/*Contact* ContactsBook::search_contact(Address address)
{
	//if(contacts_list->)
	
	//Remove this return nullptr; before writing your code
	
	for (int i = 0;i < contacts_count;i++)
	{
		if (address.get_house() == contacts_list[i].returnadd()->get_house())
		{
			return &contacts_list[i];
		}
	}
}*/

ContactsBook::ContactsBook(int size_of_list)
{
	/*
	*	Initialize the contacts_list array, also initialize the size and count members accordingly
	*/
	contacts_list = new Contact[size_of_contacts];
}

Contact* ContactsBook::copy_contacts_list() {
	Contact* con;
	con = new Contact[size_of_contacts];

	for (int i = 0; i < size_of_contacts; i++)
	{
		con[i].set_email_address(contacts_list[i].get_email_address());
		con[i].set_first_name(contacts_list[i].get_first_name());
		con[i].set_last_name(contacts_list[i].get_last_name());
		con[i].set_mobile_number(contacts_list[i].get_mobile_number());
		con[i].set_address(contacts_list[i].return_address()->copy_address());
	}
	return con;
}

void ContactsBook::print_contacts_sorted(std::string choice)
{
	/*
	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
	*	Call the sort function sort_contacts_list to sort the newly created copy
	*	This copy is created to avoid changing the original insertion order of contact list
	*	Then print the contacts in following format:
	*	[First Name] [Last Name] [Mobile] [Email]
	*	Call the address print function to print address on next line
	*/
	Contact* duplicate1;
	duplicate1= copy_contacts_list();

	sort_contacts_list(duplicate1, choice);

	for (int i = 0; i < contacts_count; i++)
	{
			std::cout << std::endl << duplicate1[i].get_first_name()
			<< " " << duplicate1[i].get_last_name() << " " << 
			duplicate1[i].get_mobile_number() << 
			" " << duplicate1[i].get_email_address() <<
			std::endl;
			duplicate1[i].return_address()->print_address();
	}
}

void ContactsBook::swap(Contact* contacts_list, int one, int two) {
	Contact* ptr = new Contact;
	*ptr = contacts_list[one];
	ptr->set_address(contacts_list[one].return_address()->copy_address());
	contacts_list[one] = contacts_list[two];
	contacts_list[two].set_address(contacts_list[two].return_address()->copy_address());
	contacts_list[two] = *ptr;
	contacts_list[two].set_address(ptr->return_address()->copy_address());
}

bool ContactsBook::compare(std::string choice, Contact& choice1, Contact& choice2) {
	if (choice == "first_name" || choice == "last_name")
	{

		if (choice1.get_first_name() >= choice2.get_last_name())
			return true;
		else
			return -1;
	}
	else if (choice == "email_address") {
		if (choice1.get_email_address() >= choice2.get_email_address())
			return true;
		else
			return -1;
	}
	else if (choice == "address") {
		if (choice1.return_address()->get_country() >= choice2.return_address()->get_country())
		{
			return true;
		}
		else
		{
			return -1;
		}
	}
	return 0;
}

void ContactsBook::sort_contacts_list(Contact *contacts_list, std::string choice)
{
	/*
		You should not duplicate the code to sort based on choices
		Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
		Sort by the fist letter of first name or last name as given in choice
	*/
	for (int i = 0; i < contacts_count; i++)
	{
		for (int j = 1; j < contacts_count; j++)
		{
			if (compare(choice, contacts_list[i], contacts_list[j]) == 1) {
				swap(contacts_list, i, j);
			}
		}
	}
}
void ContactsBook::merge_duplicates() 
{
	// Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal
	// If there are three copies of a Contact, then only one should remain
	// For example: If total contact are 10, and 2 contacts are same, after removing duplicates
	// 9 contacts will be left; and the this->contacts_count of list will 9
	// At the end display contacts merged, and count of merged contacts
	int *ptr, counter = 0;
	ptr = new int[contacts_count];

	for (int i = 0; i < contacts_count - 1; i++)
	{
		for (int j = i + 1; j < contacts_count; j++)
		{
			if (contacts_list[i].equals(contacts_list[j])) {
				
				
					ptr[counter] = j;
				counter++;
			}
		}
	}
	std::cout << "Merge Contacts= " << counter;
}
void ContactsBook::save_to_file(std::string file_name) 
{
	/*
	*	In this function you will store all the contacts to a file
	*	On first line store size_of_contacts
	*	On second line store contacts_count
	*	On next lines store contacts in the following format:
	*   2 lines for each contact
	*   On oneline write contact attributes(except address) in comma separated format. On second line
	*	store address atributes in the same format
	*	first_name,last_name,mobile_number,email_address
	*	house,street,city,country
	*	Close the file
	*/
	
		std::ofstream my_file;
		my_file.open(file_name, std::ios::out);

		my_file << size_of_contacts << std::endl;
		my_file << contacts_count << std::endl;

		for (int i = 0; i < contacts_count; i++)
		{
			my_file << contacts_list[i].get_first_name() << ',' << contacts_list[i].get_last_name()
				<< ',' << contacts_list[i].get_mobile_number() << ',' << contacts_list[i].get_email_address() << std::endl;

			my_file << contacts_list[i].return_address()->get_house() << ',' << contacts_list[i].return_address()->get_street()
				<< ',' << contacts_list[i].return_address()->get_city() << ',' << contacts_list[i].return_address()->get_country() << std::endl;
		}
}
ContactsBook* ContactsBook::load_from_file(std::string file)
{
	int len = 0;
	int count = 0;
	std::string container;
	std::ifstream file_folder;
	file_folder.open(file, std::ios::in);

	file_folder >> size_of_contacts;
	file_folder >> contacts_count;

	ContactsBook* contacts_Book_Temp;
	
	contacts_Book_Temp = new ContactsBook{ len };
	contacts_Book_Temp -> contacts_count = count;
	contacts_Book_Temp -> size_of_contacts = count;

	Address* add;
	add = new Address[contacts_count];
	for (int i = 0; i < count; i++)
	{
		getline(file_folder, container, ',');

		contacts_Book_Temp -> contacts_list[i].set_first_name (container) ;
		getline(file_folder, container, ',');

		contacts_Book_Temp ->  contacts_list[i].set_last_name (container) ;
		getline(file_folder, container, ',');

		contacts_Book_Temp ->  contacts_list[i].set_mobile_number  ( container );
		getline(file_folder, container, '\n');

		contacts_Book_Temp ->  contacts_list[i].set_email_address( container );
		getline(file_folder, container, ',');

		add[i].set_house(container);
		getline(file_folder, container, ',');

		add[i].set_street(container);
		getline(file_folder, container, ',');

		add[i].set_city(container);
		getline(file_folder, container, '\n');

		add[i].set_country(container);
		contacts_Book_Temp->contacts_list[i].set_address(add + i);
	}
	return contacts_Book_Temp;
}

