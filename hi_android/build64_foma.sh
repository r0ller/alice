cmake .. \
-DCMAKE_C_COMPILER=/home/r0ller/android-ndk/android-ndk-r25b/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android23-clang \
-DCMAKE_CXX_COMPILER=/home/r0ller/android-ndk/android-ndk-r25b/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android23-clang++ \
-DCMAKE_INCLUDE_PATH=/home/r0ller/android-ndk/android-ndk-r25b/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/include \
-DCMAKE_LIBRARY_PATH=/home/r0ller/android-ndk/android-ndk-r25b/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/lib/aarch64-linux-android/23
make foma-shared