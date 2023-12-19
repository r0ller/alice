#include "js_db.h"
/*
When using the EM_ASM macro, ensure that you only use single quotes(‘) like alert('hello world!').
Double quotes(”) will cause a syntax error that is not detected by the compiler
and is only shown when looking at a JavaScript console while running the offending code.
*/
js_db::js_db(){
	std::cout<<"jsdebug1"<<std::endl;
	//something like these may help:
	//https://groups.google.com/forum/#!searchin/emscripten-discuss/emscripten$3A$3Aval/emscripten-discuss/7-i5pRK7edQ/81zLcQ6LAwAJ
	//https://github.com/kripken/emscripten/issues/1194
	//https://docs.mongodb.com/getting-started/node/client/
	//https://kripken.github.io/emscripten-site/docs/porting/connecting_cpp_and_javascript/embind.html#using-val-to-transliterate-javascript-to-c
	//koa:https://eladnava.com/write-synchronous-node-js-code-with-es6-generators/
	//koa:http://koajs.com
	mongodb_init_fptr = EM_ASM_INT({
		mongodb_init = Runtime.addFunction(function(objid) {
			console.log('objid:'+objid);
			function mongodb(objid) {
				var self = this;
				this.id = objid;
//				this.MongoClient=null;
//				this.assert=null;
				this.Mongomery=null;
				this.init = function () {
					console.log('mongoinst init');
//					self.MongoClient = require('mongodb').MongoClient;
//					self.assert = require('assert');
					self.Mongomery = require('mongomery');
				};
				this.open = function (uri){
					console.log('Mongomery opening '+uri);
					self.Mongomery(function*(mongo) {
						var db = yield mongo.connect(uri);
						console.log('db yielded');
						var collection  = db.collection('entries');
						console.log('collection got');
						var docs = yield collection.find({}).toArray();
						console.log('docs yielded');
						docs.forEach(function(item) {
							console.log(item);
						});
						db.close();
					}).on('error', function(error) {
						console.log(error.message);
					});
				};
			}
			if(typeof mongoinst === 'undefined') {
				mongoinst=[];
			}
			mongoinst[objid] = new mongodb();
			mongoinst[objid].init();
		});
		return mongodb_init;
	},0);
	void (*mongodb_init)(int) = reinterpret_cast<void (*)(int)>(mongodb_init_fptr);
//	mongodb_init(1);
}

js_db::~js_db(){
	//TODO: don't forget Runtime.removeFunction($0) and for $1 and so on for all fptrs;
}

void js_db::open(const std::string& db_uri){
	std::cout<<"jsdebug2"<<std::endl;
	this->db_uri=db_uri;
	int addr = EM_ASM_INT({
		var uri = Module.Pointer_stringify($1);
//		var addr = mongoinst[$0].open(uri);
		var mongomery = require('mongomery');
		mongomery(function*(mongo) {
			var url = uri,
			db = yield mongo.connect(url),
			collection = db.collection('entries'),
			docs = yield collection.find({}).toArray();

			docs.forEach(function(item) {
				console.log(item);
			});
			console.log(db);
			db.close();
		}).on('error', function(error) {
		 console.log(error.message);
		});

		console.log('returned');
		return 0;
//		return addr;
	},1,db_uri.c_str());//variables passed in are labelled inside EM_ASM_ according to their sequence, numbered as $0, $1, etc.
//	std::cout<<std::string(reinterpret_cast<char*>(addr))<<std::endl;
}

void js_db::close(){
}

const std::string js_db::error_message(){
	return std::string();
}

query_result *js_db::exec_sql(const std::string& sql){
	return NULL;
}
