/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 05:19:39 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 05:42:03 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


class Intern
{
private:
    std::string _formType[3];
    Form* (Intern::*_makeForm[3])(const std::string&) const;

    Form* makeShrubberyCreationForm(const std::string& target) const;
    Form* makeRobotomyRequestForm(const std::string& target) const;
    Form* makePresidentialPardonForm(const std::string& target) const;

public:
    // Constructors
    Intern(void);
    Intern(const Intern& rhs);

    // Destructor
    ~Intern(void);

    // Assignment operator overload
    Intern& operator=(const Intern& rhs);

    // Other methods
    Form* makeForm(const std::string& formName, const std::string& target) const;
};

#endif
