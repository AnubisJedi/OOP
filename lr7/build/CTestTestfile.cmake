# CMake generated Testfile for 
# Source directory: /workspaces/OOP/lr7
# Build directory: /workspaces/OOP/lr7/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyProjectTests "/workspaces/OOP/lr7/build/tests")
set_tests_properties(MyProjectTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/OOP/lr7/CMakeLists.txt;111;add_test;/workspaces/OOP/lr7/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
