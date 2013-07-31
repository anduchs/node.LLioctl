/**
 * Copyright 2013, Andreas Fuchs
 * For license information please refer to the LICENSE-file.
 * With big thanks to the node.js api documentation.
 */

#include <node.h>
#include <node_buffer.h>
#include <v8.h>
#include <sys/ioctl.h>
#include <errno.h>

using namespace v8;
using namespace node;

Handle<Value> Method(const Arguments& args) {
    HandleScope scope;
    
    int args_length = args.Length();
    
    if (args_length != 2 && args_length != 3) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    
    if (!args[0]->IsInt32() || !args[1]->IsInt32()) {
        ThrowException(Exception::TypeError(String::New("Wrong argument types")));
        return scope.Close(Undefined());
    }
    
    int d = args[0]->Int32Value();
    int request = args[1]->Int32Value();
    int ret;
    
    if (args_length == 2) {
        ret = ioctl(d, request);
    } else {
        if (Buffer::HasInstance(args[2])) {
            char *argp = Buffer::Data(args[2]->ToObject());
            ret = ioctl(d, request, argp);
        } else if (args[2]->IsInt32()) {
            int arg = args[2]->Int32Value();
            ret = ioctl(d, request, arg);
        } else {
            ThrowException(Exception::TypeError(String::New("Wrong argument types")));
            return scope.Close(Undefined());
        }        
    }
    
    if (ret < 0)
        ret = -errno;

    return scope.Close(Number::New(ret));
}

void init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("LLioctl"),
            FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(LLioctl, init)
