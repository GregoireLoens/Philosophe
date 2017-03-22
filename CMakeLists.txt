cmake_minimum_required(VERSION 3.6)
project(PSU_2016_philo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        includes/extern.h
        includes/philo_struct.h
        includes/philosophers.h
        includes/philosophers_states.h
        includes/table.h
        sources/command_line.c
        sources/main.c
        sources/philosophers.c
        sources/philosophers_states.c
        sources/philosophers_utils.c
        sources/table.c
        sources/table_extend.c)

add_executable(PSU_2016_philo ${SOURCE_FILES})