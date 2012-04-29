google-protocol-buffers-patches
===============================

This repository contains patches implementing new functionality for Google&#39;s protocol buffers. For more information on Google protocol buffers, see https://developers.google.com/protocol-buffers/.

To use any of the patches, simply apply them on top of a plain Google protocol buffer installation with the UNIX 'patch' command.

protobuf-2.4.1-camelcase-support.diff
-------------------------------------

This patch introduces a new command line option for the protoc compiler. When a .proto file is being compiled with '--cpp-out=user_lower_case=false:OUT_DIR', the generated C++ files will not convert CamelCase field names into lowercase. The automatic conversion to lowercase is mandated by Google due to their internal coding standards, but an unnecessary restriction for other projects.

The patch also refactors C++ option handling so that implementing new options is considerably easier. Finally, a unit test is provided to verify that the code generation works as expected.


