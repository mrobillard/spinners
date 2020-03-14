#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <wchar.h>
#include <locale.h>

void int_handler(int signal) {
	printf("\e[?25h\n");
	exit(signal);
}



// static char bars[] = { '⣾', '⣽', '⣻', '⢿', '⡿', '⣟', '⣯', '⣷' };

int main() {
	printf("\e[?25l");
	//printf("\e[?25h");
	(void) signal(SIGINT, int_handler);

	setlocale(LC_CTYPE, "");
    
    wchar_t dots = 0x28FE;
    wchar_t dots2 = 0x28FF;
    
    wprintf(L"%lc", dots2);
    sleep(1);
    wprintf(L"\b%lc", dots);

    printf("\e[?25h\n");
    return 0;
}
