/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 23:14:20 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 04:56:02 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(void) :
    _name(""),
    _signed(false),
    _grade(0)
{
}

Form::Form(std::string name, int grade) :
    _name(name),
    _signed(false),
    _grade(grade)
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &rhs) :
    _name(rhs._name),
    _signed(rhs._signed),
    _grade(rhs._grade)
{
}

Form::~Form(void)
{
}

Form& Form::operator= (Form const &rhs)
{
    if (this != &rhs)
    {
        const_cast<std::string&>(_name) = rhs._name;
        const_cast<int&>(_grade) = rhs._grade;
        _signed = rhs._signed;
    }
    return *this;
}

std::string Form::getName(void) const
{
    return _name;
}

bool Form::getSigned(void) const
{
    return _signed;
}

int Form::getGrade(void) const
{
    return _grade;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _grade)
        throw Form::GradeTooLowException();
    _signed = true;
    std::cout << "Form " << _name << " signed by " << bureaucrat.getName() << std::endl;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Form& rhs)
{
    out << "Form name: " << rhs.getName() << std::endl;
    out << "Form signed: " << (rhs.getSigned() ? "Yes" : "No") << std::endl;
    out << "Form grade: " << rhs.getGrade() << std::endl;
    return out;
}
