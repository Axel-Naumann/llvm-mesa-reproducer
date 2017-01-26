#include <iostream>
#include <stddef.h>

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
   if (Val != 42) {
      std::cerr << "WRONG SYMBOL CALLED!\n";
      exit(1);
   }
   return 0;
}

int triggerStaticInit = StaticInit();
