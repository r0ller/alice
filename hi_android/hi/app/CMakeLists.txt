# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

include_directories(jni/)
include_directories(src/main/cpp)
add_library( # Sets the name of the library.
        foma
        # Sets the library as a shared library.
        SHARED

        IMPORTED
        )

set_target_properties( # Specifies the target library.
        foma

        # Specifies the parameter you want to define.
        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
        ${PROJECT_SOURCE_DIR}/ndkLibs/${ANDROID_ABI}/libfoma.so
        )

#add_library( # Sets the name of the library.
#        hisqlite3
#        # Sets the library as a shared library.
#        SHARED

#        IMPORTED
#        )

#set_target_properties( # Specifies the target library.
#        hisqlite3

#        # Specifies the parameter you want to define.
#        PROPERTIES IMPORTED_LOCATION

#        # Provides the path to the library you want to import.
#        ${PROJECT_SOURCE_DIR}/ndkLibs/${ANDROID_ABI}/libhisqlite3.so
#        )

#add_library( # Sets the name of the library.
#       hilib

        # Sets the library as a shared library.
#       SHARED

#        IMPORTED
#        )

#set_target_properties( # Specifies the target library.
#        hilib

        # Specifies the parameter you want to define.
#        PROPERTIES IMPORTED_LOCATION

        # Provides the path to the library you want to import.
#       ${PROJECT_SOURCE_DIR}/ndkLibs/${ANDROID_ABI}/libhilib.so
#        )

add_library( # Sets the name of the library.
        jhi

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        #0) external includes (like rapidjson, foma or sqlite3) are to be copied into the /jni folder
        #1) make android_parser_db
        #2) make android_bison_parser
        #3) make android_parser
        #4) copy the hi/build directory and all .cpp,.h files in /hi to src/main/cpp (winscp: mark->select files:*.h; *.cpp | */)
        #5) if necessary, adjust the list of .cpp files listed here
        jni/jhi.cpp
        src/main/cpp/build/hi_android/hi.y.cpp
        src/main/cpp/sh_transcriptor.cpp
        src/main/cpp/js_transcriptor.cpp
        src/main/cpp/transcriptor.cpp
        src/main/cpp/hi_transcribe.cpp
        src/main/cpp/hi_cvalue.cpp
        src/main/cpp/hi_query.cpp
        src/main/cpp/logger.cpp
        src/main/cpp/jni_db.cpp
        src/main/cpp/lexer.cpp
        src/main/cpp/sp.cpp
        src/main/cpp/tokenpaths.cpp
        src/main/cpp/query_result.cpp
        src/main/cpp/morphan_result.cpp
        src/main/cpp/morphan.cpp
        src/main/cpp/transgraph.cpp
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        jhi
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
        #hilib
        #hisqlite3
        foma
        )