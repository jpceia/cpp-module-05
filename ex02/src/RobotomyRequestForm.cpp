/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 04:39:34 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 19:52:21 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
#include <iostream>
#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
    Form("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) :
    Form(rhs)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& rhs)
{
    Form::operator=(rhs);
    return (*this);
}

void RobotomyRequestForm::action(void) const
{  
    std::cout << "Drilling noises..." << std::endl;
    srand(time(NULL));
    if (rand() % 2)
        std::cout << this->getTarget() << " has been robotomized successfully."
            << std::endl;
    else
        std::cout << "It's a failure." << std::endl;
}
