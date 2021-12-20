/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 05:42:06 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 05:45:45 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern(void)
{
    _formType[0] = "shrubbery creation";
    _formType[1] = "robotomy request";
    _formType[2] = "presidential pardon";
    _makeForm[0] = &Intern::makeShrubberyCreationForm;
    _makeForm[1] = &Intern::makeRobotomyRequestForm;
    _makeForm[2] = &Intern::makePresidentialPardonForm;
}

Intern::Intern(const Intern& rhs)
{
    *this = rhs;
}

Intern::~Intern(void)
{
}

Intern& Intern::operator=(const Intern& rhs)
{
    if (this != &rhs)
    {
        _formType[0] = rhs._formType[0];
        _formType[1] = rhs._formType[1];
        _formType[2] = rhs._formType[2];
        _makeForm[0] = rhs._makeForm[0];
        _makeForm[1] = rhs._makeForm[1];
        _makeForm[2] = rhs._makeForm[2];
    }
    return (*this);
}

Form* Intern::makeShrubberyCreationForm(const std::string& target) const
{
    return (new ShrubberyCreationForm(target));
}

Form* Intern::makeRobotomyRequestForm(const std::string& target) const
{
    return (new RobotomyRequestForm(target));
}

Form* Intern::makePresidentialPardonForm(const std::string& target) const
{
    return (new PresidentialPardonForm(target));
}

Form* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    for (int i = 0; i < 3; i++)
    {
        if (formName == _formType[i])
        {
            std::cout << "Intern creates " << _formType[i] << std::endl;
            return ((this->*_makeForm[i])(target));
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
    return (NULL);
}
