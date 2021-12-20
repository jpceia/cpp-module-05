/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 23:40:25 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 04:55:08 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <iostream>

class RobotomyRequestForm : public Form
{
private:
    void action(void) const;

protected:
    RobotomyRequestForm(void) {} // private constructor

public:
    // Constructors
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& rhs);

    // Destructor
    ~RobotomyRequestForm(void);

    // Assignment operator overload
    using Form::operator=;

    // Other methods
    void execute(const Bureaucrat& executor) const;
};

#endif
