// author: Grzegorz Prowadzacy

#include <algorithm>
#include <stdexcept>
#include <utility> // std::swap()
#include <cstring>
#include "vector.h"

//constructors

Vector::Vector(size_t capacity):
        data_(new Fraction[capacity]), size_(0), capacity_(capacity) {
}

Vector::Vector() : data_(nullptr), size_(0), capacity_(0) {}

Vector::Vector(const Vector &other)
        : data_(other.data_), size_(other.size_), capacity_(other.capacity_)
{
    if (other.data_.use_count() > 1) {
        if (size_ > capacity_) {
            capacity_ = size_;
            data_.reset(new Fraction[size_]);
        }
        std::memcpy(data_.get(), other.data_.get(), size_ * sizeof(Fraction));
    }
}
Vector::Vector(Vector&& other) noexcept
        : data_(std::move(other.data_)), size_(other.size_), capacity_(other.capacity_)
{
    other.size_ = 0;
    other.capacity_ = 0;
}
//getters
size_t Vector::size() const {
    return size_;
}

size_t Vector::capacity() const {
    return capacity_;
}

const std::shared_ptr<Fraction[]> &Vector::data() const {
    return data_;
}
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = std::shared_ptr<Fraction[]>(new Fraction[capacity_]);
        std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = std::move(other.data_);
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}


void Vector::push_back(const Fraction &fraction) {
    if (size_ == capacity_) {
        std::shared_ptr<Fraction[]> new_data(new Fraction[size_ + 1]);
        std::copy(data_.get(), data_.get() + size_, new_data.get());
        data_ = new_data;
        capacity_ = size_ + 1;
    }
    data_[size_] = fraction;
    size_++;
}
// operator[]
Fraction &Vector::operator[](size_t index) const {
    if (size_ <= index)
        throw std::out_of_range("Element out of range");
    return data_[index];
}

Fraction &Vector::operator[](size_t index) {
    if (size_ <= index)
        throw std::out_of_range("Element out of range");
    return data_[index];;
}