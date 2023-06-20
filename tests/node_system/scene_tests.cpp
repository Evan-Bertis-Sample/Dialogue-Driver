#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "dialogue_driver/scene.h"
#include "dialogue_driver/story_entity.h"


TEST(SceneTest, AddAndCheckAvailableActor)
{
    Scene scene;
    StoryEntity actor("John");
    
    scene.AddAvailableActor(actor);

    EXPECT_TRUE(scene.IsAvailable(actor));
}

TEST(SceneTest, CheckUnavailableActor)
{
    Scene scene;
    StoryEntity actor("John");
    StoryEntity notAddedActor("Jane");

    scene.AddAvailableActor(actor);

    EXPECT_FALSE(scene.IsAvailable(notAddedActor));
}

TEST(SceneTest, RemoveActor)
{
    Scene scene;
    StoryEntity actor("John");

    scene.AddAvailableActor(actor);
    EXPECT_TRUE(scene.IsAvailable(actor));

    scene.RemoveActor(actor);
    EXPECT_FALSE(scene.IsAvailable(actor));
}

TEST(SceneTest, RemoveActorNotAdded)
{
    Scene scene;
    StoryEntity actor("John");

    EXPECT_NO_THROW(scene.RemoveActor(actor));
}
