/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:06:39 by igngonza          #+#    #+#             */
/*   Updated: 2026/01/15 13:27:46 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("Default"), grade(1) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int num) : name(name) {
  if (num < 1)
    throw GradeTooHighException();
  else if (num > 150)
    throw GradeTooLowException();
  this->grade = num;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source) { *this = source; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source) {
  if (this != &source)
    this->grade = source.grade;
  return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return (this->name); }

unsigned int Bureaucrat::getGrade() const { return (this->grade); }

void Bureaucrat::incrementGrade() {
  unsigned int result;

  result = this->getGrade() - 1;
  if (result < 1)
    throw GradeTooHighException();
  this->grade = result;
}

void Bureaucrat::decrementGrade() {
  unsigned int result;

  result = this->getGrade() + 1;
  if (result > 150)
    throw GradeTooLowException();
  this->grade = result;
}

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << this->name << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->name << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is to low!");
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is to hight!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
  os << obj.getName() << ", bureaucrat grade: " << obj.getGrade();
  return (os);
}
