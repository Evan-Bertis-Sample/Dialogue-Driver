#ifndef FACT_H
#define FACT_H

#pragma once

#include <string>
#include <stdexcept>
#include <iostream>
#include <typeinfo>
#include <variant>
#include <functional>

class Fact
{
private:
    typedef std::variant<int, float, bool, std::string> _FactData;

    _FactData _data;
    bool _isValid;

    // Verifies the type
    template <typename T>
    bool _VerifyType() const
    {
        if (!this->_isValid)
            return false;

        if (std::holds_alternative<T>(this->_data))
            return true;

        else
            return false;
    }

    template <typename T>
    bool _Compare(const T &other, std::function<bool(const T, const T)> &compareFunc) const
    {
        std::cout << "Comparing types " << typeid(T).name() << std::endl;
        if (this->_VerifyType<T>())
        {
            T data = this->Get<T>();
            std::cout << "Comparing " << data << " to " << other << std::endl;
            return compareFunc(data, other);
        }

        std::cout << "Mismatching type / Invalid Fact!" << std::endl;
        return false;
    }

public:
    // * Constructors
    // Primary constructor
    Fact() : _data(0), _isValid(false) {}

    // Initialize a Fact with a given peice of data
    template <typename T>
    Fact(T data)
    {
        try
        {
            this->_data = data;
            this->_isValid = true;
            std::cout << "Created valid fact!" << std::endl;
        }
        catch (const std::bad_variant_access &ex)
        {
            std::cout << ex.what() << '\n';
            this->_isValid = false;
        }
    }

    // Copy constructor
    Fact(const Fact &other)
    {
        try
        {
            this->_data = other._data;
        }
        catch (const std::bad_variant_access &ex)
        {
            std::cout << ex.what() << '\n';
        }

        this->_isValid = other._isValid;
    }

    // * Methods
    template <typename T>
    void Set(T data)
    {
        this->_VerifyType<T>();

        try
        {
            this->_data = data;
        }
        catch (const std::bad_variant_access &ex)
        {
            std::cout << ex.what() << '\n';
        }
    }

    template <typename T>
    T Get() const
    {
        if (this->_isValid == false)
        {
            throw new std::logic_error("Cannot Get from NULL fact!");
        }

        try
        {
            return std::get<T>(this->_data);
        }
        catch (const std::bad_variant_access &ex)
        {
            std::cout << ex.what() << '\n';
            return T();
        }
    }

    // * Fact Comparison Operators
    bool operator ==(const Fact &other) const
    {
        std::cout << "Comparing two facts..." << std::endl;
        if (this->_data.index() == other._data.index()) return this->_data == other._data;

        // Additional logic for float and integer comparisons
        if (std::holds_alternative<int>(this->_data) && std::holds_alternative<float>(other._data)) 
            return *this == other.Get<float>();

        if (std::holds_alternative<float>(this->_data) && std::holds_alternative<int>(other._data))
            return *this == other.Get<int>();

        return false;

    }

    // * Generic Comparison Operators
    template <typename T>
    bool operator==(const T &other) const
    {
        std::function<bool(const T, const T)> func = [](const T left, const T right)
        {
            return left == right;
        };
        return this->_Compare(other, func);
    }

    template <typename T>
    bool operator!=(const T &other) const
    {
        std::function<bool(const T, const T)> func = [](const T left, const T right)
        {
            return left != right;
        };
        return this->_Compare(other, func);
    }

    template <typename T>
    bool operator<(const T &other) const
    {
        std::function<bool(const T, const T)> func = [](const T left, const T right)
        {
            return left < right;
        };
        return this->_Compare(other, func);
    }

    template <typename T>
    bool operator>(const T &other) const
    {
        std::function<bool(const T, const T)> func = [](const T left, const T right)
        {
            return left > right;
        };
        return this->_Compare(other, func);
    }

    template <typename T>
    bool operator<=(const T &other) const
    {
        std::function<bool(const T, const T)> func = [](const T left, const T right)
        {
            return left <= right;
        };
        return this->_Compare(other, func);
    }

    template <typename T>
    bool operator>=(const T &other) const
    {
        std::function<bool(const T, const T)> func = [](const T left, const T right)
        {
            return left >= right;
        };
        return this->_Compare(other, func);
    }

    // * Deconstructors
    ~Fact()
    {
        // if (std::holds_alternative<std::string*>(this->_data)) {
        //     delete std::get<std::string*>(this->_data);
        // }
    }
};

#endif // FACT_H