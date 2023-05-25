#ifndef STORY_STATE_H
#define STORY_STATE_H


#pragma once

#include <map>
#include <string>
#include <functional>

#include "fact.h"

/// @brief Stores the state of a "story"
class StoryState {
private:
    std::map<std::string, Fact> _facts;

    Fact _FindFact(std::string factName) const;
public:
    template<typename T>
    bool VerifyFact(std::string factName, std::function<bool(T)>& cmpr) const;

    template<typename T>
    void UpdateFact(std::string factName, T data);

    template<typename T>
    T GetFact(std::string factname) const;
};

#endif // STORY_STATE