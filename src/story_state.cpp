/* story_state.cpp */
#include <map>
#include <string>
#include <functional>
#include <stdexcept>
#include <type_traits>

#include "dialogue_driver/fact.h"
#include "dialogue_driver/story_state.h"

bool StoryState::_ContainsFact(std::string factName) const
{
    if (this->_facts.find(factName) == this->_facts.end())
    { // Fact not found
        return false;
    }

    return true;
}