/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:17:14 by igngonza          #+#    #+#             */
/*   Updated: 2026/01/21 11:48:40 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
  std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
  try
  {
    Bureaucrat bob("Bob", 137);
    ShrubberyCreationForm shrubbery("home");

    std::cout << bob << std::endl;
    std::cout << shrubbery << std::endl;

    bob.signForm(shrubbery);
    bob.executeForm(shrubbery);
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 2: RobotomyRequestForm ===" << std::endl;
  try
  {
    Bureaucrat alice("Alice", 45);
    RobotomyRequestForm robotomy("Bender");

    std::cout << alice << std::endl;
    std::cout << robotomy << std::endl;

    alice.signForm(robotomy);
    alice.executeForm(robotomy);
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
  try
  {
    Bureaucrat president("President", 1);
    PresidentialPardonForm pardon("Arthur");

    std::cout << president << std::endl;
    std::cout << pardon << std::endl;

    president.signForm(pardon);
    president.executeForm(pardon);
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 4: Execution without signing ===" << std::endl;
  try
  {
    Bureaucrat john("John", 1);
    ShrubberyCreationForm unsigned_form("garden");

    john.executeForm(unsigned_form);
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 5: Execution with insufficient grade ===" << std::endl;
  try
  {
    Bureaucrat lowGrade("LowGrade", 100);
    Bureaucrat highGrade("HighGrade", 5);
    PresidentialPardonForm pardon("Criminal");

    highGrade.signForm(pardon);
    lowGrade.executeForm(pardon);
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 6: Sign with insufficient grade ===" << std::endl;
  try
  {
    Bureaucrat intern("Intern", 150);
    PresidentialPardonForm pardon("Someone");

    intern.signForm(pardon);
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}