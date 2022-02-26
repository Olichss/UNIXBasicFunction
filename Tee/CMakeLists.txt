cmake_minimum_required(VERSION 3.10)

project(Tee VERSION 3.0.0)

# Переменная для одиковых названий экспортруемого таргетов
set(EXPORT_TARGETS_NAME ${PROJECT_NAME}Targets)

# Определяем стандарт С++
set(CMAKE_CXX_STANDARD 14)

# Определяем суфикс для версии Debug
set(CMAKE_DEBUG_POSTFIX _g)

# Определяем флаги для компиляции файлов C (если таковые имеются)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -D_DEBUG")

# Определяем список исходных файлов
file(GLOB SOURCES *.cpp)
# Определяем имя цели (проекта)
add_executable(${PROJECT_NAME} ${SOURCES})