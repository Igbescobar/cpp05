#ifndef FORM__HPP
#define FORM__HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;
class Form
{
private:
  const std::string name;
  bool hasBeenSigned;
  const unsigned int signGrade;
  const unsigned int execGrade;

public:
  Form();
  Form(const std::string name, unsigned int signGrade,
       unsigned int execGrade);
  Form(const Form &source);
  ~Form();

  Form &operator=(const Form &source);
  std::string getName() const;
  unsigned int getSignGrade() const;
  unsigned int getExecGrade() const;
  bool getHasBeenSigned() const;
  void beSigned(Bureaucrat const &obj);

  class GradeTooHighException : public std::exception
  {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception
  {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Form &form);
#endif
