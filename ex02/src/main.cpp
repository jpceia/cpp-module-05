/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:44:30 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 04:48:05 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat highProfileBureaucrat("High Profile Bureaucrat", 1);
    Bureaucrat lowProfileBureaucrat("Low Profile Bureaucrat", 100);

    ShrubberyCreationForm shrubberyCreationForm("Arthur Dent");
    RobotomyRequestForm robotomyRequestForm("Ford Prefect");
    PresidentialPardonForm presidentialPardonForm("Marvin the Paranoid Android");
    
    try
    {
        lowProfileBureaucrat.signForm(shrubberyCreationForm);
        lowProfileBureaucrat.signForm(robotomyRequestForm);
        lowProfileBureaucrat.signForm(presidentialPardonForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        highProfileBureaucrat.signForm(shrubberyCreationForm);
        highProfileBureaucrat.signForm(robotomyRequestForm);
        highProfileBureaucrat.signForm(presidentialPardonForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        lowProfileBureaucrat.executeForm(shrubberyCreationForm);
        lowProfileBureaucrat.executeForm(robotomyRequestForm);
        lowProfileBureaucrat.executeForm(presidentialPardonForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        highProfileBureaucrat.executeForm(shrubberyCreationForm);
        highProfileBureaucrat.executeForm(robotomyRequestForm);
        highProfileBureaucrat.executeForm(presidentialPardonForm);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
