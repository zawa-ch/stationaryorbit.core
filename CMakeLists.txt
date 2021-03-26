# stationaryorbit.core:/CMakeLists.txt
# Copyright 2020-2021 zawa-ch.
# GPLv3 (or later) license
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# any later version.
#
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.
# If not, see <http://www.gnu.org/licenses/>.
#
cmake_minimum_required(VERSION 3.16)
project(stationaryorbit.core
    VERSION 0.1.0
    LANGUAGES CXX
)
cmake_policy(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(Include_Dir ${PROJECT_SOURCE_DIR}/include)

# stationaryorbit.core のビルドとインストール
add_subdirectory(src)
list(APPEND HEADER_DIRECTORIES
    include/stationaryorbit/core
)
list(APPEND HEADER_FILES
    include/stationaryorbit/core.bitoperation.hpp
    include/stationaryorbit/core.delegate.hpp
    include/stationaryorbit/core.event.hpp
    include/stationaryorbit/core.exception.hpp
    include/stationaryorbit/core.iteration.hpp
    include/stationaryorbit/core.numeral.hpp
    include/stationaryorbit/core.property.hpp
    include/stationaryorbit/core.traits.hpp
    include/stationaryorbit/core.utilities.hpp
)
target_include_directories(stationaryorbit.core
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    PRIVATE "${PROJECT_BINARY_DIR}/src"
)
set_target_properties(stationaryorbit.core PROPERTIES INTERFACE_INCLUDE_DIRECTORIES $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
install(TARGETS stationaryorbit.core
    EXPORT stationaryorbit.core.export
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include
)
install(FILES ${HEADER_FILES} DESTINATION include/stationaryorbit)
install(DIRECTORY ${HEADER_DIRECTORIES} DESTINATION include/stationaryorbit)
install(EXPORT stationaryorbit.core.export FILE stationaryorbit.core-config.cmake DESTINATION share/cmake/stationaryorbit.core/ EXPORT_LINK_INTERFACE_LIBRARIES)

add_subdirectory(test)
target_link_libraries(stationaryorbit.core.test
    stationaryorbit.core
)
