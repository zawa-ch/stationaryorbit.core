# stationaryorbit.core:/cmake/Findstationaryorbit.core.cmake
# Copyright 2021 zawa-ch.
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

# インクルードディレクトリの探索
find_path(stationaryorbit_core_INCLUDE_DIR stationaryorbit/core
    PATHS
        ENV stationaryorbit.core_ROOT
        ENV stationaryorbit.core_INCLUDE_DIR
        ${stationaryorbit.core_ROOT}
    PATH_SUFFIXES
        include/
    NO_PACKAGE_ROOT_PATH
)
set(stationaryorbit.core_INCLUDE_DIRS ${stationaryorbit_core_INCLUDE_DIR})
unset(stationaryorbit_core_INCLUDE_DIR)
message("include dir: ${stationaryorbit.core_INCLUDE_DIRS}")
mark_as_advanced(stationaryorbit.core_INCLUDE_DIRS)

list(APPEND stationaryorbit.core_NAMES stationaryorbit.core libstationaryorbit.core)

# ライブラリパスの探索
find_library(stationaryorbit_core_LIBRARY
    NAMES
        stationaryorbit.core
        libstationaryorbit.core
    NAMES_PER_DIR
    PATHS
        ENV stationaryorbit.core_ROOT
        ENV stationaryorbit.core_LIB_DIR
        ${stationaryorbit.core_ROOT}
    PATH_SUFFIXES
        lib/
        build/src/
    NO_PACKAGE_ROOT_PATH
)
set(stationaryorbit.core_LIBRARIES ${stationaryorbit_core_LIBRARY})
unset(stationaryorbit_core_LIBRARY)
message("library dir: ${stationaryorbit.core_LIBRARIES}")
mark_as_advanced(stationaryorbit.core_LIBRARIES)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(stationaryorbit.core
    REQIRED_VARS
        stationaryorbit.core_LIBRARIES
        stationaryorbit.core_INCLUDE_DIRS
)

if(stationaryorbit.core_FOUND AND NOT TARGET stationaryorbit.core::stationaryorbit.core)
    add_library(stationaryorbit.core::stationaryorbit.core UNKNOWN IMPORTED)
    set_target_properties(stationaryorbit.core::stationaryorbit.core
        PROPERTIES
            IMPORTED_LINK_INTERFACE_LANGUAGES "CXX"
            IMPORTED_LOCATION "${stationaryorbit.core_LIBRARIES}"
            INTERFACE_INCLUDE_DIRECTORIES "${stationaryorbit.core_INCLUDE_DIRS}"
    )
endif()
