#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>

class Contact{

public:
	int			index;

	Contact(void);
	~Contact(void);

	bool		add_contact(void);
	void		display_search(void) const;
	void		display_contact_detail(void) const;

private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nick_name;
	std::string	_phone_number;
	std::string	_darkest_secret;

};

#endif
