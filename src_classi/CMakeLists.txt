set(BINARY ${LAB_PROG_Mazzocchi})

set(SOURCES ConcreteObserver.cpp Cartella.cpp Nota.cpp)

add_executable(${BINARY}_run main.cpp ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})