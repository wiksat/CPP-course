#include <iostream>
#include <string>
#include <stdexcept> // std::out_of_range()
#include <iomanip>   // std::setw()

using namespace std;

#include "matrix.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

TwoDimensionMatrix::TwoDimensionMatrix() {
    for (auto & i : matrix_) {
        for (int & j : i) {
            j = 0;
        }
    }
}
TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix &matrix2) {
    for (size_t i = 0; i < size_; i++) {
        for (size_t j = 0; j < size_; j++) {
            matrix_[i][j] = matrix2.get(i, j);
        }
    }
}

MatrixElement TwoDimensionMatrix::get(size_t a, size_t b) const{
    return matrix_[a][b];
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement matrix2[size_][size_]) {
    for (size_t i = 0; i < size_; i++) {
        for (size_t j = 0; j < size_; j++) {
            matrix_[i][j] = matrix2[i][j];
        }
    }
}

TwoDimensionMatrix &TwoDimensionMatrix::operator=(TwoDimensionMatrix matrix2) {
    for (size_t i = 0; i < size_; i++) {
        for (size_t j = 0; j < size_; j++) {
            matrix_[i][j] = matrix2.get(i, j);
        }
    }
    return *this;
}

std::istream &operator>>(istream &input, TwoDimensionMatrix &matrix2) {
    for (auto &i: matrix2.matrix_) {
        for (int &j: i) {
            input >> j;
        }
    }
    return input;
}

std::ostream &operator<<(ostream &output, const TwoDimensionMatrix &matrix2) {
    for (size_t i = 0; i < TwoDimensionMatrix::size(); i++) {
        for (size_t j = 0; j < TwoDimensionMatrix::size(); j++) {
            output << matrix2.get(i, j) << " ";
        }
        output << endl;
    }
    return output;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix &matrix2) {
    TwoDimensionMatrix res;
    for (size_t i = 0; i < TwoDimensionMatrix::size(); i++) {
        for (size_t j = 0; j < TwoDimensionMatrix::size(); j++) {
            res.matrix_[i][j] = matrix1.get(i, j) + matrix2.get(i, j);
        }
    }
    return res;
}

TwoDimensionMatrix &TwoDimensionMatrix::operator*=(MatrixElement number) {
    for (auto & i : matrix_) {
        for (int & j : i) {
            j *= number;
        }
    }
    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix &matrix) const {
    TwoDimensionMatrix res;
    for (size_t i = 0; i < TwoDimensionMatrix::size(); i++) {
        for (size_t j = 0; j < TwoDimensionMatrix::size(); j++) {
            res.matrix_[i][j] = get(i,j) && matrix.get(i, j);
        }
    }
    return res;
}

MatrixElement *TwoDimensionMatrix::operator[](size_t i) {
    return matrix_[i];
}

const MatrixElement *TwoDimensionMatrix::operator[](size_t i) const {
    return matrix_[i];
}

