/* Fact.cpp */

#include <iostream>
#include <string>
#include <stdexcept>
#include <type_traits>
#include <variant>

#include "dialogue_driver/fact.h"

// template<typename T>
// bool Fact::_VerifyType() const {
//     if (this->_isValid) return false;

//     if (std::holds_alternative<T>(this->_data))
//         return true;
//     else std::cout << "Invalid type!" << std::endl;
// }