#ifndef SCENE_H
#define SCENE_H

#pragma once

#include <map>
#include <string>
#include <functional>
#include <vector>
#include <memory>

#include "story.h"
#include "story_entity.h"

class Scene
{
public:
    void AddAvailableActor(StoryEntity actor);
    void RemoveActor(StoryEntity actor);

    bool IsAvailable(StoryEntity actor);
private:
    std::vector<StoryEntity> _availableActors;
};

#endif // SCENE_H