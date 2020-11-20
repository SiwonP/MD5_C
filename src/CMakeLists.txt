add_executable(
    md5-cli
    main.c
    )

target_link_libraries(
    md5-cli
    md5
    )

add_library(
    md5 STATIC
    md5.c
    )
