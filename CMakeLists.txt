cmake_minimum_required(VERSION 3.10)

project(unlimited_rpg VERSION "0.0.0" LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU") OR ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))
	# Tell me all about any (useful) compiler warnings. (GCC, Clang)
	add_compile_options(-Wall)
	add_compile_options(-Wextra)
elseif(DEFINED MSVC)
	# on MSVC, min() and max() are preprocessor variables, hence, we have to disable those macros.
	add_definitions(-DNOMINMAX)
endif()

add_library(libunlimitedrpg
	src/command_parser.cpp
	src/factory.cpp
	src/game_data.cpp
	src/game_state.cpp
	src/game_state_manager.cpp
	src/logger.cpp
	src/npc.cpp
	src/room.cpp
	src/screen_print.cpp
	header/actor.hpp
	header/ai_tags.hpp
	header/code_definitions.hpp
	header/command_parser.hpp
	header/command_set.hpp
	header/entity.hpp
	header/factory.hpp
	header/game_data.hpp
	header/game_state.hpp
	header/game_state_main_menu.hpp
	header/game_state_manager.hpp
	header/game_state_play.hpp
	header/logger.hpp
	header/npc.hpp
	header/platform.hpp
	header/player.hpp
	header/room.hpp
	header/screen_print.hpp
	header/utility_functions.hpp
	header/word_list.hpp
)
target_compile_features(libunlimitedrpg PUBLIC cxx_std_17)

add_executable(unlimited_rpg src/main.cpp)
target_compile_features(unlimited_rpg INTERFACE cxx_std_17)
target_link_libraries(unlimited_rpg libunlimitedrpg)
