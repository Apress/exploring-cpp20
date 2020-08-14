example(list1201)
example(list1202 "$<$<CXX_COMPILER_ID:AppleClang,ArmClang,Clang,XLClang>:-Wno-literal-conversion>")
example(list1204)
example(list1205)
example(list1206)
example(snip1201 snip1201.hh)
example(snip1202 snip1202.hh)
example(snip1203 snip1203.hh
	"$<$<CXX_COMPILER_ID:MSVC>:/w45056>"
	"$<$<CXX_COMPILER_ID:AppleClang,ArmClang,Clang,XLClang>:-Wno-deprecated-array-compare -Wno-string-compare>")
