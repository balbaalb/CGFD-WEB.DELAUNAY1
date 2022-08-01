// Ref 1: https://nodejs.org/api/addons.html
// Ref 2: https://nodeaddons.com/
#include "EngineInterface.h"
#include <string>
#include <node.h>
#include <nan.h>

namespace Addon
{

  using v8::Exception;
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Number;
  using v8::Object;
  using v8::String;
  using v8::Value;
  using v8::Array;
  using namespace std;
  using namespace Nan;

  // Input arguments are passed using the
  // const FunctionCallbackInfo<Value>& args struct
  void AddonInterface(const FunctionCallbackInfo<Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();
    v8::String::Utf8Value str(isolate, args[0]);
    std::string cppStr(*str);
    Nan::New<String>(cppStr.c_str());
    int res = EngineInterface(cppStr);
    Local<Number> num = Number::New(isolate, res);
    args.GetReturnValue().Set(num);
    //args.GetReturnValue().Set(Nan::New<String>(cppStr.c_str()).ToLocalChecked()); 
  }

  void Init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "AddonInterface", AddonInterface);
  }

  NODE_MODULE(EngineAddon, Init)

}