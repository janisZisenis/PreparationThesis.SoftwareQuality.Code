#include "HierarchyNodeTest.h"

/////////////////////////////////////// PROPERTY CHANGING /////////////////////////////////////////////
TEST_F(HierarchyNodeWithEventSubClasses, WhenNewNameIsSet_ShouldTriggerDataChangedEventToNotifyListeners)
{
	sut->setName("newName");

	EXPECT_THAT(propertyEvent->getLastReceivedObject(), sut);
	EXPECT_THAT(propertyEvent->getLastReceivedArgs()->getPropertyName(), testing::StrEq(HierarchyNodeProperties::name()));
}

///////////////////////////////////// CHILD LISTENING ////////////////////////////////////////
TEST_F(HierarchyNodeWithEventSubClasses, WhenHandlePropertyChanged_ShouldNotifyListenerWithEmptyPropertyName)
{
	sut->handleEvent(make_shared<ObjectDummy>(), make_shared<PropertyChangedEventArgs>("Any Property"));

	EXPECT_THAT(propertyEvent->getLastReceivedObject(), sut);
	EXPECT_THAT(propertyEvent->getLastReceivedArgs()->getPropertyName(), testing::StrEq(""));
}
TEST_F(HierarchyNodeWithEventSubClasses, WhenHandleChildChanged_ShouldNotifyListenerWithEmptyPropertyName)
{
	ChildChangedEventArgsPtr args = make_shared<ChildChangedEventArgs>(ChildEventTypes::Replaced, HierarchyNodeDummy::getNewInstance(), "AnyType ", "Any RoleName");
	sut->handleEvent(make_shared<ObjectDummy>(), args);

	EXPECT_THAT(propertyEvent->getLastReceivedObject(), sut);
	EXPECT_THAT(propertyEvent->getLastReceivedArgs()->getPropertyName(), testing::StrEq(""));
}