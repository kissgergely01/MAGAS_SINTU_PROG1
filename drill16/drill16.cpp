#include "../GUI/Lines_window.h"
#include "../GUI/Graph.h"

int main()
try {
    Lines_window win {Point{100,100},600,400,"Lines"};
    return gui_main();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}
