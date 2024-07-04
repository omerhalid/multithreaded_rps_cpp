add_executable(client
    main.cpp
    client.cpp
    client.h
)

if(WIN32)
    target_link_libraries(client ws2_32)
endif()
