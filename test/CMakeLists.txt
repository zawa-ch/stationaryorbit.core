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

add_executable(stationaryorbit.core.test.constarray test.constarray.cpp)
target_link_libraries(stationaryorbit.core.test.constarray stationaryorbit.core)
do_test_pattern(stationaryorbit.core.test.constarray 1 ". 1 1 2 3 5 8 13")

add_executable(stationaryorbit.core.test.constprogression test.constprogression.cpp)
target_link_libraries(stationaryorbit.core.test.constprogression stationaryorbit.core)
do_test_pattern(stationaryorbit.core.test.constprogression 1 ". 1 2 3 4 5 6 7 8 9 10")

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

add_executable(stationaryorbit.core.test.integer test.integer.cpp)
target_link_libraries(stationaryorbit.core.test.integer stationaryorbit.core)
do_test_nofail(stationaryorbit.core.test.integer 1)
do_test_nofail(stationaryorbit.core.test.integer 2)
do_test_nofail(stationaryorbit.core.test.integer 3)
do_test_nofail(stationaryorbit.core.test.integer 4)
do_test_nofail(stationaryorbit.core.test.integer 5)
do_test_nofail(stationaryorbit.core.test.integer 6)
do_test_nofail(stationaryorbit.core.test.integer 7)
do_test_nofail(stationaryorbit.core.test.integer 8)
do_test_nofail(stationaryorbit.core.test.integer 9)
do_test_nofail(stationaryorbit.core.test.integer 10)
do_test_nofail(stationaryorbit.core.test.integer 11)
do_test_nofail(stationaryorbit.core.test.integer 12)
do_test_nofail(stationaryorbit.core.test.integer 13)
do_test_nofail(stationaryorbit.core.test.integer 14)
do_test_nofail(stationaryorbit.core.test.integer 15)
do_test_nofail(stationaryorbit.core.test.integer 16)
do_test_nofail(stationaryorbit.core.test.integer 17)
do_test_nofail(stationaryorbit.core.test.integer 18)
do_test_nofail(stationaryorbit.core.test.integer 19)
do_test_nofail(stationaryorbit.core.test.integer 20)
do_test_nofail(stationaryorbit.core.test.integer 21)
do_test_nofail(stationaryorbit.core.test.integer 22)
do_test_nofail(stationaryorbit.core.test.integer 23)

add_executable(stationaryorbit.core.test.iterator test.iterator.cpp)
target_link_libraries(stationaryorbit.core.test.iterator stationaryorbit.core)
do_test_pattern(stationaryorbit.core.test.iterator 1 "1 2 3 4 5")
do_test_pattern(stationaryorbit.core.test.iterator 2 "5 4 3 2 1")
do_test_pattern(stationaryorbit.core.test.iterator 3 "0 1 2 3 4")

add_executable(stationaryorbit.core.test.logic test.logic.cpp)
target_link_libraries(stationaryorbit.core.test.logic stationaryorbit.core)
do_test_pattern(stationaryorbit.core.test.logic 1 "true")
do_test_pattern(stationaryorbit.core.test.logic 2 "false")
do_test_pattern(stationaryorbit.core.test.logic 3 "indefinited")
do_test_pattern(stationaryorbit.core.test.logic 4 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 5 "true")
do_test_pattern(stationaryorbit.core.test.logic 6 "true")
do_test_pattern(stationaryorbit.core.test.logic 7 "true")
do_test_pattern(stationaryorbit.core.test.logic 8 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 9 "true")
do_test_pattern(stationaryorbit.core.test.logic 10 "false")
do_test_pattern(stationaryorbit.core.test.logic 11 "indefinited")
do_test_pattern(stationaryorbit.core.test.logic 12 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 13 "true")
do_test_pattern(stationaryorbit.core.test.logic 14 "indefinited")
do_test_pattern(stationaryorbit.core.test.logic 15 "indefinited")
do_test_pattern(stationaryorbit.core.test.logic 16 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 17 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 18 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 19 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 20 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 21 "true")
do_test_pattern(stationaryorbit.core.test.logic 22 "false")
do_test_pattern(stationaryorbit.core.test.logic 23 "indefinited")
do_test_pattern(stationaryorbit.core.test.logic 24 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 25 "false")
do_test_pattern(stationaryorbit.core.test.logic 26 "false")
do_test_pattern(stationaryorbit.core.test.logic 27 "false")
do_test_pattern(stationaryorbit.core.test.logic 28 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 29 "indefinited")
do_test_pattern(stationaryorbit.core.test.logic 30 "false")
do_test_pattern(stationaryorbit.core.test.logic 31 "indefinited")
do_test_pattern(stationaryorbit.core.test.logic 32 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 33 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 34 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 35 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 36 "undefined")
do_test_pattern(stationaryorbit.core.test.logic 37 "false")
do_test_pattern(stationaryorbit.core.test.logic 38 "true")
do_test_pattern(stationaryorbit.core.test.logic 39 "indefinited")
do_test_pattern(stationaryorbit.core.test.logic 40 "undefined")
do_test_nofail(stationaryorbit.core.test.logic 41)
do_test_nofail(stationaryorbit.core.test.logic 42)
do_test_nofail(stationaryorbit.core.test.logic 43)
do_test_nofail(stationaryorbit.core.test.logic 44)

add_executable(stationaryorbit.core.test.point2d test.point2d.cpp)
target_link_libraries(stationaryorbit.core.test.point2d stationaryorbit.core)
do_test_pattern(stationaryorbit.core.test.point2d 1 "(5, 12)")
do_test_pattern(stationaryorbit.core.test.point2d 2 "(1, -4)")
do_test_nofail(stationaryorbit.core.test.point2d 3)
do_test_pattern(stationaryorbit.core.test.point2d 4 "(-2.8, 3.8)")
do_test_pattern(stationaryorbit.core.test.point2d 5 "(3.4, -0.2)")
do_test_pattern(stationaryorbit.core.test.point2d 6 "(0, 2)")
do_test_pattern(stationaryorbit.core.test.point2d 7 "(0, 1)")
do_test_pattern(stationaryorbit.core.test.point2d 8 "(1, 2)")
do_test_pattern(stationaryorbit.core.test.point2d 9 "(0.3, 0.8)")

add_executable(stationaryorbit.core.test.property test.property.cpp)
target_link_libraries(stationaryorbit.core.test.property stationaryorbit.core)
do_test_pattern(stationaryorbit.core.test.property 1 " . 10")
do_test_pattern(stationaryorbit.core.test.property 2 " . 3")

add_executable(stationaryorbit.core.test.proportion test.proportion.cpp)
target_link_libraries(stationaryorbit.core.test.proportion stationaryorbit.core)
do_test_nofail(stationaryorbit.core.test.proportion 1)
do_test_nofail(stationaryorbit.core.test.proportion 2)
do_test_nofail(stationaryorbit.core.test.proportion 3)
do_test_nofail(stationaryorbit.core.test.proportion 4)
do_test_nofail(stationaryorbit.core.test.proportion 5)
do_test_nofail(stationaryorbit.core.test.proportion 6)
do_test_nofail(stationaryorbit.core.test.proportion 7)
do_test_nofail(stationaryorbit.core.test.proportion 8)
do_test_nofail(stationaryorbit.core.test.proportion 9)
do_test_nofail(stationaryorbit.core.test.proportion 10)
do_test_nofail(stationaryorbit.core.test.proportion 11)
do_test_nofail(stationaryorbit.core.test.proportion 12)
do_test_nofail(stationaryorbit.core.test.proportion 13)
do_test_nofail(stationaryorbit.core.test.proportion 14)
do_test_nofail(stationaryorbit.core.test.proportion 15)
do_test_nofail(stationaryorbit.core.test.proportion 16)
do_test_nofail(stationaryorbit.core.test.proportion 17)
do_test_nofail(stationaryorbit.core.test.proportion 18)
do_test_nofail(stationaryorbit.core.test.proportion 19)
do_test_nofail(stationaryorbit.core.test.proportion 20)
do_test_nofail(stationaryorbit.core.test.proportion 21)
do_test_nofail(stationaryorbit.core.test.proportion 22)
do_test_nofail(stationaryorbit.core.test.proportion 23)
do_test_nofail(stationaryorbit.core.test.proportion 24)
do_test_nofail(stationaryorbit.core.test.proportion 25)
do_test_pattern(stationaryorbit.core.test.proportion 26 "0.501960784313725")
do_test_pattern(stationaryorbit.core.test.proportion 27 "0.250980392156862")
do_test_nofail(stationaryorbit.core.test.proportion 28)
do_test_nofail(stationaryorbit.core.test.proportion 29)
do_test_nofail(stationaryorbit.core.test.proportion 30)
do_test_nofail(stationaryorbit.core.test.proportion 31)
do_test_nofail(stationaryorbit.core.test.proportion 32)
do_test_nofail(stationaryorbit.core.test.proportion 33)
do_test_pattern(stationaryorbit.core.test.proportion 34 "0.25")
do_test_pattern(stationaryorbit.core.test.proportion 35 "4629771061636907072")
do_test_nofail(stationaryorbit.core.test.proportion 36)
do_test_nofail(stationaryorbit.core.test.proportion 37)

add_executable(stationaryorbit.core.test.range test.range.cpp)
target_link_libraries(stationaryorbit.core.test.range stationaryorbit.core)
do_test_nofail(stationaryorbit.core.test.range 1)
do_test_nofail(stationaryorbit.core.test.range 2)
do_test_nofail(stationaryorbit.core.test.range 3)
do_test_nofail(stationaryorbit.core.test.range 4)
do_test_nofail(stationaryorbit.core.test.range 5)
do_test_pattern(stationaryorbit.core.test.range 6 "0 1 2 3 4 5 6 7 8 9")
do_test_pattern(stationaryorbit.core.test.range 7 "11 10 9 8 7 6 5")
do_test_nofail(stationaryorbit.core.test.range 8)

add_executable(stationaryorbit.core.test.rectangle2d test.rectangle2d.cpp)
target_link_libraries(stationaryorbit.core.test.rectangle2d stationaryorbit.core)
do_test_pattern(stationaryorbit.core.test.rectangle2d 1 "r1\.left . 0")
do_test_pattern(stationaryorbit.core.test.rectangle2d 2 "r1\.right . 3")
do_test_pattern(stationaryorbit.core.test.rectangle2d 3 "r1\.top . 4")
do_test_pattern(stationaryorbit.core.test.rectangle2d 4 "r1\.bottom . 0")
do_test_nofail(stationaryorbit.core.test.rectangle2d 5)
do_test_pattern(stationaryorbit.core.test.rectangle2d 6 "r2\.left . -3")
do_test_pattern(stationaryorbit.core.test.rectangle2d 7 "r2\.right . 0")
do_test_pattern(stationaryorbit.core.test.rectangle2d 8 "r2\.top . 10")
do_test_pattern(stationaryorbit.core.test.rectangle2d 9 "r2\.bottom . 6")

add_executable(stationaryorbit.core.test.zerovalue test.zerovalue.cpp)
target_link_libraries(stationaryorbit.core.test.zerovalue stationaryorbit.core)
do_test_nofail(stationaryorbit.core.test.zerovalue 1)
do_test_nofail(stationaryorbit.core.test.zerovalue 2)
do_test_nofail(stationaryorbit.core.test.zerovalue 3)
do_test_nofail(stationaryorbit.core.test.zerovalue 4)
do_test_nofail(stationaryorbit.core.test.zerovalue 5)
do_test_nofail(stationaryorbit.core.test.zerovalue 6)
do_test_nofail(stationaryorbit.core.test.zerovalue 7)
do_test_nofail(stationaryorbit.core.test.zerovalue 8)
do_test_pattern(stationaryorbit.core.test.zerovalue 9 "5")

add_executable(stationaryorbit.core.test
    numeral.cpp
    test-general.cpp
)
target_link_libraries(stationaryorbit.core.test stationaryorbit.core)
