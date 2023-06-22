#ifndef CHOICE_COMMAND_H
#define CHOICE_COMMAND_H

#pragma once

#include <iostream>
#include <algorithm>

#include "i_conversation_command.h"
#include "iobridge.h"
#include "query.h"
#include "story.h"
#include "conversation_node.h"

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
    ChoiceCommand(std::vector<Choice> choices) : _choices(choices) {};
    ChoiceCommand(const ChoiceCommand &other) : _choices(other._choices) {};

    // * Virtual Functions
    void Execute(ConversationNode &node, Story &story, IOBridge &bridge) override
    {
        int choiceCount = std::min(node.NumNodes(), (int)this->_choices.size());
        std::vector<std::string> choicePreviewText;
        std::vector<int> choiceNodeMapping;

        for (int i = 0; i < choiceCount; i++)
        {
            // Check if this choice should be added
            Query curCriteria = this->_choices[i].criteria;
            if (!story.CheckQuery(curCriteria)) continue; // This is a possible choice to be presented

            choicePreviewText.emplace_back(this->_choices[i].previewText);
            choiceNodeMapping.push_back(i);
        }

        if (choicePreviewText.size() == 0) return; // No suitable choices were found

        // Now prompt the with our choices
        int choice = bridge.GetChoice(choicePreviewText);

        // Validate the input
        if (choice < 0 || choice >= choicePreviewText.size())
            throw std::out_of_range("Invalid Choice! Please ensure that choice index is valid!");

        // Now given the choice of the user, set the priority of the next
        int nextNodeIndex = choiceNodeMapping[choice];
        std::shared_ptr<ConversationNode> nextNode = node.GetNode(nextNodeIndex);
        node.UpdateSuccessorPriority(nextNode, 0xFFFFFFF); // Set the priority very high
    }

    // * Methods
    void AddChoice(Choice &choice)
    {
        this->_choices.emplace_back(choice);
    }

    void AddChoice(Query &criteria, std::string &previewText)
    {
        Choice c{criteria, previewText};
        this->_choices.emplace_back(c);
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
        return false;
    }

private:
    std::vector<Choice> _choices;
};

#endif // CHOICE_COMMAND_H