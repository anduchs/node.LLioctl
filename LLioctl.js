module.exports = require('./build/Release/LLioctl.node').LLioctl;

//To be used with "strace -e open -e ioctl node" or something similar...
var test = function() {
    fs = require("fs");
    LLioctl = require('./LLioctl');

    file = fs.openSync("/dev/uinput", "r")
    LLioctl(file,1,1)
}
