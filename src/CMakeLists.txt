# stationaryorbit.core:/src/CMakeLists.txt
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

add_library(stationaryorbit.core SHARED
    ${Include_Dir}/stationaryorbit/core.bitoperation.hpp
    ${Include_Dir}/stationaryorbit/core.datastructure.hpp
    ${Include_Dir}/stationaryorbit/core.exception.hpp
    ${Include_Dir}/stationaryorbit/core.iteration.hpp
    ${Include_Dir}/stationaryorbit/core.numeral.hpp
    ${Include_Dir}/stationaryorbit/core.traits.hpp
    ${Include_Dir}/stationaryorbit/core.utilities.hpp
    algorithms.cpp
    arithmetic.cpp
    bitmask.cpp
    bitsequencetraits.cpp
    bitwidth.cpp
    endians.cpp
    fixedpoint.cpp
    integer.cpp
    machinprogression.cpp
    multiplelong.cpp
    numericaltraits.cpp
    point2d.cpp
    proportion.cpp
    rect2dsize.cpp
    rectangle2d.cpp
    rotation.cpp
    stditeratortraits.cpp
    traits.cpp
    valuetypetraits.cpp
)
