cmake_minimum_required( VERSION 3.0 )
project(md5)

file(
    GLOB_RECURSE
    source_files
    src/*
)

add_executable(
    md5
    ${source_files}
    main.c
)
