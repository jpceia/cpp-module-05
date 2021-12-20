/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 04:36:00 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 19:52:12 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include <iostream>


PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
    Form("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) :
    Form(rhs)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& rhs)
{
    Form::operator=(rhs);
    return (*this);
}

void PresidentialPardonForm::action(void) const
{   
    std::cout << "Zafod Beeblebrox pardons " << this->getTarget()
        << " for a crime he did not commit." << std::endl;
}
