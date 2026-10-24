#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int console = open("/dev/console", O_RDWR);

    if (console >= 0) {
        dup2(console, STDIN_FILENO);
        dup2(console, STDOUT_FILENO);
        dup2(console, STDERR_FILENO);

        if (console > STDERR_FILENO)
            close(console);
    }

    write(STDOUT_FILENO,
          "\nWelcome to My Linux OS!\n"
          "Kernel booted successfully.\n"
          "PID 1 is running from my initramfs.\n\n",
          88);

    for (;;)
        pause();

    return 0;
}
