/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:19:49 by igngonza          #+#    #+#             */
/*   Updated: 2026/01/21 11:26:42 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source)
    : AForm(source), target(source.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &source)
{
    if (this != &source)
    {
        AForm::operator=(source);
        this->target = source.target;
    }
    return *this;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* drilling noises *" << std::endl;

    std::srand(std::time(NULL));
    if (std::rand() % 2 == 0)
    {
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << this->target << "!" << std::endl;
    }
}