/* scene.cpp */

#include <vector>

#include "dialogue_driver/scene.h"
#include "dialogue_driver/story_entity.h"

void Scene::AddAvailableActor(StoryEntity actor)
{
    auto it = std::find(this->_availableActors.begin(), this->_availableActors.end(), actor);
    if (it != this->_availableActors.end()) return;

    this->_availableActors.push_back(actor);
}

void Scene::RemoveActor(StoryEntity actor)
{
    auto it = std::find(this->_availableActors.begin(), this->_availableActors.end(), actor);
    if (it == this->_availableActors.end()) return;

    this->_availableActors.erase(it);
}

bool Scene::IsAvailable(StoryEntity actor) const
{
    auto it = std::find(this->_availableActors.begin(), this->_availableActors.end(), actor);
    return it != this->_availableActors.end();
}