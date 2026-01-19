/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:56:07 by igngonza          #+#    #+#             */
/*   Updated: 2026/01/14 10:59:20 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT__HPP
#define BUREAUCRAT__HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat {
private:
  const std::string name;
  unsigned int grade;

public:
  Bureaucrat();
  Bureaucrat(std::string name, unsigned int grade);
  Bureaucrat(const Bureaucrat &source);
  Bureaucrat &operator=(const Bureaucrat &source);
  ~Bureaucrat();

  std::string getName() const;
  unsigned int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);
#endif
