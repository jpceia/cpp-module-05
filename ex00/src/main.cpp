/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:44:30 by jpceia            #+#    #+#             */
/*   Updated: 2021/11/20 01:51:11 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    try
    {
        Bureaucrat b3("b3", 151);
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        b1.incrementGrade();
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    b1.decrementGrade();
    std::cout << b1 << std::endl;
    
    try
    {
        b2.decrementGrade();
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Decrementing " << b2.getName() << " grade" << std::endl;
    b2.incrementGrade();
    std::cout << b2 << std::endl;   
}
