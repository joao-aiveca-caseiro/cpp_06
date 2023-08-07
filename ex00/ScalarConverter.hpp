/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:28:49 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/07 16:44:48 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class	ScalarConverter
{
	public:
		
		~ScalarConverter();
		static void	convert(std::string literal);

	private:
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter &target);
		ScalarConverter	&operator=(const ScalarConverter &target);
};

#endif