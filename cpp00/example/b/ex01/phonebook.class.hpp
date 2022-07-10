/* ************************************************************************** */
/*                                                                            */
/*                                                       ..eeeee..            */
/*   phonebook.class.hpp                               e8'   8   '8e          */
/*                                                    d8     8     8b         */
/*   By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8         */
/*                                                    Y8 .e* 8 *e. 8P         */
/*   Created: 2021/03/24 17:21:31 by dries             *8*   8   *8*          */
/*   Updated: 2021/03/24 17:21:32 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include <iostream>
# include "contact.class.hpp"

class Phonebook {
	public:
		Phonebook(void);
		~Phonebook(void);
	private:
		Contact		_contacts[8];
		void		_search(void);
		void		_add(void);
		void		_index(void);
		void		_printIndex(void);
};

#endif
