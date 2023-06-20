#ifndef CONVERSATION_H
#define CONVERSATION_H
#pragma once


#include <map>
#include <string>
#include <functional>
#include <vector>
#include <memory>

#include "story.h"
#include "conversation_node.h"
#include "story_entity.h"
#include "scene.h"
#include "iobridge.h"

class Conversation
{
public:
    // Something
    void AddEntry(std::shared_ptr<ConversationNode> entry);

    void Converse(StoryEntity &actor, Scene &scene, IOBridge &bridge);
private:
    std::map<StoryEntity, std::vector<std::shared_ptr<ConversationNode>>> _entriesByEntity;
};

#endif // CONVERSATION_H