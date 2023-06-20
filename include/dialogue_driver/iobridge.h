#ifndef IOBRIDGE_H
#define IOBRIDGE_H

#pragma once

#include <functional>
#include <memory>

typedef std::function<void(std::string)> OutputHandler;
typedef std::function<int(std::vector<std::string>)> InputHandler;
class IOBridge
{
public:
    IOBridge(OutputHandler outputHandler, InputHandler inputHandler) :
        _outputHandler(outputHandler), _inputHandler(inputHandler) {}

    IOBridge(const IOBridge &other):
        _outputHandler(other._outputHandler), _inputHandler(other._inputHandler) {}

    void DisplayContent(std::string content) const
    {
        this->_outputHandler(content);
    }

    int GetChoice(std::vector<std::string> choices)
    {
        return this->_inputHandler(choices);
    }

private:
    OutputHandler _outputHandler;
    InputHandler _inputHandler;
};

#endif // IOBRIDGE_H