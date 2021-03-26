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

add_executable(stationaryorbit.core.test
    bitoperation.cpp
    delegate.cpp
    iteration.cpp
    numeral.cpp
    property.cpp
    test-general.cpp
    utilities.cpp
)
target_link_libraries(stationaryorbit.core.test
    ${DEP_LIBS}
    stationaryorbit.core
)
