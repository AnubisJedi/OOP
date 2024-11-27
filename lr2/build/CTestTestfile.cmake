# CMake generated Testfile for 
# Source directory: /workspaces/OOP/lr2 - copy
# Build directory: /workspaces/OOP/lr2 - copy/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyProjectTests "/workspaces/OOP/lr2 - copy/build/tests")
set_tests_properties(MyProjectTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/OOP/lr2 - copy/CMakeLists.txt;35;add_test;/workspaces/OOP/lr2 - copy/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
