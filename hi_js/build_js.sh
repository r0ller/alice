emcc -s EXPORTED_FUNCTIONS="['_hi']" hi.bc libsqlite3.a libfoma.a libz.a libreadline.a -o hi.js --embed-file hi.db --embed-file english.fst
