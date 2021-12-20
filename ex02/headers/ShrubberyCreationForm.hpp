/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 23:40:28 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 04:55:12 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <iostream>

class ShrubberyCreationForm : public Form
{
private:
    void action(void) const;

protected:
    ShrubberyCreationForm(void) {} // private constructor

public:
    // Constructors
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& rhs);

    // Destructor
    ~ShrubberyCreationForm(void);

    // Assignment operator overload
    using Form::operator=;

    // Other methods
    void execute(const Bureaucrat& executor) const;
};

#endif
