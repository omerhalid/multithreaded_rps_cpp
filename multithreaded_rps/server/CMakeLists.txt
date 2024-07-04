add_executable(server
    main.cpp
    server.cpp
    server.h
    high_score_board.cpp
    high_score_board.h
    game_logic.cpp
    game_logic.h
)

if(WIN32)
    target_link_libraries(server ws2_32)
else()
    target_link_libraries(server pthread)
endif()
