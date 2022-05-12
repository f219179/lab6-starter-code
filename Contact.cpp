#include "Contact.h"

/*
*	Implement a constructor that initializes all the Contact parts, including address. Call the setter to set values
*	as they have the logic to check correct input
*	Declaration is given in Contact.h
*/


/*
*	Implement getter/setters for all the member variables of Contact. Also declare them in the Contact.h header file
*	In each setter, do not set value if string is empty ("" 0 size). 
*   Check in phone number setter, Phone number must be 11 digits
*/



/*
*	Implement the equals function(as declared in header file) that takes a 
*   Contact object and checks if it is equal to current object refered by (this pointer). 
*   Compare all the attributes.
*   For comparing address of contact you can call the equals function of the Address object;
*   For example: this.address.equals
*/

Contact* Contact::copy_contact()
{
	/*
		Return a new object(deep copy of "this"[due to Address pointer, which should also be copied])
	*/
}
