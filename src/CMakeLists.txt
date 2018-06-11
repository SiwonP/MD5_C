add_executable(
    md5-cli
    main.c
    md5.c
    )

add_library(
    md5 SHARED
    md5.c
    )
