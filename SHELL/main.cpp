#define SDL_MAIN_HANDLED
#include "gui.h"
#include "shell.h"

int main() {
    if (!init_gui()) return -1;

    Shell shell;
    run_gui(shell);

    cleanup_gui();
    return 0;
}
