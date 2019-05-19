macro(addGMockLinkDirectory)
	link_directories(${CMAKE_SOURCE_DIR}/lib/gmock/${PLATFORM}/Debug)
endmacro(addGMockLinkDirectory)

macro(linkGMock TARGET_NAME)
	include_directories(${CMAKE_SOURCE_DIR}/src/3rdParty/gmock-1.7.0/src/googlemock/include)
	include_directories(${CMAKE_SOURCE_DIR}/src/3rdParty/gmock-1.7.0/src/googletest/include)
	target_link_libraries(${TARGET_NAME} gmock_main gmock)
endmacro(linkGMock)
