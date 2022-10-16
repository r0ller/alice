export PATH=~/android-ndk-r25/toolchains/llvm/prebuilt/linux-x86_64/bin:$PATH
export TERMCAP_SRC=~/termcap-1.3.1
export TERMCAP_BUILD=${TERMCAP_SRC}/build_arm64
mkdir $TERMCAP_BUILD
mkdir ~/termcap-1.3.1/final_arm64
cd $TERMCAP_SRC
export TARGETMACH=aarch64-linux-android
export CROSS=aarch64-linux-android23
export CC=${CROSS}-clang
export CXX=${CROSS}-clang++
export LD=ld
export AS=llvm-as
export AR=llvm-ar
export RANLIB=llvm-ranlib
cd $TERMCAP_BUILD/
$TERMCAP_SRC/./configure --prefix=${TERMCAP_SRC}/final_arm64 --host=$TARGETMACH
make
make install
