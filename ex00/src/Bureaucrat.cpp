/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:37:05 by jpceia            #+#    #+#             */
/*   Updated: 2021/12/20 19:48:56 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>


Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name), _grade(grade)
{
    #ifdef DEBUG
    std::cout << "Bureaucrat standard constructor called" << std::endl;
    #endif
    checkGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs)
    : _name(rhs._name), _grade(rhs._grade)
{
    #ifdef DEBUG
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    #endif
}

Bureaucrat::~Bureaucrat()
{
    #ifdef DEBUG
    std::cout << "Bureaucrat destructor called" << std::endl;
    #endif
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
    {
        const_cast<std::string&>(_name) = rhs._name;
        _grade = rhs._grade;
    }
    return *this;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::checkGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::incrementGrade(void)
{
    int new_grade = _grade - 1;
    checkGrade(new_grade);
    _grade = new_grade;
}

void Bureaucrat::decrementGrade(void)
{
    int new_grade = _grade + 1;
    
    checkGrade(new_grade);
    _grade = new_grade;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return out;
}
