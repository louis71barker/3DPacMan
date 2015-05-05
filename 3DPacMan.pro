isEqual(QT_MAJOR_VERSION, 5) {cache() }
TARGET=PacMan3D
cache()
SOURCES+=src/main.cpp \
         src/ghost.cpp \
         src/arena.cpp \
         src/collectables.cpp \
         src/window.cpp \
         src/camera.cpp \
         src/walls.cpp \
         src/Vec.cpp \
         src/objLoader.cpp \
         src/TextLoader.cpp \
         src/fileLoader.cpp \
         src/barn.cpp \
         src/fence.cpp \
         src/lightning.cpp \
         src/helicopter.cpp \
         src/geoDome.cpp \
         src/audio.cpp \


HEADERS+=header/arena.h \
         header/collectables.h \
         header/ghost.h \
         header/window.h \
         header/camera.h \
         header/walls.h \
         header/scene.h \
         header/barn.h \
         header/fence.h \
         header/lightning.h \
         header/helicopter.h \
         header/FPSCounter.h \
         header/geoDome.h \
         header/audio.h \

OTHER_FILES+= src/MapCoor.txt\
              obj/GhostObj.obj\
              obj/CherryObj.obj \
              obj/OBJ_Ground.obj \
              obj/geoSphere.obj \
              obj/Helicopter_crashed.obj \
              obj/NewTriBush.obj \
              obj/FarmhouseTriMedHighpoly.obj \
              textures/Ground.png \
              textures/NewTreesTextureMap.png \
              textures/Skydome.png \
              textures/BarnTextures/Farmhouse_Diffuse_Map.jpg \
              textures/GroundTextures/Diffuse.jpg \
              textures/HelicopterTextures/Helicopter_Crash_D.png \
              textures/oldFence_texture.jpg \



QT += core
QT -= opengl
CONFIG-=app_bundle
DESTDIR=./
OBJECTS_DIR=buildFiles

INCLUDEPATH += header
INCLUDEPATH += header/NCCA
INCLUDEPATH += usr/local/lib

QMAKE_CXXFLAGS+= -msse -msse2 -msse3
macx:QMAKE_CXXFLAGS+= -arch x86_64
linux-g++:QMAKE_CXXFLAGS +=  -march=native
linux-g++-64:QMAKE_CXXFLAGS +=  -march=native

QMAKE_CXXFLAGS+=$$system(sdl2-config  --cflags)
message(output from sdl2-config --cflags added to CXXFLAGS= $$QMAKE_CXXFLAGS)

LIBS += -lglut -lGLU -lSDL2_image -lSDL2_mixer

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
