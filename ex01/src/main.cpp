/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:44:30 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/17 23:30:30 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Form form1("Piscine", 100);
    Form form2("Cursus", 50);

    Bureaucrat bureaucrat("Staff", 75);

    try
    {
        Form form3("Test form", 200);
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;

    std::cout << std::endl;

    bureaucrat.signForm(form1);

    std::cout << std::endl;
    
    bureaucrat.signForm(form2);

    std::cout << std::endl;

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;

    return 0;
}
