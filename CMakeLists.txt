cmake_minimum_required(VERSION 3.8)
project(fourmiliere)

find_package(Curses REQUIRED)


set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_STANDARD "${CMAKE_C_FLAGS} -Wall -Werror -lncurses -lpanel -lmenu")

set(CMAKE_BUILD_TYPE Debug)

set(AntClasses
        src/Ant/AntHill.cpp src/Ant/AntHill.h
        src/Ant/AbstractAnt.cpp src/Ant/AbstractAnt.h
        src/Ant/AntQueen.cpp src/Ant/AntQueen.h
        src/Ant/AntWarrior.cpp src/Ant/AntWarrior.h
        src/Ant/AntWorker.cpp src/Ant/AntWorker.h
        src/Ant/AntMove.cpp src/Ant/AntMove.h src/Ant/AntFactory.cpp src/Ant/AntFactory.h)

set(GameClasses
        src/Game/GameEngine.cpp src/Game/GameEngine.h)

set(MapClasses
        src/Map/Map.cpp src/Map/Map.h src/Map/Tile.cpp src/Map/Tile.h)

set(ItemClasses
        src/Item/Item.cpp src/Item/Item.h
        src/Item/FoodItem.cpp src/Item/FoodItem.h
        src/Item/WaterItem.cpp src/Item/WaterItem.h)

set(WindowClasses
        src/Window/SimulationWindow.cpp src/Window/SimulationWindow.h
        src/Window/ChoiceWindow.cpp src/Window/ChoiceWindow.h)

set(SOURCE_FILES main.cpp ${AntClasses} ${GameClasses} ${MapClasses} ${ItemClasses} ${WindowClasses})

add_executable(fourmiliere ${SOURCE_FILES})

target_link_libraries(fourmiliere ncurses panel menu)