/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:18:50 by igngonza          #+#    #+#             */
/*   Updated: 2026/01/21 11:18:51 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
  std::cout << "=== Test 1: Valid bureaucrat ===" << std::endl;
  try
  {
    Bureaucrat bob("Bob", 75);
    std::cout << bob << std::endl;
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 2: Decrement until exception ===" << std::endl;
  try
  {
    Bureaucrat intern("Intern", 149);
    std::cout << intern << std::endl;
    intern.decrementGrade();
    std::cout << intern << std::endl;
    intern.decrementGrade(); // Should throw
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 3: Increment until exception ===" << std::endl;
  try
  {
    Bureaucrat ceo("CEO", 2);
    std::cout << ceo << std::endl;
    ceo.incrementGrade();
    std::cout << ceo << std::endl;
    ceo.incrementGrade(); // Should throw
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 4: Grade too high in constructor ===" << std::endl;
  try
  {
    Bureaucrat invalid("Invalid", 0);
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 5: Grade too low in constructor ===" << std::endl;
  try
  {
    Bureaucrat invalid("Invalid", 151);
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}