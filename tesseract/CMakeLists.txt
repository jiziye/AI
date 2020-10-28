cmake_minimum_required(VERSION 3.10)
project(tesseract)

#demo1
include_directories(/usr/include/leptonica  /usr/include/tesseract)
add_executable(tesseract_demo1 main.cpp)
target_link_libraries(tesseract_demo1  tesseract lept)

#demo2
# find_package(Leptonica REQUIRED)
# include_directories(${Leptonica_INCLUDE_DIRS})

# find_package(Tesseract REQUIRED)
# include_directories($(Tesseract_INCLUDE_DIRS))
# add_executable(tesseract_demo1 main.cpp)
# target_link_libraries(tesseract_demo1 ${Leptonica_LIBRARIES})

# target_link_libraries(tesseract_demo1 ${Tesseract_LIBRARIES})

