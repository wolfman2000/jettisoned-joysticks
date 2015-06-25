list(APPEND JJ_INCLUDE_DIRS
  ${SDL2_INCLUDE_DIR}
)

list(APPEND GAMELIB_HPP
  "userState.hpp"
  "gameState.hpp"
)

list(APPEND GAMELIB_CPP
  "gameState.cpp"
)

add_library(GameLib ${GAMELIB_CPP} ${GAMELIB_HPP})

set_property(TARGET GameLib PROPERTY FOLDER "Internal Libraries")

set_target_properties(GameLib PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
)

list(APPEND CL_SRC
  "clMain.cpp"
)

add_executable(Jettisoned ${CL_SRC})

list(APPEND Jettisoned_Link_Lib
  "GameLib"
)

target_link_libraries(Jettisoned ${Jettisoned_Link_Lib})

set_property(TARGET Jettisoned PROPERTY FOLDER "Executables")

set_target_properties(Jettisoned PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
)

list(APPEND TEST_SRC
  "test.cpp"
)

list(APPEND TEST_HPP
  "resource_path.hpp"
)

add_executable(Tester ${TEST_SRC} ${TEST_HPP})

set_property(TARGET Tester PROPERTY FOLDER "Executables")

set_target_properties(Tester PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
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
