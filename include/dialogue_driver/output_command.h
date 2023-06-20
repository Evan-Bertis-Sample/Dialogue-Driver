#ifndef OUTPUT_COMMAND_H
#define OUTPUT_COMMAND_H

#pragma once

#include <iostream>

#include "i_conversation_command.h"

class OutputCommand : public IConversationCommand
{
public:
    std::string Content;

    // * Constructors
    OutputCommand() : Content(std::string("")) {}
    OutputCommand(std::string content) : Content(content) {}
    OutputCommand(const OutputCommand &other) : Content(other.Content) {}

    // * Virtual Functions
    void Execute(ConversationNode &node, Story &story) override
    {
        std::cout << "Executing output command!" << std::endl;
    }
};

#endif // OUTPUT_COMMAND_H