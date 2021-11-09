cmake_minimum_required(VERSION 3.0.0)
project(ukulele VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ukulele src/main.cpp )

target_link_libraries(ukulele -lallegro -lallegro_font -lallegro_image -lallegro_primitives -lallegro_audio -lallegro_acodec)
add_custom_command(TARGET ukulele PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/src/ $<TARGET_FILE_DIR:ukulele>)
