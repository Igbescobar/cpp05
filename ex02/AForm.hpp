#ifndef AFORM__HPP
#define AFORM__HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;
class AForm {
private:
  const std::string name;
  bool hasBeenSigned;
  const unsigned int signGrade;
  const unsigned int execGrade;

public:
  AForm();
  AForm(const std::string name, unsigned int signGrade, unsigned int execGrade);
  AForm(const AForm &source);
  virtual ~AForm();

  AForm &operator=(const AForm &source);
  const std::string getName() const;
  unsigned int getSignGrade() const;
  unsigned int getExecGrade() const;
  bool getHasBeenSigned() const;
  void beSigned(Bureaucrat const &obj);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);
#endif
