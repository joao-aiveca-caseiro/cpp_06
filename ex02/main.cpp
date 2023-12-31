/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:46:13 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/15 15:01:42 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base *generate(void)
{
	std::srand(time(NULL));
	int	random = std::rand() % 3;
	
	switch (random)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	}

	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a_test = dynamic_cast<A&>(p);
		(void)a_test;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		B &b_test = dynamic_cast<B&>(p);
		(void)b_test;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		C &c_test = dynamic_cast<C&>(p);
		(void)c_test;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e){}
}

int	main(void)
{
	std::cout << "-- identifying the type of an instance of A (must print A)" << std::endl;
	Base *a = new A;
	identify(a);

	Base *generated = generate();
	std::cout << "-- identifying the type of a generated object by pointer" << std::endl;
	identify(generated);
	std::cout << "-- identifying the type of the same object by reference \n-- (must give same result as above)" << std::endl;
	identify(*generated);
	
	delete generated;
	delete a;
}