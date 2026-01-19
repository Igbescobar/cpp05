/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:17:14 by igngonza          #+#    #+#             */
/*   Updated: 2026/01/15 13:27:23 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
  std::cout << "=== Test 1: Create forms with valid grades ===" << std::endl;
  try
  {
    Form form1("Tax", 50, 25);
    std::cout << form1 << std::endl;

    Form form2("Contract", 1, 1);
    std::cout << form2 << std::endl;
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 2: Form with grade too high ===" << std::endl;
  try
  {
    Form form3("Invalid", 0, 50);
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 3: Form with grade too low ===" << std::endl;
  try
  {
    Form form4("Invalid", 151, 50);
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 4: Bureaucrat successfully signs form ===" << std::endl;
  try
  {
    Bureaucrat bob("Bob", 30);
    Form form5("Report", 50, 25);

    std::cout << bob << std::endl;
    std::cout << form5 << std::endl;
    bob.signForm(form5);
    std::cout << form5 << std::endl;
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 5: Bureaucrat fails to sign form (grade too low) ===" << std::endl;
  try
  {
    Bureaucrat intern("Intern", 100);
    Form form6("Top Secret", 10, 5);

    std::cout << intern << std::endl;
    std::cout << form6 << std::endl;
    intern.signForm(form6);
    std::cout << form6 << std::endl;
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 6: High-grade bureaucrat signs difficult form ===" << std::endl;
  try
  {
    Bureaucrat ceo("CEO", 1);
    Form form7("Merger Agreement", 5, 1);

    std::cout << ceo << std::endl;
    std::cout << form7 << std::endl;
    ceo.signForm(form7);
    std::cout << form7 << std::endl;
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  return (0);
}