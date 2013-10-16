node.LLioctl
============

Some low-level bindings for making ioctl-calls from node.js.

Disclaimer
----------

- I'm an absolute newbie to node, node-gyp and npm, so this may be full of flaws. Feel invited to provide pull requests...

- I use int32s since I want to be able to use this for all kinds of ioctls.
- I provide no callback, since I don't provide an async function, so no need.
- Return values can carry return values on some ioctls, not just errors.

Building
--------

Just get npm and run:
npm install

(you might need to symlink nodejs to node)
