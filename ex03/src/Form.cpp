/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 23:14:20 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 04:56:10 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(void) :
    _name(""),
    _target(""),
    _signed(false),
    _sign_grade(0),
    _exec_grade(0)
{
}

Form::Form(
    const std::string& name,
    const std::string& target,
    int sign_grade,
    int exec_grade
) :
    _name(name),
    _target(target),
    _signed(false),
    _sign_grade(sign_grade),
    _exec_grade(exec_grade)
{
    checkGrade(sign_grade);
    checkGrade(exec_grade);
}

Form::Form(Form const &rhs) :
    _name(rhs._name),
    _target(rhs._target),
    _signed(rhs._signed),
    _sign_grade(rhs._sign_grade),
    _exec_grade(rhs._exec_grade)
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
        const_cast<std::string&>(_target) = rhs._target;
        const_cast<int&>(_sign_grade) = rhs._sign_grade;
        const_cast<int&>(_exec_grade) = rhs._exec_grade;
        _signed = rhs._signed;
    }
    return *this;
}

void Form::checkGrade(int grade) const
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
}

std::string Form::getName(void) const
{
    return _name;
}

std::string Form::getTarget(void) const
{
    return _target;
}

bool Form::getSigned(void) const
{
    return _signed;
}

int Form::getSignGrade(void) const
{
    return _sign_grade;
}

int Form::getExecGrade(void) const
{
    return _exec_grade;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _sign_grade)
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

const char* Form::NotSignedException::what(void) const throw()
{
    return "Form is not signed";
}

void Form::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > _exec_grade)
        throw Form::GradeTooLowException();
    if (this->getSigned() == false)
        throw Form::NotSignedException();
    this->action();
}

std::ostream& operator<<(std::ostream& out, const Form& rhs)
{
    out << "Form details:" << std::endl;
    out << "  Name: " << rhs.getName() << std::endl;
    out << "  Target: " << rhs.getTarget() << std::endl;
    out << "  Signed: " << (rhs.getSigned() ? "Yes" : "No") << std::endl;
    out << "  Sign grade: " << rhs.getSignGrade() << std::endl;
    out << "  Execution grade: " << rhs.getExecGrade() << std::endl;
    return out;
}
