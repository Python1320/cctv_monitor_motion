LDLIBS=-lX11 -lXss

all: dpms_idle_forcer

dpms_idle_forcer: dpms_idle_forcer.o

clean:
	rm -f dpms_idle_forcer dpms_idle_forcer.o

install:
	echo Copying to ~/.config/autostart
	cp dpms_idle_forcer.desktop ~/.config/autostart/
	mkdir -p "$HOME/.local/bin"
	cp dpms_idle_forcer "$HOME/.local/bin"

uninstall:
	rm ~/.config/autostart/dpms_idle_forcer.desktop
	mkdir "$HOME/.local/bin"
	rm "$HOME/.local/bin/dpms_idle_forcer"

.PHONY: all clean
