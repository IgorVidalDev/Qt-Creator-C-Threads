cmake_minimum_required(VERSION 3.16)

project(ThreadExemplo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)            # Ativa o padrão C++11
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Torna obrigatório usar C++11 ou superior

add_executable(ThreadExemplo main.cpp)

include(GNUInstallDirs)
install(TARGETS ThreadExemplo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
