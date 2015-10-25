#include <node.h>
#include <direct.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "tools_windows_bash.h"
#include "convert.h"

namespace mkdirbash {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using tools::mkdirs;

void Mkdir(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  // get the param
  v8::String::Utf8Value param1(args[0]->ToString());
    // convert it to string
  std::string foo = std::string(*param1);
  const char *dir = foo.c_str();
  const char *out = convertToStringV8(args);
  tools::mkdirs(dir);
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "created dir"));
}

void initbash(Local<Object> exports) {
  NODE_SET_METHOD(exports, "mkdir", Mkdir);
}

NODE_MODULE(mkdirbash, initbash)

}  // namespace demo
