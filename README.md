Stanford CS 144 Networking Lab
==============================

These labs are open to the public under the (friendly) request that to
preserve their value as a teaching tool, solutions not be posted
publicly by anybody.

Website: https://cs144.stanford.edu

To set up the build system: `cmake -S . -B build`

To compile: `cmake --build build`

To run tests: `cmake --build build --target test`

To run speed benchmarks: `cmake --build build --target speed`

To run clang-tidy (which suggests improvements): `cmake --build build --target tidy`

To format code: `cmake --build build --target format`

check /src/reassembler.cc for the implementation of the reassembler

check /src/tcp_receiver.cc & /src/tcp_sender.cc for the implementation of the receiver & sender

check /src/network_interface.cc for the implementation of the network interface

check /src/router.cc for the implementation of the router

