#include "SubjectTest.h"

TEST_F(SomeObserverAttached, WhenNotify_ShouldUpdatedAttachedObservers){
    this->notify();

    EXPECT_TRUE(first->getWasUpdated());
    EXPECT_TRUE(second->getWasUpdated());
    EXPECT_TRUE(third->getWasUpdated());
}

TEST_F(SomeObserverDetached, WhenNotify_ShouldNotUpdateDetachedObservers){
    this->notify();

    EXPECT_FALSE(first->getWasUpdated());
    EXPECT_TRUE(second->getWasUpdated());
    EXPECT_FALSE(third->getWasUpdated());
}

TEST_F(SomeObserverFreed, WhenNotify_ShouldNotUpdateNotFreedObservers){
    this->notify();

    EXPECT_TRUE(second->getWasUpdated());
}