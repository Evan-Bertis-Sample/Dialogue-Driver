#ifndef CHOICE_COMMAND_H
#define CHOICE_COMMAND_H

#pragma once

#include <iostream>

#include "i_conversation_command.h"
#include "iobridge.h"
#include "query.h"

typedef struct Choice
{
    Query criteria;
    std::string previewText;
} Choice;


class ChoiceCommand : public IConversationCommand
{
public:
    // * Constructors
    ChoiceCommand();
    ChoiceCommand(const ChoiceCommand &other) : _choices(other._choices);

    // * Virtual Functions
    void Execute(ConversationNode &node, Story &story, IOBridge &bridge) override
    {

    }

    // * Methods
    void AddChoice(Query &criteria, std::string &previewText)
    {
        Choice c{criteria, previewText};
        this->_choices.emplace(c);
    }

    void RemoveChoice(int index)
    {
        if (index >= this->_choices.size() || index < 0)
            throw std::out_of_range("Cannot delete choice!");

        this->_choices.erase(this->_choices.begin() + index);
    }

    Choice GetChoice(int index)
    {
        if (index >= this->_choices.size() || index < 0)
            throw std::out_of_range("Cannot remove choice!");
        return this->_choices[index];
    }

    // * Operator
    bool operator == (const ChoiceCommand &other) const
    {
        return this->Content == other.Content;
    }

private:
    std::vector<Choice> _choices;

    std::vector<std::string> _GetPreviewTextVector() const
    {

    }
};

#endif // CHOICE_COMMAND_H