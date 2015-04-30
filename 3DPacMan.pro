isEqual(QT_MAJOR_VERSION, 5) {cache() }
TARGET=PacMan3D
cache()
SOURCES+=src/main.cpp \
         src/player.cpp \
         src/ghost.cpp \
         src/arena.cpp \
         src/collectables.cpp \
         src/window.cpp \
         src/camera.cpp \
         src/walls.cpp \
         src/torch.cpp \
         src/Vec.cpp \
         src/objLoader.cpp \
         src/lighting.cpp \
         src/TextLoader.cpp \
         src/fileLoader.cpp \
         src/skyDome.cpp \
         src/barn.cpp \
         src/fence.cpp \
         src/lightning.cpp \
         src/helicopter.cpp \
         src/FPSCounter.cpp \
#         src/NCCA/Mat4.cpp\
#         src/NCCA/Vec4.cpp\
#         src/NCCA/GLFunctions.cpp


HEADERS+=header/arena.h \
         header/collectables.h \
         header/player.h \
         header/ghost.h \
         header/window.h \
         header/camera.h \
         header/walls.h \
         header/torch.h \
         header/scene.h \
         header/lights.h \
         header/skyDome.h \
         header/barn.h \
         header/fence.h \
         header/lightning.h \
         header/helicopter.h \
         header/FPSCounter.h \
#         header/NCCA/Mat4.h\
#         header/NCCA/Vec4.h\
#         header/NCCA/GLFunctions.h

OTHER_FILES+= src/MapCoor.txt\
              obj/GhostObj.obj\
              obj/CherryObj.obj \
              obj/cubeTri.obj \
              obj/cubeSquared.obj \
              obj/01_Wall_Crack.obj \
              obj/02_Wall_Shelf.obj \
              obj/03_Wall_Hypnotic.obj \
              obj/04_Wall_Boiler.obj \
              obj/crackedWall.obj \
              obj/cubeBoiler.obj \
              obj/cubeHypno.obj \
              obj/cubeWindow.obj \
              obj/stripLight.obj \
              obj/BushWall.obj \
              obj/BushWallHighPoly.obj \
              obj/BushWallHighPolyNew.obj \
              obj/FenceFrame.obj \
              obj/OBJ_Ground.obj \
              obj/FarmhouseTri.obj \
              obj/geoSphere.obj \
              obj/Helicopter_crashed.obj \
              obj/OldFence.obj \
              textures/Ground.png \
              textures/NewTreesTextureMap.png \
              textures/Skydome.png \
              textures/BarnTextures/Farmhouse_Diffuse_Map.jpg \
              textures/BarnTextures/Farmhouse_Specular_Map.jpg \
              textures/FenceTextures/Metal_Fence_Bump_Map.png \
              textures/FenceTextures/Metal_Fence_Diffuse_01.png \
              textures/FenceTextures/Metal_Fence_Diffuse_02.png \
              textures/FenceTextures/Metal_Fence_Diffuse_03.png \
              textures/GroundTextures/Bump_Map.jpg \
              textures/GroundTextures/Diffuse.jpg \
              textures/GroundTextures/Specular.jpg \
              textures/HelicopterTextures/Helicopter_Crash_D.png \
              textures/HelicopterTextures/Helicopter_Crash_N.tga \
              textures/HelicopterTextures/Helicopter_Crash_S.tga \
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

LIBS += -lglut -lGLU -lSDL2_image

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
