/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:18:34 by igngonza          #+#    #+#             */
/*   Updated: 2026/01/21 17:32:11 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
private:
    AForm *createPresidentialPardonForm(const std::string &target);
    AForm *createRobotomyRequestForm(const std::string &target);
    AForm *createShrubberyCreationForm(const std::string &target);

public:
    Intern();
    Intern(const Intern &source);
    ~Intern();

    Intern &operator=(const Intern &source);

    AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif