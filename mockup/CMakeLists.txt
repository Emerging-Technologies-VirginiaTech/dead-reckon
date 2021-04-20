add_library (Ackermann ackermann.c)

# Make sure the compiler can find include files 
target_include_directories (Ackermann PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
