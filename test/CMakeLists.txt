set(GTEST_SHUFFLE 1)

#set(EXECUTABLE_OUTPUT_PATH ".")

find_package( OpenCV REQUIRED )

add_executable(
    cpp-test
    main.cpp
    UserTest.cpp
    UtilsTest.cpp
    YoloTest.cpp
        ../include/User.h ../include/yolo.h ../include/Utils.h ../app/Yolo.cpp ../app/User.cpp ../app/Utils.cpp)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})
