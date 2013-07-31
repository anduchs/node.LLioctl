node.LLioctl
============

Some low-level bindings for making ioctl-calls from node.js.

Disclaimer
----------

- I use int32s since I want to be able to use this for all kinds of ioctls.
- I provide no callback, since I don't provide an async function, so no need.
- Return values can carry return values on some ioctls, not just errors.

Building
--------

node-gyp build

(to get node-gyp in Ubuntu: ln -s nodejs /usr/bin/node; npm install -g node-gyp; node-gyp configure)
