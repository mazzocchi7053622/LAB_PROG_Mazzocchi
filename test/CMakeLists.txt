set(BINARY ${LAB_PROG_Mazzocchi}_test)

add_executable(${BINARY} EsempioCartella.cpp EsempioNota.cpp TestCartella.cpp TestNota.cpp TestMain.cpp )

target_link_libraries(${BINARY} PUBLIC ${LAB_PROG_Mazzocchi}_lib gtest)
