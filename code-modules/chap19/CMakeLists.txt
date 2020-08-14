example(list1901)
add_executable(snip1901 snip1901.cc)
target_compile_options(snip1901 PUBLIC "$<$<CXX_COMPILER_ID:AppleClang,ArmClang,Clang,XLClang>:-Wno-invalid-source-encoding>")
