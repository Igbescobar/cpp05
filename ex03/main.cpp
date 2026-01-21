/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:17:14 by igngonza          #+#    #+#             */
/*   Updated: 2026/01/21 17:44:51 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

void testInternFormCreation()
{
  std::cout << "=== TEST 1: Creating Forms with Intern ===" << std::endl;

  Intern someRandomIntern;
  AForm *form1;
  AForm *form2;
  AForm *form3;

  // Test robotomy request (example from subject)
  std::cout << "\n--- Creating Robotomy Request for Bender ---" << std::endl;
  form1 = someRandomIntern.makeForm("robotomy request", "Bender");
  if (form1)
  {
    std::cout << "Form created: " << form1->getName() << std::endl;
    delete form1;
  }

  // Test presidential pardon
  std::cout << "\n--- Creating Presidential Pardon for Arthur Dent ---" << std::endl;
  form2 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
  if (form2)
  {
    std::cout << "Form created: " << form2->getName() << std::endl;
    delete form2;
  }

  // Test shrubbery creation
  std::cout << "\n--- Creating Shrubbery Creation for home ---" << std::endl;
  form3 = someRandomIntern.makeForm("shrubbery creation", "home");
  if (form3)
  {
    std::cout << "Form created: " << form3->getName() << std::endl;
    delete form3;
  }

  std::cout << std::endl;
}

void testInvalidFormName()
{
  std::cout << "=== TEST 2: Invalid Form Name ===" << std::endl;

  Intern intern;

  std::cout << "\n--- Trying to create 'coffee making' form ---" << std::endl;
  intern.makeForm("coffee making", "break room");

  std::cout << "\n--- Trying to create 'vacation request' form ---" << std::endl;
  intern.makeForm("vacation request", "Hawaii");

  std::cout << std::endl;
}

int main()
{
  testInternFormCreation();
  std::cout << "----------------------------------------\n"
            << std::endl;

  testInvalidFormName();
  std::cout << "----------------------------------------\n"
            << std::endl;

  return 0;
}