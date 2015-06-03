list(APPEND JJ_INCLUDE_DIRS
  ${SDL2_INCLUDE_DIR}
)
add_executable(Tester "test.cpp")
target_include_directories(Tester PUBLIC ${JJ_INCLUDE_DIRS})
target_link_libraries(Tester ${SDL2_LIBRARY})

