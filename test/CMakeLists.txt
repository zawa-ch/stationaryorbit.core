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

function(do_test_nofail target index)
    add_test(NAME ${target}.${index} COMMAND ${target} ${index})
    set_tests_properties(${target}.${index}
    PROPERTIES
        PASS_REGULAR_EXPRESSION "\.\.\.OK"
        FAIL_REGULAR_EXPRESSION "NG"
        SKIP_RETURN_CODE 255
)
endfunction(do_test_nofail)
function(do_test_pattern target index pattern)
    add_test(NAME ${target}.${index} COMMAND ${target} ${index})
    set_tests_properties(${target}.${index}
    PROPERTIES
        PASS_REGULAR_EXPRESSION ${pattern}
        SKIP_RETURN_CODE 255
)
endfunction(do_test_pattern)

add_executable(stationaryorbit.core.test.bitmask test.bitmask.cpp)
target_link_libraries(stationaryorbit.core.test.bitmask stationaryorbit.core)
do_test_nofail(stationaryorbit.core.test.bitmask 1)
do_test_nofail(stationaryorbit.core.test.bitmask 2)
do_test_nofail(stationaryorbit.core.test.bitmask 3)
do_test_nofail(stationaryorbit.core.test.bitmask 4)

add_executable(stationaryorbit.core.test.endian test.endian.cpp)
target_link_libraries(stationaryorbit.core.test.endian stationaryorbit.core)
do_test_nofail(stationaryorbit.core.test.endian 1)
do_test_nofail(stationaryorbit.core.test.endian 2)
do_test_nofail(stationaryorbit.core.test.endian 3)
do_test_nofail(stationaryorbit.core.test.endian 4)
do_test_nofail(stationaryorbit.core.test.endian 5)

add_executable(stationaryorbit.core.test.delegate test.delegate.cpp)
target_link_libraries(stationaryorbit.core.test.delegate stationaryorbit.core)
do_test_nofail(stationaryorbit.core.test.delegate 1)

add_executable(stationaryorbit.core.test.fixedpoint test.fixedpoint.cpp)
target_link_libraries(stationaryorbit.core.test.fixedpoint stationaryorbit.core)
do_test_nofail(stationaryorbit.core.test.fixedpoint 1)
do_test_nofail(stationaryorbit.core.test.fixedpoint 2)
do_test_nofail(stationaryorbit.core.test.fixedpoint 3)
do_test_nofail(stationaryorbit.core.test.fixedpoint 4)
do_test_nofail(stationaryorbit.core.test.fixedpoint 5)
do_test_nofail(stationaryorbit.core.test.fixedpoint 6)
do_test_nofail(stationaryorbit.core.test.fixedpoint 7)
do_test_nofail(stationaryorbit.core.test.fixedpoint 8)
do_test_nofail(stationaryorbit.core.test.fixedpoint 9)
do_test_nofail(stationaryorbit.core.test.fixedpoint 10)
do_test_nofail(stationaryorbit.core.test.fixedpoint 11)
do_test_nofail(stationaryorbit.core.test.fixedpoint 12)
do_test_nofail(stationaryorbit.core.test.fixedpoint 13)
do_test_nofail(stationaryorbit.core.test.fixedpoint 14)
do_test_nofail(stationaryorbit.core.test.fixedpoint 15)
do_test_pattern(stationaryorbit.core.test.fixedpoint 16 "255\.996")
do_test_pattern(stationaryorbit.core.test.fixedpoint 17 "0")
do_test_pattern(stationaryorbit.core.test.fixedpoint 18 "0\.00390625")

add_executable(stationaryorbit.core.test.iterator test.iterator.cpp)
target_link_libraries(stationaryorbit.core.test.iterator stationaryorbit.core)
do_test_pattern(stationaryorbit.core.test.iterator 1 "1 2 3 4 5")
do_test_pattern(stationaryorbit.core.test.iterator 2 "5 4 3 2 1")
do_test_pattern(stationaryorbit.core.test.iterator 3 "0 1 2 3 4")

add_executable(stationaryorbit.core.test
    numeral.cpp
    property.cpp
    test-general.cpp
    utilities.cpp
)
target_link_libraries(stationaryorbit.core.test stationaryorbit.core)
