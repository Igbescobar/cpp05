#include "Form.hpp"
#include <iostream>

Form::Form() : name("default"), hasBeenSigned(false), signGrade(0), execGrade(0)
{
}

Form::Form(const std::string name, unsigned int signGrade,
           unsigned int execGrade) : name(name), hasBeenSigned(false),
                                     signGrade(signGrade), execGrade(execGrade)
{
  if (this->signGrade > 150 || this->execGrade > 150)
    throw GradeTooLowException();
  else if (this->signGrade < 1 || this->execGrade < 1)
    throw GradeTooHighException();
}

Form::Form(const Form &source) : signGrade(source.signGrade),
                                 execGrade(source.execGrade)
{
  *this = source;
}

Form::~Form()
{
}

Form &Form::operator=(const Form &source)
{
  if (this != &source)
  {
    this->hasBeenSigned = source.hasBeenSigned;
  }
  return (*this);
}

std::string Form::getName() const
{
  return (this->name);
}

unsigned int Form::getSignGrade() const
{
  return (this->signGrade);
}

unsigned int Form::getExecGrade() const
{
  return (this->execGrade);
}

bool Form::getHasBeenSigned() const
{
  return (this->hasBeenSigned);
}

void Form::beSigned(Bureaucrat const &obj)
{
  if (this->hasBeenSigned)
    return;
  else if (obj.getGrade() > this->signGrade)
    throw GradeTooLowException();
  else
    this->hasBeenSigned = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
  return ("Grade too low");
}

const char *Form::GradeTooHighException::what() const throw()
{
  return ("Grade too high");
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
  os << "Form " << obj.getName() << " is signed: " << obj.getHasBeenSigned()
     << ", can be signed by grade " << obj.getSignGrade()
     << ", can be executed by grade " << obj.getExecGrade();
  return (os);
}