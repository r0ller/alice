export PATH=~/android-ndk-r25/toolchains/llvm/prebuilt/linux-x86_64/bin:$PATH
export TERMCAP_SRC=~/termcap-1.3.1
export READLINE_SRC=~/readline-8.1
export READLINE_BUILD=~/readline-8.1/build_arm64
mkdir $READLINE_BUILD
mkdir ~/readline-8.1/final_arm64
cd $READLINE_SRC
export TARGETMACH=aarch64-linux-android
export CROSS=aarch64-linux-android23
export CC=${CROSS}-clang
export CXX=${CROSS}-clang++
export LD=ld
export AS=llvm-as
export AR=llvm-ar
export RANLIB=llvm-ranlib
export bash_cv_wcwidth_broken=no
export ac_cv_func_malloc_0_nonnull=yes
export ac_cv_func_realloc_0_nonnull=yes
cd $READLINE_BUILD/
$READLINE_SRC/./configure --prefix=${READLINE_SRC}/final_arm64 --host=$TARGETMACH LDFLAGS=-L${TERMCAP_SRC}/final_arm64/lib
make
make install
