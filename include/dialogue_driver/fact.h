#ifndef FACT_H
#define FACT_H

#include <string>
#include <stdexcept>
#include <iostream>

enum FACT_TYPE {
    INT,
    FLOAT,
    BOOL,
    STRING
};

class Fact
{
private:
    union _factData
    {
        int intData;
        float floatData;
        bool boolData;
        std::string* stringData;

        constexpr _factData(): intData(0) {}
    };

    _factData _data;
    FACT_TYPE _factType;


public:
    //* Constructors
    // Primary constructor
    Fact(FACT_TYPE ftype):
        _factType(ftype) {}

    template<typename T>
    Fact(T data);

    // Default constructor
    Fact():
        _factType(INT) {
            _data.intData = 0;
        }

    // Copy constructor
    Fact(const Fact& other) : _factType(other._factType) {
        switch(_factType) {
            case INT:
                _data.intData = other._data.intData;
                break;
            case FLOAT:
                _data.floatData = other._data.floatData;
                break;
            case BOOL:
                _data.boolData = other._data.boolData;
                break;
            case STRING:
                _data.stringData = new std::string(*other._data.stringData);
                break;
        }
    }

    // * GETTERS/SETTERS
    void SetInt(int data);
    void SetFloat(float data);
    void SetBool(bool data);
    void SetString(std::string data);

    int GetInt() const;
    float GetFloat() const;
    bool GetBool() const;
    std::string GetString() const;

    // Verifies the type
    bool VerifyType(FACT_TYPE fType) const;

    // Gets the FACT_TYPE of a variable
    // Returns -1 if the type is not supported
    template<typename T>
    static FACT_TYPE GetFactType(T value);

    //* Deconstructors
    ~Fact() {
        if(this->_factType == STRING) {
            delete this->_data.stringData;
        }
    }

};

#endif // FACT_H