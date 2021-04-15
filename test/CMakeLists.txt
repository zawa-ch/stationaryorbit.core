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

function(do_test target index)
    add_test(NAME ${target}.${index} COMMAND ${target} ${index})
    set_tests_properties(${target}.${index}
    PROPERTIES
        PASS_REGULAR_EXPRESSION ".*OK"
        FAIL_REGULAR_EXPRESSION ".*NG"
        SKIP_RETURN_CODE 255
)
endfunction(do_test)

add_executable(stationaryorbit.core.test.bitmask test.bitmask.cpp)
target_link_libraries(stationaryorbit.core.test.bitmask stationaryorbit.core)
do_test(stationaryorbit.core.test.bitmask 1)
do_test(stationaryorbit.core.test.bitmask 2)
do_test(stationaryorbit.core.test.bitmask 3)
do_test(stationaryorbit.core.test.bitmask 4)

add_executable(stationaryorbit.core.test.endian test.endian.cpp)
target_link_libraries(stationaryorbit.core.test.endian stationaryorbit.core)
do_test(stationaryorbit.core.test.endian 1)
do_test(stationaryorbit.core.test.endian 2)
do_test(stationaryorbit.core.test.endian 3)
do_test(stationaryorbit.core.test.endian 4)
do_test(stationaryorbit.core.test.endian 5)

add_executable(stationaryorbit.core.test.delegate test.delegate.cpp)
target_link_libraries(stationaryorbit.core.test.delegate stationaryorbit.core)
do_test(stationaryorbit.core.test.delegate 1)

add_executable(stationaryorbit.core.test
    iteration.cpp
    numeral.cpp
    property.cpp
    test-general.cpp
    utilities.cpp
)
target_link_libraries(stationaryorbit.core.test stationaryorbit.core)
