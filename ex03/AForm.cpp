/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:19:19 by igngonza          #+#    #+#             */
/*   Updated: 2026/01/21 17:51:00 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Default"), hasBeenSigned(false), signGrade(150), execGrade(150) {}

AForm::AForm(const std::string name, unsigned int signGrade,
             unsigned int execGrade)
    : name(name), hasBeenSigned(false), signGrade(signGrade), execGrade(execGrade)
{
  if (signGrade < 1 || execGrade < 1)
    throw GradeTooHighException();
  if (signGrade > 150 || execGrade > 150)
    throw GradeTooLowException();
}

AForm::AForm(const AForm &source)
    : name(source.name), hasBeenSigned(source.hasBeenSigned),
      signGrade(source.signGrade), execGrade(source.execGrade) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &source)
{
  if (this != &source)
    this->hasBeenSigned = source.hasBeenSigned;
  return *this;
}

const std::string AForm::getName() const { return this->name; }

unsigned int AForm::getSignGrade() const { return this->signGrade; }

unsigned int AForm::getExecGrade() const { return this->execGrade; }

bool AForm::getHasBeenSigned() const { return this->hasBeenSigned; }

void AForm::beSigned(const Bureaucrat &obj)
{
  if (obj.getGrade() > this->signGrade)
    throw GradeTooLowException();
  this->hasBeenSigned = true;
}

void AForm::execute(Bureaucrat const &obj) const
{
  if (!this->hasBeenSigned)
    throw FormNotSignedException();
  if (obj.getGrade() > this->execGrade)
    throw GradeTooLowException();
  this->executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
  return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
  return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
  return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
  os << "Form " << form.getName() << ", signed: " << (form.getHasBeenSigned() ? "yes" : "no")
     << ", sign grade: " << form.getSignGrade()
     << ", exec grade: " << form.getExecGrade();
  return os;
}
