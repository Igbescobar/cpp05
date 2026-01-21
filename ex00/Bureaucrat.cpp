/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:06:39 by igngonza          #+#    #+#             */
/*   Updated: 2026/01/21 17:48:16 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(1) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int num) : name(name)
{
  if (num < 1)
    throw GradeTooHighException();
  else if (num > 150)
    throw GradeTooLowException();
  this->grade = num;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source) { *this = source; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source)
{
  if (this != &source)
    this->grade = source.grade;
  return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return this->name; }

unsigned int Bureaucrat::getGrade() const { return (this->grade); }

void Bureaucrat::incrementGrade()
{
  if (this->grade <= 1)
    throw GradeTooHighException();
  this->grade--;
}

void Bureaucrat::decrementGrade()
{
  if (this->grade >= 150)
    throw GradeTooLowException();
  this->grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Grade is too low!");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Grade is too high!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
  return os;
}
