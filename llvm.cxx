#include <iostream>
namespace llvm {
namespace cl {
   class Option {};
   void AddLiteralOption(llvm::cl::Option&, char const*) {
      std::cerr << "ERROR: THIS MUST NOT BE CALLED!\n";
      std::cerr << "I.e. if you see this then you can reproduce the problem.\n";
   }
}
}

