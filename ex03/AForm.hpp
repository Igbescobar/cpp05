/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:19:23 by igngonza          #+#    #+#             */
/*   Updated: 2026/01/21 11:19:25 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM__HPP
#define AFORM__HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;
class AForm
{
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
  bool getHasBeenSigned() const;
  unsigned int getSignGrade() const;
  unsigned int getExecGrade() const;

  void beSigned(Bureaucrat const &obj);
  void execute(Bureaucrat const &obj) const;

  virtual void executeAction() const = 0;

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

  class FormNotSignedException : public std::exception
  {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);
#endif
