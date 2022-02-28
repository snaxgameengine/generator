cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
cmake_policy(VERSION 3.15)

#if(MSVC)
#	add_definitions(/W3)
#else()
#	add_definitions(-std=c++11 -pedantic -Wall -Wextra)
#endif()

add_definitions(-DGENERATOR_USE_GLM -DGLM_ENABLE_EXPERIMENTAL)
find_package(glm CONFIG REQUIRED)


set(TARGET_NAME ${CMAKE_STATIC_LIBRARY_PREFIX}generator${SUFFIX}${CMAKE_STATIC_LIBRARY_SUFFIX})

add_subdirectory(src)
#add_subdirectory(images)

