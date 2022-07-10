#ifndef YELLOWPAGES_HPP
#define YELLOWPAGES_HPP

class Contact
{

};

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);	

private:
	Contact	Contacts[8];
	void	search(void);
	void	add(void);
	void	index(void);
	void	printIndex(void);
};

#endif