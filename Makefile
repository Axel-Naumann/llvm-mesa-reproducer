ALL=mesa_llvm libpseudollvm.so

all: $(ALL)
.PHONY: all

libpseudollvm.so: llvm.cxx
	g++ -std=c++11 -shared -fPIC $< -o $@

mesa_llvm: mesa_llvm.cxx
	g++ -std=c++11 $< -o $@ -lX11 -lGL -ldl

clean:
	rm -f $(ALL)
