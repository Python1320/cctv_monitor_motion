# CCTV monitor on demand

Purpose: Makes a Linux CCTV monitor turn off even in fullscreen (you should also kill the program to save on CPU) and wakes the screen on motion detected with a PIR sensor

![architecture.drawio.svg](architecture.drawio.svg)

## Installation (WIP)


*Arduino:*
 - Install Arduino IDE or VSCode platform.io
 - Upload
 - Solder to P2 a PIR
 - Connect to PC for fake keyboard
 
*Force close monitor daemon:* 

```bash
make
make install
```

## Alternatives
 - xprintidle and some bash

## Misc

```bash
#!/bin/bash
while true;do

        mpv --no-terminal --really-quiet --loop-playlist=force --loop --profile=low-latency -hwdec=vaapi --stop-screensaver=no "$HOME/.config/cams.m3u"
        echo restarting
        sleep 5
done

```
