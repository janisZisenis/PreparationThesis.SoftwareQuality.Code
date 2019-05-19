#include "ObjectTest.h"

TEST_F(SomeLoggerAdded, WhenLog_ShouldTriggerLoggerToLogMessage){
    this->log(expectedMessage);
    EXPECT_THAT(first->getReceivedMessage(), expectedMessage);
    EXPECT_THAT(second->getReceivedMessage(), expectedMessage);
    EXPECT_THAT(third->getReceivedMessage(), expectedMessage);
    EXPECT_THAT(fourth->getReceivedMessage(), expectedMessage);
}

TEST_F(SomeAddedLoggerRemoved, WhenLog_ShouldTriggerLoggerToLogMessage){
    this->log(expectedMessage);
    EXPECT_THAT(first->getReceivedMessage(), expectedMessage);
    EXPECT_THAT(second->getReceivedMessage(), "");
    EXPECT_THAT(third->getReceivedMessage(), "");
    EXPECT_THAT(fourth->getReceivedMessage(), expectedMessage);
}