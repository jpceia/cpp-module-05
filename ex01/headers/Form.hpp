/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:52:32 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 04:51:54 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _grade;

protected:
    Form(void);

public:
    // Constructors
    Form(const std::string& name, int grade);
    Form(Form const &rhs);

    // Destructor
    ~Form();

    // Assignment operator overload
    Form& operator=(Form const &rhs);

    // Getters
    std::string getName(void) const;
    bool getSigned(void) const;
    int getGrade(void) const;

    // Other methods
    void beSigned(Bureaucrat &bureaucrat);
    
    // Exceptions
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what(void) const throw();
    };
    
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what(void) const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& rhs);

#endif
