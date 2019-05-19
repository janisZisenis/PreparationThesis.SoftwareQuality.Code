cmake_minimum_required(VERSION 2.8)

#############################################################
###		SHARED OR STATIC LIBRARIES						  ###
#############################################################


set(BUILD_SHARED_LIBS ON CACHE BOOL "Build shared libraries")
if(${BUILD_SHARED_LIBS})
	set(LIB_TYPE SHARED)
else()
	set(LIB_TYPE STATIC)
	
set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )
foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()

endif()

add_subdirectory(src)


