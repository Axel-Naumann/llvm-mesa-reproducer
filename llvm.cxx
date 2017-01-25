#include <iostream>
namespace llvm {
namespace cl {
   class Option {};
   int AddLiteralOption(llvm::cl::Option&, char const*) {
      std::cerr << "This symbol should be called!\n";
      return 42;
   }
}
}

llvm::cl::Option dummyOpt;
int StaticInit = llvm::cl::AddLiteralOption(dummyOpt, "");
