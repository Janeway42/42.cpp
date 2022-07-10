/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   contact.class.hpp                                 e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/03/24 17:21:07 by dries             *8*   8   *8*          */
/*   Updated: 2021/03/24 17:21:08 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include <iostream>

class Contact {
	public:
		Contact(void);
		~Contact(void);

		void	writeContact(void);
		void	clearContact(void);
		void	getContact(void);
		void	getIndex(void);
		int		isEmpty(void);
	private:
		int		_isEmpty;
		char	_firstName[256];
		char	_lastName[256];
		char	_nickname[256];
		char	_login[256];
		char	_postalAddress[256];
		char	_emailAddress[256];
		char	_phoneNumber[256];
		char	_birthdayDate[256];
		char	_favoriteMeal[256];
		char	_underwearColor[256];
		char	_darkestSecret[256];

		void	_clearField(char *field);
		void	_printIndexField(char *value);
};

#endif
