#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "Contact.class.hpp"

class Phonebook{

public:
	Phonebook(void);
	~Phonebook(void);

	int		count;
	bool	book_add_contact(void);
	bool	book_search(void) const;

private:
	class Contact _contacts[8];

};

#endif
