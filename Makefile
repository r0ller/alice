.POSIX:

#End of variable=value assignment is a newline, not a semicolon nor single nor double quotes around the value
PROJECTSRCDIR=$$(pwd)#${PROJECTDIR} is reserved by make
BUILDDIR=build
ABSBUILDDIR=$$(readlink -f ${BUILDDIR})
CXX=clang++
CXXFLAGS=-std=c++17 -fPIC -pedantic -Wall
INCLUDEDIRS=-I${PROJECTSRCDIR} -I/usr/pkg/include -I/usr/local/include
COMMONLIBDIRS=-L/usr/pkg/lib -L/usr/local/lib
NATIVELIBDIR=-L${BUILDDIR}/hi_desktop
NATIVEEXELDFLAGS=-Wl,-rpath=${ABSBUILDDIR}/hi_desktop -lhilib -lsqlite3 -lfoma -lz
PARSERGENLDFLAGS=-lsqlite3
NDK32BITTOOLCHAINDIR=
NDK64BITTOOLCHAINDIR=
ARM32CXX=armv7a-linux-androideabi23-clang++
ARM32INCLUDEDIRS=-I${BUILDDIR}/hi_android -I${PROJECTSRCDIR} -I${PROJECTSRCDIR}/hi_android/hi/app/jni -I${NDK32BITTOOLCHAINDIR}/sysroot/usr/include -I/usr/pkg/include -I/usr/local/include
ARM32LIBDIR=-L${PROJECTSRCDIR}/hi_android/hi/app/ndkLibs/armeabi-v7a -L${NDK32BITTOOLCHAINDIR}/sysroot/usr/lib/arm-linux-androideabi/23
ARM32LDFLAGS=-v -Wl,-soname,libhilib.so -lfoma -llog
ARM64CXX=aarch64-linux-android23-clang++
ARM64INCLUDEDIRS=-I${BUILDDIR}/hi_android -I${PROJECTSRCDIR} -I${PROJECTSRCDIR}/hi_android/hi/app/jni -I${NDK64BITTOOLCHAINDIR}/sysroot/usr/include -I/usr/pkg/include -I/usr/local/include
ARM64LIBDIR=-L${PROJECTSRCDIR}/hi_android/hi/app/ndkLibs/arm64-v8a -L${NDK64BITTOOLCHAINDIR}/sysroot/usr/lib/aarch64-linux-android/23
ARM64LDFLAGS=-v -Wl,-soname,libhilib.so -lfoma -llog
JSINCLUDEDIRS=-I${BUILDDIR}/hi_js -I${PROJECTSRCDIR} -I/usr/pkg/include -I/usr/local/include
JSLIBDIR=-L${PROJECTSRCDIR}/hi_js
JSDB=${ABSBUILDDIR}/hi_js/hi.db
JSFST=${ABSBUILDDIR}/hi_js/english.fst
EMSCRIPTENDIR=
USERSHELL=$$(getent passwd $$(whoami)|cut -d: -f7)
TESTSINCLUDEDIRS=-I${PROJECTSRCDIR} -I/usr/pkg/include -I/usr/local/include -I/usr/pkg/include/python3.7

#posix trick for ifdef:if DEBUG is defined on command line (even as empty), the variable with the name of
#the concatenation of CXXFLAGS_DEBUG and ${DEBUG} will be set and CXXFLAGS_DEBUG retains its preset value
#if DEBUG is not defined, CXXFLAGS_DEBUG${DEBUG} will expand to CXXFLAGS_DEBUG+<empty> which is
#CXXFLAGS_DEBUG and any preset, existing value gets overwritten by the new assignment
#Another option would be to use suffixed version for variables and switch dynamically: EXTRA_FLAGS = ${EXTRA_FLAGS_${USE_FOO}}
CXXFLAGS_DEBUG=-fstandalone-debug -g
CXXFLAGS_DEBUG${DEBUG}=

NATIVEPARSERFILEPATH=${BUILDDIR}/hi_desktop/hi.y
ANDROIDPARSERFILEPATH=${BUILDDIR}/hi_android/hi.y
JSPARSERFILEPATH=${BUILDDIR}/hi_js/hi.y
DBSCHEMA=${PROJECTSRCDIR}/hi_db.sql

NATIVEPARSERDBCONTENT=${PROJECTSRCDIR}/hi_desktop/desktop_content.sql
NATIVEPARSERDBNAME=hi.db
DESKTOPACTIONSNIPPETS=${PROJECTSRCDIR}/gensrc
DESKTOPFUNCTORPATH=${PROJECTSRCDIR}/hi_desktop/functors
DESKTOPFOMAPATH=${PROJECTSRCDIR}/hi_desktop/foma/english.foma
DESKTOPFSTNAME=english.fst
DESKTOPLEXCFILES=${PROJECTSRCDIR}/hi_desktop/foma

ANDROIDPARSERDBCONTENT=${PROJECTSRCDIR}/hi_android/android_content.sql
ANDROIDPARSERDBNAME=hi.db
ANDROIDACTIONSNIPPETS=${PROJECTSRCDIR}/gensrc
ANDROIDFUNCTORPATH=${PROJECTSRCDIR}/hi_android/functors
ANDROIDFOMAPATH=${PROJECTSRCDIR}/hi_android/foma/english.foma
ANDROIDFSTNAME=english.fst
ANDROIDLEXCFILES=${PROJECTSRCDIR}/hi_android/foma

JSPARSERDBCONTENT=${PROJECTSRCDIR}/hi_js/js_content.sql
JSPARSERDBNAME=hi.db
JSACTIONSNIPPETS=${PROJECTSRCDIR}/gensrc
JSFUNCTORPATH=${PROJECTSRCDIR}/hi_js/functors
JSFOMAPATH=${PROJECTSRCDIR}/hi_js/foma/english.foma
JSFSTNAME=english.fst
JSLEXCFILES=${PROJECTSRCDIR}/hi_js/foma

all: desktop_fst desktop_parser_db desktop_bison_parser desktop_parser shared_native_lib desktop_client android_fst android_parser_db android_bison_parser android_parser arm32_lib arm64_lib js_fst js_parser_db js_bison_parser js_parser embedded_js_lib node_js_lib test_tools ml_tools

desktop_client:
	mkdir -p ${BUILDDIR};\
	projectdir=${PROJECTSRCDIR};\
	includedirs="${INCLUDEDIRS}";\
	nativelibdir=${NATIVELIBDIR};\
	nativeexeldflags="${NATIVEEXELDFLAGS}";\
	${CXX} $$projectdir/hi.cpp -o ${BUILDDIR}/hi ${CXXFLAGS} ${CXXFLAGS_DEBUG} $$includedirs $$nativelibdir ${COMMONLIBDIRS} $$nativeexeldflags

desktop_fst:
	mkdir -p ${BUILDDIR}/hi_desktop;\
	desktopfomapath=${DESKTOPFOMAPATH};\
	fomabasename=$$(basename ${DESKTOPFOMAPATH});\
	desktoplexcfiles=${DESKTOPLEXCFILES};\
	cp $$desktopfomapath ${BUILDDIR}/hi_desktop;\
	cp $$desktoplexcfiles/*.lexc ${BUILDDIR}/hi_desktop;\
	cd ${BUILDDIR}/hi_desktop;\
	echo save stack ${DESKTOPFSTNAME}|foma -l $$fomabasename;

desktop_parser_db:
	mkdir -p ${BUILDDIR}/hi_desktop;\
	if [ -f ${BUILDDIR}/hi_desktop/${NATIVEPARSERDBNAME} ]; then rm ${BUILDDIR}/hi_desktop/${NATIVEPARSERDBNAME}; fi;\
	dbschema=${DBSCHEMA};\
	dbcontent=${NATIVEPARSERDBCONTENT};\
	cat $$dbschema|sqlite3 ${BUILDDIR}/hi_desktop/${NATIVEPARSERDBNAME};\
	cat $$dbcontent|sqlite3 ${BUILDDIR}/hi_desktop/${NATIVEPARSERDBNAME};

desktop_bison_parser: parser_generator
	mkdir -p ${BUILDDIR}/hi_desktop;\
	desktopactionsnippets=${DESKTOPACTIONSNIPPETS};\
	desktopfunctorpath=${DESKTOPFUNCTORPATH};\
	${BUILDDIR}/gensrc ${BUILDDIR}/hi_desktop/${NATIVEPARSERDBNAME} $$desktopactionsnippets ${NATIVEPARSERFILEPATH} $$desktopfunctorpath;

desktop_parser:
	mkdir -p ${BUILDDIR}/hi_desktop;\
	parserfilename=$$(basename ${NATIVEPARSERFILEPATH});\
	srcfilepath=${BUILDDIR}/hi_desktop/$$parserfilename.cpp;\
	bison -o $$srcfilepath ${NATIVEPARSERFILEPATH};

shared_native_lib:
	mkdir -p ${BUILDDIR}/hi_desktop;\
	projectdir=${PROJECTSRCDIR};\
	includedirs="${INCLUDEDIRS}";\
	parserfilename=$$(basename ${NATIVEPARSERFILEPATH});\
	nativesrcfilepath=${BUILDDIR}/hi_desktop/$$parserfilename.cpp;\
	nativeobjfilepath=${BUILDDIR}/hi_desktop/$$parserfilename.o;\
	${CXX} $$nativesrcfilepath $$projectdir/sh_transcriptor.cpp $$projectdir/js_transcriptor.cpp $$projectdir/transcriptor.cpp $$projectdir/hi_transcribe.cpp $$projectdir/hi_cvalue.cpp $$projectdir/hi_query.cpp $$projectdir/logger.cpp $$projectdir/sqlite_db.cpp $$projectdir/lexer.cpp $$projectdir/sp.cpp $$projectdir/tokenpaths.cpp $$projectdir/query_result.cpp $$projectdir/morphan_result.cpp $$projectdir/morphan.cpp $$projectdir/transgraph.cpp -U__ANDROID__ -U__EMSCRIPTEN ${CXXFLAGS} ${CXXFLAGS_DEBUG} -I${BUILDDIR}/hi_desktop $$includedirs -shared -o ${BUILDDIR}/hi_desktop/libhilib.so;

android_fst:
	mkdir -p ${BUILDDIR}/hi_android;\
	androidfomapath=${ANDROIDFOMAPATH};\
	fomabasename=$$(basename ${ANDROIDFOMAPATH});\
	androidlexcfiles=${ANDROIDLEXCFILES};\
	cp $$androidfomapath ${BUILDDIR}/hi_android;\
	cp $$androidlexcfiles/*.lexc ${BUILDDIR}/hi_android;\
	cd ${BUILDDIR}/hi_android;\
	echo save stack ${ANDROIDFSTNAME}|foma -l $$fomabasename;

android_parser_db:
	mkdir -p ${BUILDDIR}/hi_android;\
	if [ -f ${BUILDDIR}/hi_android/${ANDROIDPARSERDBNAME} ]; then rm ${BUILDDIR}/hi_android/${ANDROIDPARSERDBNAME}; fi;\
	dbschema=${DBSCHEMA};\
	dbcontent=${ANDROIDPARSERDBCONTENT};\
	cat $$dbschema|sqlite3 ${BUILDDIR}/hi_android/${ANDROIDPARSERDBNAME};\
	cat $$dbcontent|sqlite3 ${BUILDDIR}/hi_android/${ANDROIDPARSERDBNAME};

android_bison_parser: parser_generator
	mkdir -p ${BUILDDIR}/hi_android;\
	androidactionsnippets=${ANDROIDACTIONSNIPPETS};\
	androidfunctorpath=${ANDROIDFUNCTORPATH};\
	${BUILDDIR}/gensrc ${BUILDDIR}/hi_android/${ANDROIDPARSERDBNAME} $$androidactionsnippets ${ANDROIDPARSERFILEPATH} $$androidfunctorpath;

android_parser:
	mkdir -p ${BUILDDIR}/hi_android;\
	parserfilename=$$(basename ${ANDROIDPARSERFILEPATH});\
	srcfilepath=${BUILDDIR}/hi_android/$$parserfilename.cpp;\
	bison -v -o $$srcfilepath ${ANDROIDPARSERFILEPATH};

arm32_lib:
	ndk32toolchaindir=${NDK32BITTOOLCHAINDIR};\
	if [ -z $$ndk32toolchaindir ]; then echo NDK32BITTOOLCHAINDIR cannot be empty; exit; fi;\
	mkdir -p ${BUILDDIR}/hi_android/arm32;\
	projectdir=${PROJECTSRCDIR};\
	includedirs="${ARM32INCLUDEDIRS}";\
	parserfilename=$$(basename ${ANDROIDPARSERFILEPATH});\
	androidsrcfilepath=${BUILDDIR}/hi_android/$$parserfilename.cpp;\
	androidobjfilepath=${BUILDDIR}/hi_android/arm32/$$parserfilename.o;\
	arm32libfilepath=${BUILDDIR}/hi_android/arm32/libhilib.so;\
	system=$$(uname -s);\
	case $$system in \
	NetBSD) arm32libfilepath=${BUILDDIR}/hi_android/arm32/fifo_hilib;\
	if [ -f $$arm32libfilepath ]; then rm $$arm32libfilepath; fi;\
	mkfifo $$arm32libfilepath;\
	cat $$arm32libfilepath > ${BUILDDIR}/hi_android/arm32/libhilib.so &\
	;;\
	esac;\
	${NDK32BITTOOLCHAINDIR}/bin/${ARM32CXX} ${CXXFLAGS} $$includedirs -shared $$androidsrcfilepath -D__ANDROID__ $$projectdir/sh_transcriptor.cpp $$projectdir/js_transcriptor.cpp $$projectdir/transcriptor.cpp $$projectdir/hi_transcribe.cpp $$projectdir/hi_cvalue.cpp $$projectdir/hi_query.cpp $$projectdir/logger.cpp $$projectdir/jni_db.cpp $$projectdir/lexer.cpp $$projectdir/sp.cpp $$projectdir/tokenpaths.cpp $$projectdir/query_result.cpp $$projectdir/morphan_result.cpp $$projectdir/morphan.cpp $$projectdir/transgraph.cpp ${ARM32LIBDIR} ${ARM32LDFLAGS} -o $$arm32libfilepath;

arm64_lib:
	ndk64toolchaindir=${NDK64BITTOOLCHAINDIR};\
	if [ -z $$ndk64toolchaindir ]; then echo NDK64BITTOOLCHAINDIR cannot be empty; exit; fi;\
	mkdir -p ${BUILDDIR}/hi_android/arm64;\
	projectdir=${PROJECTSRCDIR};\
	includedirs="${ARM64INCLUDEDIRS}";\
	parserfilename=$$(basename ${ANDROIDPARSERFILEPATH});\
	androidsrcfilepath=${BUILDDIR}/hi_android/$$parserfilename.cpp;\
	androidobjfilepath=${BUILDDIR}/hi_android/arm64/$$parserfilename.o;\
	arm64libfilepath=${BUILDDIR}/hi_android/arm64/libhilib.so;\
	system=$$(uname -s);\
	case $$system in \
	NetBSD) arm64libfilepath=${BUILDDIR}/hi_android/arm64/fifo_hilib;\
	if [ -f $$arm64libfilepath ]; then rm $$arm64libfilepath; fi;\
	mkfifo $$arm64libfilepath;\
	cat $$arm64libfilepath > ${BUILDDIR}/hi_android/arm64/libhilib.so &\
	;;\
	esac;\
	${NDK64BITTOOLCHAINDIR}/bin/${ARM64CXX} ${CXXFLAGS} $$includedirs -shared $$androidsrcfilepath -D__ANDROID__ $$projectdir/sh_transcriptor.cpp $$projectdir/js_transcriptor.cpp $$projectdir/transcriptor.cpp $$projectdir/hi_transcribe.cpp $$projectdir/hi_cvalue.cpp $$projectdir/hi_query.cpp $$projectdir/logger.cpp $$projectdir/jni_db.cpp $$projectdir/lexer.cpp $$projectdir/sp.cpp $$projectdir/tokenpaths.cpp $$projectdir/query_result.cpp $$projectdir/morphan_result.cpp $$projectdir/morphan.cpp $$projectdir/transgraph.cpp ${ARM64LIBDIR} ${ARM64LDFLAGS} -o $$arm64libfilepath;

js_fst:
	mkdir -p ${BUILDDIR}/hi_js;\
	jsfomapath=${JSFOMAPATH};\
	fomabasename=$$(basename ${JSFOMAPATH});\
	jslexcfiles=${JSLEXCFILES};\
	cp $$jsfomapath ${BUILDDIR}/hi_js;\
	cp $$jslexcfiles/*.lexc ${BUILDDIR}/hi_js;\
	cd ${BUILDDIR}/hi_js;\
	echo save stack ${JSFSTNAME}|foma -l $$fomabasename;

js_parser_db:
	mkdir -p ${BUILDDIR}/hi_js;\
	if [ -f ${BUILDDIR}/hi_js/${JSPARSERDBNAME} ]; then rm ${BUILDDIR}/hi_js/${JSPARSERDBNAME}; fi;\
	dbschema=${DBSCHEMA};\
	dbcontent=${JSPARSERDBCONTENT};\
	cat $$dbschema|sqlite3 ${BUILDDIR}/hi_js/${JSPARSERDBNAME};\
	cat $$dbcontent|sqlite3 ${BUILDDIR}/hi_js/${JSPARSERDBNAME};

js_bison_parser: parser_generator
	mkdir -p ${BUILDDIR}/hi_js;\
	jsactionsnippets=${JSACTIONSNIPPETS};\
	jsfunctorpath=${JSFUNCTORPATH};\
	${BUILDDIR}/gensrc ${BUILDDIR}/hi_js/${JSPARSERDBNAME} $$jsactionsnippets ${JSPARSERFILEPATH} $$jsfunctorpath;

js_parser:
	mkdir -p ${BUILDDIR}/hi_js;\
	parserfilename=$$(basename ${JSPARSERFILEPATH});\
	srcfilepath=${BUILDDIR}/hi_js/$$parserfilename.cpp;\
	bison -o $$srcfilepath ${JSPARSERFILEPATH};

embedded_js_lib:
	emscriptendir=${EMSCRIPTENDIR};\
	if [ -z $$emscriptendir ]; then echo EMSCRIPTENDIR cannot be empty; exit; fi;\
	mkdir -p ${BUILDDIR}/hi_js/embedded;\
	projectdir=${PROJECTSRCDIR};\
	includedirs="${JSINCLUDEDIRS}";\
	parserfilename=$$(basename ${JSPARSERFILEPATH});\
	srcfilepath=${ABSBUILDDIR}/hi_js/$$parserfilename.cpp;\
	jsobjfilepath=${ABSBUILDDIR}/hi_js/embedded/$$parserfilename.bc;\
	jslibdir=${JSLIBDIR};\
	jsdb=${JSDB};\
	jsfst=${JSFST};\
	absbuilddir=${ABSBUILDDIR};\
	exportedfunction="\"['_hi']\"";\
	${USERSHELL} -c "source ${EMSCRIPTENDIR}/emsdk_env.sh;\
	${EMSCRIPTENDIR}/upstream/emscripten/em++ ${CXXFLAGS} $$includedirs -s EXPORTED_FUNCTIONS=$$exportedfunction -s EXTRA_EXPORTED_RUNTIME_METHODS=\"['ccall']\" $$srcfilepath $$projectdir/sh_transcriptor.cpp $$projectdir/js_transcriptor.cpp $$projectdir/transcriptor.cpp $$projectdir/hi_transcribe.cpp $$projectdir/hi_cvalue.cpp $$projectdir/hi_query.cpp $$projectdir/logger.cpp $$projectdir/sqlite_db.cpp $$projectdir/lexer.cpp $$projectdir/sp.cpp $$projectdir/tokenpaths.cpp $$projectdir/query_result.cpp $$projectdir/morphan_result.cpp $$projectdir/morphan.cpp $$projectdir/transgraph.cpp $$jslibdir -lsqlite3 -lfoma -lz -lreadline -o $$absbuilddir/hi_js/embedded/hi.js --embed-file $$jsdb --embed-file $$jsfst;"
#POSIX breaks here: ${USERSHELL} is necessary as some shells like the default NetBSD sh does not support pushd and popd used in emsdk_env.sh

node_js_lib:
	emscriptendir=${EMSCRIPTENDIR};\
	if [ -z $$emscriptendir ]; then echo EMSCRIPTENDIR cannot be empty; exit; fi;\
	mkdir -p ${BUILDDIR}/hi_js/nodejs;\
	projectdir=${PROJECTSRCDIR};\
	includedirs="${JSINCLUDEDIRS}";\
	parserfilename=$$(basename ${JSPARSERFILEPATH});\
	srcfilepath=${ABSBUILDDIR}/hi_js/$$parserfilename.cpp;\
	jsobjfilepath=${ABSBUILDDIR}/hi_js/nodejs/$$parserfilename.bc;\
	jslibdir=${JSLIBDIR};\
	absbuilddir=${ABSBUILDDIR};\
	exportedfunction="\"['_hi']\"";\
	${USERSHELL} -c "source ${EMSCRIPTENDIR}/emsdk_env.sh;\
	${EMSCRIPTENDIR}/upstream/emscripten/em++ ${CXXFLAGS} -DFS=NODEJS $$includedirs -s EXPORTED_FUNCTIONS=$$exportedfunction -s EXTRA_EXPORTED_RUNTIME_METHODS=\"['ccall']\" $$srcfilepath $$projectdir/sh_transcriptor.cpp $$projectdir/js_transcriptor.cpp $$projectdir/transcriptor.cpp $$projectdir/hi_transcribe.cpp $$projectdir/hi_cvalue.cpp $$projectdir/hi_query.cpp $$projectdir/logger.cpp $$projectdir/sqlite_db.cpp $$projectdir/lexer.cpp $$projectdir/sp.cpp $$projectdir/tokenpaths.cpp $$projectdir/query_result.cpp $$projectdir/morphan_result.cpp $$projectdir/morphan.cpp $$projectdir/transgraph.cpp $$jslibdir -lsqlite3 -lfoma -lz -lreadline -o $$absbuilddir/hi_js/nodejs/hi.js;"

parser_generator:
	mkdir -p ${BUILDDIR};\
	projectdir=${PROJECTSRCDIR};\
	includedirs="${INCLUDEDIRS}";\
	${CXX} $$projectdir/gensrc/gensrc.cpp $$projectdir/logger.cpp $$projectdir/sqlite_db.cpp $$projectdir/query_result.cpp -o ${BUILDDIR}/gensrc ${CXXFLAGS} ${CXXFLAGS_DEBUG} $$includedirs ${COMMONLIBDIRS} ${PARSERGENLDFLAGS}

test_tools:
	mkdir -p ${BUILDDIR};\
	projectdir=${PROJECTSRCDIR};\
	includedirs="${TESTSINCLUDEDIRS}";\
	cp $$projectdir/tests/remove_stex_output_duplicates.sh ${BUILDDIR};\
	${CXX} $$projectdir/tests/stax.cpp $$projectdir/logger.cpp $$projectdir/sqlite_db.cpp $$projectdir/query_result.cpp $$projectdir/morphan_result.cpp $$projectdir/morphan.cpp -o ${BUILDDIR}/stax ${CXXFLAGS} ${CXXFLAGS_DEBUG} $$includedirs ${COMMONLIBDIRS} -lsqlite3 -lfoma;\
	${CXX} $$projectdir/tests/stex.cpp $$projectdir/logger.cpp $$projectdir/sqlite_db.cpp $$projectdir/query_result.cpp $$projectdir/morphan_result.cpp $$projectdir/morphan.cpp -o ${BUILDDIR}/stex ${CXXFLAGS} ${CXXFLAGS_DEBUG} $$includedirs ${COMMONLIBDIRS} -lsqlite3 -lpython3.7 -lfoma;\

ml_tools:
	mkdir -p ${BUILDDIR};\
	projectdir=${PROJECTSRCDIR};\
	includedirs="${INCLUDEDIRS}";\
	${CXX} $$projectdir/ml/prep_abl.cpp $$projectdir/logger.cpp $$projectdir/sqlite_db.cpp $$projectdir/lexer.cpp $$projectdir/sp.cpp $$projectdir/tokenpaths.cpp $$projectdir/query_result.cpp $$projectdir/morphan_result.cpp $$projectdir/morphan.cpp $$projectdir/transgraph.cpp -o ${BUILDDIR}/prep_abl ${CXXFLAGS} ${CXXFLAGS_DEBUG} $$includedirs ${COMMONLIBDIRS} -lsqlite3 -lfoma;\
	${CXX} $$projectdir/ml/proc_abl.cpp $$projectdir/logger.cpp $$projectdir/sqlite_db.cpp $$projectdir/query_result.cpp -o ${BUILDDIR}/proc_abl ${CXXFLAGS} ${CXXFLAGS_DEBUG} $$includedirs ${COMMONLIBDIRS} -lsqlite3;\

clean:
	rm -rf ${BUILDDIR}

help:
	@echo Set the following variables on the command line like \'make variable=value\' to influence the make process:
#comments shall not be indented in commmands as gnu make will echo them though bsd make not
	@echo;echo Variables defined:
	@grep -v ^\#.* "${PROJECTSRCDIR}/Makefile"|grep -v ^[[:blank:]]|grep -E [[:blank:]]*[a-zA-Z0-9_-\$\{\}][a-zA-Z0-9_-]*=[^\#]*
#as the sh -c set command cannot be used to print the variables since commands are exeucted in subshells,
#grep the Makefile itself for variables used as ${} or $() though, not looking for $() currently as I don't use variables that way
#TODO:look for $() as well
#TODO:handling hashtags in a makefile command is a nightmare so this isn't perfect either:
#it isn't only cutting comments but anything after an escaped hashtag as well
	@echo;echo Variables used:
	@grep $$\{ "${PROJECTSRCDIR}/Makefile"|grep -v ^\#.*|cut -f 1 -d \#|grep -o $$\{[^{}][^{}]*\}|sort|uniq|tr '\n' ' '
#see next line for another variant of getting the variables used where the for loop is only there to be able put in some code
#if possible at all that assigns the variables to their values and prints them like ${var}=value
#@vars="$$(grep $$\{ "${PROJECTSRCDIR}/gensrc/Makefile"|grep -v ^\#.*|cut -f 1 -d \#|grep -o $$\{[^{}][^{}]*\}|sort|uniq|tr '\n' ' ')";for i in $$vars;do echo $$i;done
#grep the Makefile itself for targets and print them
	@echo;echo;echo Make targets:
	@grep -v ^\#.* "${PROJECTSRCDIR}/Makefile"|grep -v ^[[:blank:]]|grep -v ^\\.|grep -E [a-zA-Z0-9_-][a-zA-Z0-9_-]*\([[:blank:]][a-zA-Z0-9_-][a-zA-Z0-9_-]*\)*:
	@echo; echo No dependencies are checked currently. Please, make sure that you have the followings for your targets at least with the versions specified:
	@echo "desktop_client: rapidjson-1.1.0, nodejs (any version that can evaluate your js scripts)"
	@echo desktop_fst, android_fst, js_fst: foma-0.9.17
	@echo desktop_parser_db, android_parser_db, js_parser_db: sqlite3-3.8.11
	@echo desktop_parser, android_parser, js_parser: bison-3.0.4
	@echo shared_native_lib: foma-0.9.17, sqlite3-3.8.11, bison-3.0.4
	@echo arm32_lib, arm64_lib: Android NDK r16b
	@echo embedded_js_lib, node_js_lib: emscripten-1.36.0
	@echo test_tools: sqlite3-3.8.11, foma-0.9.17, python-3.7, nltk-3.3
	@echo "ml_tools: ABL-1.2 (Alignment-Based Learning framework)"
