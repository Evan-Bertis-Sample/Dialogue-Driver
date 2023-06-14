/* story_state.cpp */
#include <map>
#include <string>
#include <functional>
#include <stdexcept>
#include <type_traits>

#include "dialogue_driver/fact.h"
#include "dialogue_driver/story_state.h"

Fact StoryState::_FindFact(std::string factName) const {
    if(this->_facts.find(factName) == this->_facts.end()) { // Fact not found
        throw new std::logic_error("Fact does not exist in Story State!");
    }

    return this->_facts.at(factName);
}

template<typename T>
bool StoryState::VerifyFact(std::string factName, std::function<bool(T)>& cmpr) const {
    // Fact f = this->_FindFact(factName);
    // FACT_TYPE type = Fact::GetFactType<T>(T());
    // f.VerifyType(type);
    return true;
}

template<typename T>
void StoryState::UpdateFact(std::string factName, T data) {

}

template<typename T>
T StoryState::GetFact(std::string factname) const {

}