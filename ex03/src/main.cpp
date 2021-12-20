/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:44:30 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 05:46:01 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Form* form;
    Intern intern;
    Bureaucrat bureaucrat("High Profile Bureaucrat", 1);

    form = intern.makeForm("robotomy request", "Ford Prefect");
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;

    form = intern.makeForm("presidential pardon", "Marvin the Paranoid Android");
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;
    
    form = intern.makeForm("shrubbery creation", "Arthur Dent");
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;

    form = intern.makeForm("invalid form", "invalid");

    return 0;
}
