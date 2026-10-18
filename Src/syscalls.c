#include <sys/stat.h>
#include <errno.h>

#undef errno
extern int errno;

int _close(int file) {
    return -1;
}

int _fstat(int file, struct stat *st) {
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file) {
    return 1;
}

int _lseek(int file, int ptr, int dir) {
    return 0;
}

int _read(int file, char *ptr, int len) {
    // Implement UART receive logic here if standard input is needed
    return 0;
}

int _write(int file, char *ptr, int len) {
    // Implement UART transmit logic here (e.g., HAL_UART_Transmit or ITM_SendChar)
    // For now, return bytes processed:
    return len;
}
