LOPTS = /opt:nowin98 /stack:100000000
COPTS = /Ox /O2 /Gs /G6
LIBS = user32.lib gdi32.lib

.exe: m3d2d.obj
	link m3d2d.obj $(LIBS) $(LOPTS)

m3d2d.obj: m3d2d.c
	cl /c m3d2d.c $(COPTS)

clean:
	del *.obj