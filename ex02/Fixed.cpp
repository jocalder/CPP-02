/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:45:30 by jocalder          #+#    #+#             */
/*   Updated: 2026/01/19 17:47:50 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): value(0) {}

Fixed::Fixed(const Fixed& other)
{
    this->value = other.value;
}
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->value = other.value;
    return (*this);
}

Fixed::~Fixed() {}


Fixed::Fixed(const float floating)
{
    this->value = roundf(floating * (1 << fractionalBits));
}

Fixed::Fixed(const int integer)
{
	this->value = integer << fractionalBits;
}

bool	Fixed::operator>(const Fixed& other) const
{
    if (this->value > other.value)
        return (true);
    return (false);
}

bool	Fixed::operator<(const Fixed& other) const
{
    if (this->value < other.value)
        return (true);
    return (false);
}

bool	Fixed::operator>=(const Fixed& other) const
{
    if (this->value >= other.value)
        return (true);
    return (false);
}

bool	Fixed::operator<=(const Fixed& other) const
{
    if (this->value <= other.value)
        return (true);
    return (false);
}

bool	Fixed::operator==(const Fixed& other) const
{
    if (this->value == other.value)
        return (true);
    return (false);
}

bool	Fixed::operator!=(const Fixed& other) const
{
    if (this->value != other.value)
        return (true);
    return (false);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
    Fixed   result;
    result.value = this->value + other.value;
    return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
    Fixed   result;
    result.value = this->value - other.value;
    return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
    Fixed   result;
    result.value = (this->value * other.value) >> fractionalBits;
    return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
    Fixed   result;
    result.value = (this->value << fractionalBits) / other.value;
    return (result);
}

Fixed&	Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	this->value++;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	this->value--;
	return (temp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

int Fixed::getRawBits() const
{
    return (this->value);
}

void    Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->value / (float)(1 << fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->value >> fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
