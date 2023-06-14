#include <iostream>
#include <stdexcept> // std::out_of_range
#include <numeric>   // std::gcd

#include "fraction.h"


Fraction::Fraction() : numerator_(0), denominator_(1) {}
Fraction::Fraction(int newNumerator) : numerator_(newNumerator), denominator_(1) {}
Fraction::Fraction(int newNumerator, int newDenominator) :
        numerator_(newNumerator), denominator_(newDenominator) {
    if (newDenominator == 0)
        throw std::invalid_argument("Denominator cannot be 0");
}

int Fraction::denominator() const {
    return denominator_;
};
int Fraction::numerator() const {
    return numerator_;
};
void Fraction::setDenominator(int den){
    if (den == 0)
        throw std::invalid_argument("Denominator cannot be 0");
    denominator_=den;
};
void Fraction::setNumerator(int num) {
    numerator_=num;
};
// operator +
Fraction Fraction::operator+(const Fraction &other) const {
    int new_numerator = numerator_ * other.denominator() + other.numerator() * denominator_;
    int new_denominator = denominator_ * other.denominator();
    if (new_denominator == 0)
        throw std::invalid_argument("Denominator cannot be 0");
    Fraction new_fraction = simplifyFraction(Fraction(new_numerator, new_denominator));
    return new_fraction;
}

// operator *
Fraction Fraction::operator*(const Fraction &other) const {
    int new_numerator = numerator_ * other.numerator();
    int new_denominator = denominator_ * other.denominator();
    if (new_denominator == 0)
        throw std::invalid_argument("Denominator cannot be 0");
    Fraction new_fraction = simplifyFraction(Fraction(new_numerator, new_denominator));
    return new_fraction;
}

// simplify fraction
Fraction Fraction::simplifyFraction(Fraction fraction) {
    int numerator = fraction.numerator();
    int denominator = fraction.denominator();
    int divisor = std::gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    if (denominator == 0)
        throw std::invalid_argument("Denominator cannot be 0");
    return {numerator, denominator};
}
