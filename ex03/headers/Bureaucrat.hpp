/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:19:53 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 04:54:58 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

    void checkGrade(int grade);

protected:
    Bureaucrat(void) {}

public:
    // Constructors
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(Bureaucrat const &rhs);

    // Destructor
    ~Bureaucrat();

    // Assignment operator overload
    Bureaucrat& operator=(Bureaucrat const &rhs);

    // Ostream operator overload
    std::ostream &operator<<(std::ostream &out);

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Increment and decrement
    void incrementGrade(void);
    void decrementGrade(void);

    // Other methods
    void signForm(Form &form);
    void executeForm(const Form& form);

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

// Ostream operator overload
std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif
