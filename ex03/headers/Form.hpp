/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:52:32 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 04:53:16 by jpceia           ###   ########.fr       */
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
    const std::string _target;
    bool _signed;
    const int _sign_grade;
    const int _exec_grade;

    void checkGrade(int grade) const;

protected:
    Form(void);
    virtual void action(void) const = 0;

public:
    // Constructors
    Form(const std::string& name,
         const std::string& target,
         int sign_grade, int exec_grade);
    Form(Form const &rhs);

    // Destructor
    virtual ~Form();

    // Assignment operator overload
    Form& operator=(Form const &rhs);

    // Getters
    std::string getName(void) const;
    std::string getTarget(void) const;
    bool getSigned(void) const;
    int getSignGrade(void) const;
    int getExecGrade(void) const;

    // Other methods
    void beSigned(Bureaucrat &bureaucrat);
    void execute(const Bureaucrat& executor) const;
    
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

    class NotSignedException : public std::exception
    {
        public:
            virtual const char* what(void) const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& rhs);

#endif
