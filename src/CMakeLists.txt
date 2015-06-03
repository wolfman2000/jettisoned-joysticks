list(APPEND JJ_INCLUDE_DIRS
  ${SDL2_INCLUDE_DIR}
)
add_executable(Tester "test.cpp")

set_target_properties(Tester PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${JJ_BIN_DIR}"
  RUNTIME_OUTPUT_DIRECTORY_RELEASE "${JJ_BIN_DIR}"
  RUNTIME_OUTPUT_DIRECTORY_DEBUG "${JJ_BIN_DIR}"
  RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${JJ_BIN_DIR}"
  RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${JJ_BIN_DIR}"
  OUTPUT_NAME_DEBUG "Tester-debug"
  OUTPUT_NAME_MINSIZEREL "Tester-min-size"
  OUTPUT_NAME_RELWITHDEBINFO "Tester-rel-deb"
)

target_include_directories(Tester PUBLIC ${JJ_INCLUDE_DIRS})
if (MSVC)
  set_target_properties(Tester PROPERTIES LINK_FLAGS "/LIBPATH:\"${SDL2_LIB_DIR}\"")
  list(APPEND JJ_LINK_LIBS
    "SDL2.lib"
    "SDL2main.lib"
  )
  target_link_libraries(Tester ${JJ_LINK_LIBS})
  
  add_custom_command(TARGET Tester
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${SDL2_LIB_DIR}/SDL2.dll" ${JJ_BIN_DIR}
  )
else()
  target_link_libraries(Tester ${SDL2_LIBRARY})
endif()
