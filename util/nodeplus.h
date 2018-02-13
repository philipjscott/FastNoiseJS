#ifndef NODEPLUS_H
#define NODEPLUS_H

#define NODE_DEFINE_CONST(target, constantName, constant)                     \
  do {                                                                        \
    v8::Isolate* isolate = target->GetIsolate();                              \
    v8::Local<v8::Context> context = isolate->GetCurrentContext();            \
    v8::Local<v8::String> constant_name =                                     \
        v8::String::NewFromUtf8(isolate, constantName);                       \
    v8::Local<v8::Number> constant_value =                                    \
        v8::Number::New(isolate, static_cast<int>(constant));                 \
    v8::PropertyAttribute constant_attributes =                               \
        static_cast<v8::PropertyAttribute>(v8::ReadOnly | v8::DontDelete);    \
    (target)->DefineOwnProperty(context,                                      \
                                constant_name,                                \
                                constant_value,                               \
                                constant_attributes).FromJust();              \
  }                                                                           \
  while (0)

inline void NODE_SET_OBJECT(v8::Local<v8::Object> recv,
                            const char* name,
                            v8::Local<v8::Object> obj) {
  v8::Isolate* isolate = v8::Isolate::GetCurrent();

  v8::Local<v8::String> obj_name = v8::String::NewFromUtf8(isolate, name);
  recv->Set(obj_name, obj);
}

#endif
