#include <X11/extensions/scrnsaver.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
        char *pend;
        time_t t;
        float idle_length = 10;
        char *ctime_no_newline;

        errno = 0;
        if (argc > 1 && strlen(argv[1]) > 0)
        {

                idle_length = strtof(argv[1], &pend);
                if (errno != 0 || *pend != '\0' || idle_length > 65535.0f || idle_length < 5.0f)
                {
                        return 2;
                }
        }
        else
        {
                printf("Usage: %s [idle delay in seconds > 5s]\n", argv[0]);
        }
        printf("Delay: %.1fs\n", idle_length);

        bool turned_off = 0;
        Display *display = XOpenDisplay(0);

        if (display == 0)
        {
                return 1;
        }

        XScreenSaverInfo *info = XScreenSaverAllocInfo();
        if (!info)
                return 3;
        while (1)
        {
                sleep(1);
                XScreenSaverQueryInfo(display, DefaultRootWindow(display), info);

                if ((((float)(info->idle)) * 0.001f) > (unsigned long)(idle_length) && !turned_off)
                {
                        turned_off = 1;
                        time(&t);
                        system("xset dpms force off");
                        ctime_no_newline = strtok(ctime(&t), "\n");
                        printf("%s Forcing off after idling %.1f seconds\n", ctime_no_newline, ((float)(info->idle)) * 0.001f);
                }
                else if (turned_off && info->idle < 3000)
                {
                        turned_off = 0;
                }
        }
        XFree(info);

        return 0;
}
