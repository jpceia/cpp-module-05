/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 23:44:10 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 04:55:04 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <iostream>

class PresidentialPardonForm : public Form
{
private:
    void action(void) const;

protected:
    PresidentialPardonForm(void) {} // private constructor

public:
    // Constructors
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& rhs);

    // Destructor
    ~PresidentialPardonForm(void);

    // Assignment operator overload
    using Form::operator=;

    // Other methods
    void execute(const Bureaucrat& executor) const;
};

#endif
