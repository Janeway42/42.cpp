#include "MutantStack.hpp"

int main()
{
	std::cout << "\n ------------ MutantStack test ------------------\n";

	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	std::cout << "Last added: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Mutant size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "Display Mutant: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);  // stack copy constructor 
	std::cout << "size s (copy): " << s.size() << std::endl;
	std::cout << "Last added: " << s.top() << std::endl;
	s.pop();
	std::cout << "Last added: " << s.top() << std::endl;

	std::cout << "\n ----------------- List test --------------------\n";

	std::list<int> mlist;
	
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << "Last added: " << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << "List size: " << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::cout << std::endl;
	std::list<int>::iterator itList = mlist.begin();
	std::list<int>::iterator iteList = mlist.end();

	++itList;
	--itList;
	std::cout << "Display List: ";
	while (itList != iteList)
	{
		std::cout << *itList << " ";
		++itList;
	}
	std::cout << std::endl;


	std::cout << "\n --------------- Vector test ---------------------\n";

	std::vector<int> mvector;
	
	mvector.push_back(5);
	mvector.push_back(17);
	std::cout << "Last added: " << mvector.back() << std::endl;
	mvector.pop_back();
	std::cout << "Vector size: " << mvector.size() << std::endl;
	mvector.push_back(3);
	mvector.push_back(5);
	mvector.push_back(737);
	mvector.push_back(0);

	std::cout << std::endl;
	std::vector<int>::iterator itVector = mvector.begin();
	std::vector<int>::iterator iteVector = mvector.end();

	++itVector;
	--itVector;
	std::cout << "Display Vector: ";
	while (itVector != iteVector)
	{
		std::cout << *itVector << " ";
		++itVector;
	}
	std::cout << std::endl;
	std::cout << "\n -------------------------------------------------\n";

	return (0);
}