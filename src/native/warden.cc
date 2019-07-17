#include <nan.h>

using namespace std;
using namespace Nan;
using namespace v8;

NAN_METHOD(wardenEntry) {
  if (info.Length() > 0) {
    Local<Object> input = info[0]->ToObject();

    Local<String> x_prop = Nan::New<String>("x").ToLocalChecked();
    Local<String> y_prop = Nan::New<String>("y").ToLocalChecked();
    Local<String> sum_prop = Nan::New<String>("sum").ToLocalChecked();

    Local<Object> retval = Nan::New<Object>();

    double x = Nan::Get(input, x_prop).ToLocalChecked()->NumberValue();
    double y = Nan::Get(input, y_prop).ToLocalChecked()->NumberValue();

    Nan::Set(retval, sum_prop, Nan::New<Number>(x + y));

    info.GetReturnValue().Set(retval);
  }
}

NAN_MODULE_INIT(Initialize) {
  Nan::Set(target, New<String>("warden").ToLocalChecked(),
      GetFunction(New<FunctionTemplate>(wardenEntry)).ToLocalChecked());
}

NODE_MODULE(warden, Initialize)