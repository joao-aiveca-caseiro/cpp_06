/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:17:01 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/10 18:22:46 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(void)
{
	std::cout << static_cast<char> (42) << std::endl;
	ScalarConverter::convert("-42.2");
}