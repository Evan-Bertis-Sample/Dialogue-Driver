#include <iostream>

#include "dialogue_driver/story.h"
#include "dialogue_driver/fact.h"
#include "dialogue_driver/constant_expression.h"
#include "dialogue_driver/fact_collection.h"
#include "dialogue_driver/iobridge.h"
#include "dialogue_driver/entry_node.h"
#include "dialogue_driver/scene.h"

int main()
{
    std::cout << "Hello, world!" << std::endl;
    int x;
    std::cin >> x;
    std::cout << "You input: " << x << std::endl;
}