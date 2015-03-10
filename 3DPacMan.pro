isEqual(QT_MAJOR_VERSION, 5) {cache() }
TARGET=PacMan3D
cache()
SOURCES+=src/main.cpp\
         src/player.cpp\
         src/ghost.cpp\
         src/arena.cpp\
         src/collectables.cpp\
         src/window.cpp


HEADERS+=header/arena.h\
         header/collectables.h\
         header/player.h\
         header/ghost.h\
         header/window.h


QT += core
QT -= opengl
CONFIG-=app_bundle
DESTDIR=./
OBJECTS_DIR=obj

INCLUDEPATH += header
INCLUDEPATH += header/NCCA
INCLUDEPATH += usr/local/lib

QMAKE_CXXFLAGS+= -msse -msse2 -msse3
macx:QMAKE_CXXFLAGS+= -arch x86_64
linux-g++:QMAKE_CXXFLAGS +=  -march=native
linux-g++-64:QMAKE_CXXFLAGS +=  -march=native

QMAKE_CXXFLAGS+=$$system(sdl2-config  --cflags)
message(output from sdl2-config --cflags added to CXXFLAGS= $$QMAKE_CXXFLAGS)

LIBS += -lglut -lGLU

LIBS+=$$system(sdl2-config  --libs)
message(output from sdl2-config --libs added to LIB=$$LIBS)



LIBS += -L/usr/local/lib
macx:LIBS+= -framework OpenGL
macx:DEFINES+=DARWIN
# now if we are under unix and not on a Mac (i.e. linux) define GLEW
linux-* {
    DEFINES += LINUX
    LIBS+= -lGLEW
}
linux-clang {
    DEFINES += LINUX
    LIBS+= -lGLEW
}
