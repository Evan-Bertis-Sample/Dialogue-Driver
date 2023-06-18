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
    void AddAvailableActor(std::shared_ptr<StoryEntity> actor);
    void RemoveActor(std::shared_ptr<StoryEntity> actor);

    bool IsAvailable(std::shared_ptr<StoryEntity> actor);
private:
    std::vector<std::shared_ptr<StoryEntity>> _availableActors;
}

#endif // SCENE_H