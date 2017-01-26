#include <iostream>
#include <cassert>

namespace llvm {
namespace cl {
   class Option {};
   int AddLiteralOption(llvm::cl::Option&, char const*) {
      std::cerr << "This symbol should be called!\n";
      return 42;
   }
}
}

int StaticInit() {
   llvm::cl::Option dummyOpt;
   int Val = llvm::cl::AddLiteralOption(dummyOpt, "");
   assert(Val == 42 && "WRONG SYMBOL CALLED!");
   return 0;
}

int triggerStaticInit = StaticInit();
