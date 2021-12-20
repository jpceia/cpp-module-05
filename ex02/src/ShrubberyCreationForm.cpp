/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 03:55:44 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 04:56:19 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
    Form("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) :
    Form(rhs)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void ShrubberyCreationForm::action(void) const
{   
    std::ofstream ofs;
    std::string fname(this->getTarget() + "_shrubbery");
    
    ofs.open(fname.c_str(), std::ios::out | std::ios::trunc);
    if (ofs.is_open())
    {
        std::cout << "Creating a shrubbery for " << this->getTarget() << "." << std::endl;
        
        ofs << "                                         " << std::endl;
        ofs << "               ,@@@@@@@,                 " << std::endl;
        ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o.     " << std::endl;
        ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o    " << std::endl;
        ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'   " << std::endl;
        ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'   " << std::endl;
        ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'    " << std::endl;
        ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'      " << std::endl;
        ofs << "       |o|        | |         | |        " << std::endl;
        ofs << "       |.|        | |         | |        " << std::endl;
        ofs << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
        
        ofs.close();
        
        std::cout << "Shrubbery created." << std::endl;
    }
    else
        std::cout << "Error: could not open file." << std::endl;
}
