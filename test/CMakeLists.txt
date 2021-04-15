# stationaryorbit.core:/test/CMakeLists.txt
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

add_executable(stationaryorbit.core.test.bitmask test.bitmask.cpp)
target_link_libraries(stationaryorbit.core.test.bitmask stationaryorbit.core)
add_test(NAME stationaryorbit.core.test.bitmask COMMAND stationaryorbit.core.test.bitmask)
set_tests_properties(stationaryorbit.core.test.bitmask
    PROPERTIES
        FAIL_REGULAR_EXPRESSION ".*NG"
)

add_executable(stationaryorbit.core.test.endian test.endian.cpp)
target_link_libraries(stationaryorbit.core.test.endian stationaryorbit.core)
add_test(NAME stationaryorbit.core.test.endian COMMAND stationaryorbit.core.test.endian)
set_tests_properties(stationaryorbit.core.test.endian
    PROPERTIES
        FAIL_REGULAR_EXPRESSION ".*NG"
)

add_executable(stationaryorbit.core.test
    delegate.cpp
    iteration.cpp
    numeral.cpp
    property.cpp
    test-general.cpp
    utilities.cpp
)
target_link_libraries(stationaryorbit.core.test stationaryorbit.core)
