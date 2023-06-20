#ifndef OUTPUT_COMMAND_H
#define OUTPUT_COMMAND_H

#pragma once

#include <iostream>

#include "i_conversation_command.h"
#include "iobridge.h"

class OutputCommand : public IConversationCommand
{
public:
    std::string Content;

    // * Constructors
    OutputCommand() : Content(std::string("")) {}
    OutputCommand(std::string content) : Content(content) {}
    OutputCommand(const OutputCommand &other) : Content(other.Content) {}

    // * Virtual Functions
    void Execute(ConversationNode &node, Story &story, IOBridge &bridge) override
    {
        std::cout << "Executing output command!" << std::endl;
        bridge.DisplayContent(this->Content);
    }
};

#endif // OUTPUT_COMMAND_H