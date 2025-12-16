set(MATHPARSER_INTERPRETER_SOURCES
    src/coef_state.cpp
    src/func_state.cpp
    src/function_expression.cpp
    src/function_map.cpp
    src/parser.cpp
    src/parser_context.cpp
    src/parser_state.cpp
    src/init_state.cpp
    src/base_function/base_function.cpp
    src/base_function/power_function.cpp
    src/base_function/div_function.cpp
    src/base_function/mult_function.cpp
    src/base_function/add_function.cpp
    src/base_function/sin_function.cpp
    src/base_function/cos_function.cpp
    src/base_function/coe_function.cpp
    src/base_function/brackets_function.cpp
)

add_library(mathparser_core STATIC ${MATHPARSER_INTERPRETER_SOURCES})

target_include_directories(mathparser_core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
