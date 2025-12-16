add_executable(mathparser_exe src/main.cpp)
target_link_libraries(mathparser_exe PRIVATE mathparser_core)


target_include_directories(mathparser_exe PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS mathparser_exe RUNTIME DESTINATION bin)
