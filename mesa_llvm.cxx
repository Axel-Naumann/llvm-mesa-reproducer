#include <dlfcn.h> // for dlopen()
#include <X11/Xlib.h> // for XOpenDisplay()
#include <iostream> // for errors
#include <stdlib.h> // for exit()
#include <GL/glx.h>

void dlopenMyLLVM() {
   if (!dlopen("./libpseudollvm.so", RTLD_LAZY|RTLD_LOCAL)) {
      std::cerr << "This should have actually worked. dlopen says: "
                << dlerror() << '\n';
      exit(1);
   }
}

//struct XVisualInfo;
//extern "C" XVisualInfo* glXChooseVisual(Display * dpy, int screen, int * attribList);

void initGL() {
   const int dblBuff[] =
   {
      GLX_DOUBLEBUFFER,
      GLX_RGBA,
      GLX_DEPTH_SIZE, 16,
      GLX_STENCIL_SIZE, 8,
      GLX_RED_SIZE, 1,
      GLX_GREEN_SIZE, 1,
      GLX_BLUE_SIZE, 1,
      None
   };

   // Now initialize GL:
   Display* display = XOpenDisplay("");
   auto ret = glXChooseVisual(display, DefaultScreen(display), const_cast<int *>(dblBuff));
   if (!ret) {
     std::cerr << "glXChooseVisual - that's not supposed to happen.\n";
   }
}

int main() {
   initGL();
   dlopenMyLLVM();
   return 0;
}
