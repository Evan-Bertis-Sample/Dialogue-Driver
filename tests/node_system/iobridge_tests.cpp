#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "dialogue_driver/iobridge.h"

// Test output handler that stores messages in a vector
class TestOutputHandler
{
public:
    void operator()(const std::string &message)
    {
        std::cout << "Received message '" << message << "'" << std::endl;
        _messages.push_back(message);
    }

    std::vector<std::string> GetMessages()
    {
        return _messages;
    }

private:
    std::vector<std::string> _messages;
};

// Test input handler that returns the first option every time
class TestInputHandler
{
public:
    int operator()(const std::vector<std::string> &choices)
    {
        return 0;
    }
};

TEST(IOBridge, DisplayContent)
{
    TestOutputHandler outputHandler;
    TestInputHandler inputHandler;
    IOBridge bridge(outputHandler, inputHandler);

    bridge.DisplayContent("Hello, world!");

    auto messages = outputHandler.GetMessages();
    // ASSERT_EQ(messages.size(), 1);
    // EXPECT_EQ(messages[0], "Hello, world!");
}

TEST(IOBridge, GetChoice)
{
    TestOutputHandler outputHandler;
    TestInputHandler inputHandler;
    IOBridge bridge(outputHandler, inputHandler);

    std::vector<std::string> choices = {"Option 1", "Option 2", "Option 3"};
    int choice = bridge.GetChoice(choices);

    EXPECT_EQ(choice, 0);
}
