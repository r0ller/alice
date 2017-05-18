emcc -s EXPORTED_FUNCTIONS="['_hi']" -s RESERVED_FUNCTION_POINTERS=10 hi.bc libfoma.a libz.a libreadline.a -o hi.js --embed-file english.fst
