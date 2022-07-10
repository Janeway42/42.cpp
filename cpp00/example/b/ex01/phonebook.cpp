/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   phonebook.cpp                                     e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/03/24 17:21:35 by dries             *8*   8   *8*          */
/*   Updated: 2021/03/24 17:21:36 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	testContact(void) {
	Contact contact;
	contact.writeContact();
	contact.getContact();
	contact.getIndex();
	contact.clearContact();
	contact.getContact();
	return;
}

int		main(void) {
	Phonebook	phonebook;
	return (0);
}
