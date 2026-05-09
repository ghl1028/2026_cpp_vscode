cmake_minimum_required(VERSION 3.28)
project(cpp23_labs CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# MinGW (GCC): std::print / std::println requires libstdc++exp
if(MINGW)
    link_libraries(stdc++exp)
endif()

file(GLOB LAB_DIRS CONFIGURE_DEPENDS RELATIVE "${CMAKE_SOURCE_DIR}/labs" "labs/q*")
foreach(dir IN LISTS LAB_DIRS)
    if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/labs/${dir}"
       AND EXISTS "${CMAKE_SOURCE_DIR}/labs/${dir}/CMakeLists.txt")
        add_subdirectory("labs/${dir}")
    endif()
endforeach()

# project* 폴더 자동 감지 추가
file(GLOB PROJECT_DIRS CONFIGURE_DEPENDS RELATIVE "${CMAKE_SOURCE_DIR}" "project*")
foreach(dir IN LISTS PROJECT_DIRS)
    if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${dir}"
       AND EXISTS "${CMAKE_SOURCE_DIR}/${dir}/CMakeLists.txt")
        add_subdirectory("${dir}")
    endif()
endforeach()
