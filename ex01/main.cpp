/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:26:03 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/14 18:38:57 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data *original_struct = new Data;

	original_struct->test_char = 'a';
	original_struct->test_int = 42;
	original_struct->test_string = "Hello!";

	std::cout << "These are the variables in the original_struct Data structure:\n"
	<< "<test_char> a char with value: " << original_struct->test_char << std::endl
	<< "<test_int> an int with value: " << original_struct->test_int << std::endl
	<< "<test_string> a string with value: " << original_struct->test_string << std::endl << std::endl;

	uintptr_t	serialized = Serializer::serialize(original_struct);
	Data		*new_struct = Serializer::deserialize(serialized);
	
	std::cout << "These are the variables in the new_struct Data structure:\n"
	<< "<test_char> a char with value: " << new_struct->test_char << std::endl
	<< "<test_int> an int with value: " << new_struct->test_int << std::endl
	<< "<test_string> a string with value: " << new_struct->test_string << std::endl << std::endl;


	std::cout << "Address of *original_struct: " <<  original_struct << std::endl;
	std::cout << "Address of *new_struct: "<< new_struct << std::endl;
	
	delete original_struct;
}