set(BINARY ${cmake_project_name}_test)

add_executable(${BINARY} EsempioCartella.cpp EsempioNota.cpp TestCartella.cpp TestNota.cpp TestMain.cpp )

target_link_libraries(${BINARY} PUBLIC ${cmake_project_name}_lib gtest)
