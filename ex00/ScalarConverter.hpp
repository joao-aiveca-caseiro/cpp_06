/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:28:49 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/15 02:47:51 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>

class	ScalarConverter
{
	public:
		
		~ScalarConverter();
		static void			convert(std::string literal);
		static std::size_t	check_e(std::string literal);
		static std::size_t	check_f(std::string literal);
		static std::size_t	check_plus_minus(std::string literal);
		static std::size_t	check_decimal(std::string literal);
		static std::size_t	check_limits(std::string literal);
		static void 		convert_to_char(std::string literal, std::string original_type, int flag);
		static void 		convert_to_int(std::string literal, std::string original_type, int flag);
		static void 		convert_to_float(std::string literal, std::string original_type, int flag);
		static void			convert_to_double(std::string literal, std::string original_type, int flag);

	private:
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter &target);
		ScalarConverter	&operator=(const ScalarConverter &target);
};

#endif