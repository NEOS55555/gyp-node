#include <node_api.h>
#include <napi.h>
#include <Windows.h>
#include <WinUser.h>
using namespace Napi;

void KeyDown(const CallbackInfo& info) {
    Number str = info[0].As<Number>();
    keybd_event(str.DoubleValue(),0,0,0);
    info.Env();
}
void KeyUp(const CallbackInfo& info) {
    Number str = info[0].As<Number>();
    keybd_event(str.DoubleValue(),0,2,0);
    info.Env();
}

Object Init(Env env, Object exports) {
    exports.Set("keydown", Function::New(env, KeyDown));
    exports.Set("keyup", Function::New(env, KeyUp));
    return exports;
}

NODE_API_MODULE(addon, Init)