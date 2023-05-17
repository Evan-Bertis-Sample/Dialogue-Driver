/* Fact.cpp */

#include <string>
#include <stdexcept>
#include <type_traits>

#include "dialogue_driver/fact.h"

bool Fact::VerifyType(FACT_TYPE ftype) const {
    if(this->_factType != ftype) {
        throw std::logic_error("Fact type does not match the expected type");
    }

    return true;
}

template<typename T>
FACT_TYPE Fact::GetFactType(T value) {
    if(std::is_same<T, int>::value) return INT;
    else if (std::is_same<T, float>::value) return FLOAT;
    else if (std::is_same<T, bool>::value) return BOOL;
    else if (std::is_same<T, std::string>::value) return STRING;
    else return -1;
}

void Fact::SetInt(int data) {
    if(this->VerifyType(INT)) {
        this->_data.intData = data;
    }
}

void Fact::SetFloat(float data) {
    if(this->VerifyType(INT)) {
        this->_data.floatData= data;
    }
}

void Fact::SetBool(bool data) {
    if(this->VerifyType(INT)) {
        this->_data.boolData = data;
    }
}
void Fact::SetString(std::string data) {
    if(this->VerifyType(INT)) {
        this->_data.stringData = &data;
    }
}

int Fact::GetInt() const {
    this->VerifyType(INT);
    return this->_data.intData;
}

float Fact::GetFloat() const {
    this->VerifyType(INT);
    return this->_data.floatData;
}

bool Fact::GetBool() const {
    this->VerifyType(INT);
    return this->_data.boolData;
}

std::string Fact::GetString() const {
    this->VerifyType(INT);
    return *(this->_data.stringData);
}