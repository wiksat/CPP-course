#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "fraction.h"

#ifdef UNIMPLEMENTED_classFraction
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
#endif // UNIMPLEMENTED_classFraction

int Fraction::removedFractions_ = 0;

Fraction::Fraction(int newNumerator, int newDenominator, std::string newName) :
        numerator_(newNumerator), denominator_(newDenominator), fractionName_(std::move(newName)) {
}

void Fraction::setNumerator(int newNumerator) {
    numerator_ = newNumerator;
}

void Fraction::setDenominator(int newDenominator) {
    denominator_ = newDenominator;
}

int Fraction::getNumerator() const {
    return numerator_;
}

int Fraction::getDenominator() const {
    return denominator_;
}

void Fraction::print() const {
    cout << numerator_ << "/" << denominator_ << "\n";
}

int Fraction::removedFractions() {
    return removedFractions_;
}

Fraction::~Fraction() {
    removedFractions_++;
}

void Fraction::save(ostream &os) const{
    os << numerator_ << "/" << denominator_;
}

void Fraction::load(istream &is) {
    string fraction;
    getline(is, fraction);
    int i = fraction.find('/');
    numerator_ = stoi(fraction.substr(0, i));
    denominator_ = stoi(fraction.substr(i + 1, fraction.length()));
}
string Fraction::getFractionName() const {
    return fractionName_;
}

int Fraction::getInvalidDenominatorValue() {
    return invalidDenominatorValue;
}


