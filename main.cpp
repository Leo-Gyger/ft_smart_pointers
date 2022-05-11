#include <iostream>
#include "unique_ptr.hpp"
#include "shared_ptr.hpp"
class a
{
	public:
		int	val;
	a()
	{
		std::cout << "built" << std::endl;
	}
	~a()
	{
		std::cout << "destroyed" << std::endl;
	}
};
void test(ft::unique_ptr<a> t)
{
	t->val = 3;
}
int	main()
{
	a e;
	ft::unique_ptr<a> ptr(e);
	int r = 2;
	test(ptr);
	ft::unique_ptr<int> ptr2(&r);
	ft::unique_ptr<int> ptr3;
	ptr3 = ptr2;
	std::cout << e.val << std::endl;
	int *i = ptr3.release();
	std::cout  << *i << std::endl;
	delete i;
	ft::shared_ptr<a> sptr(e);
	ft::shared_ptr<a> sptr2(sptr);
	std::cout << sptr->val << sptr2->val << std::endl;
}
