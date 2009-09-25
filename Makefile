# Toggle the following line/comment under windows
LIBS =  -lglut -lGLU -lGL -lGLEW -lm
#LIBS =  -lglut32 -lGLU32 -lopengl32 -lglew32 -lm

CFLAGS = -Wall -O3 -mfpmath=sse -msse2 #-march=native -mtune=native
CXXFLAGS = -Wall -O3 -mfpmath=sse -msse2 #-march=native -mtune=native
CPPFLAGS = -I$(INCDIR) -I/include -I.
LDFLAGS = -L/usr/X11R6/lib -L/lib
LDLIBS = $(LIBS)  
CC = g++
CPP = g++

CIBLE = Main
SRCS =  Camera.cpp Main.cpp Shader.cpp Vertex.cpp Triangle.cpp Mesh.cpp 


OBJS = $(SRCS:.cpp=.o)   


$(CIBLE): $(OBJS)

install:  $(CIBLE)
	cp $(CIBLE) $(BINDIR)/

installdirs:
	test -d $(INCDIR) || mkdir $(INCDIR)
	test -d $(LIBDIR) || mkdir $(LIBDIR)
	test -d $(BINDIR) || mkdir $(BINDIR)

clean:
	rm -f  *~  $(CIBLE) $(OBJS)

veryclean: clean
	rm -f $(BINDIR)/$(CIBLE)

dep:
	gcc $(CPPFLAGS) -MM $(SRCS)

# Dependencies
Camera.o: Camera.cpp Camera.h Vec3D.h
Mesh.o: Mesh.cpp Mesh.h Vertex.h Vec3D.h Triangle.h Edge.h
Main.o: Main.cpp Shader.h Vec3D.h Vertex.h \
  Triangle.h Mesh.h Edge.h Camera.h	
Triangle.o: Triangle.cpp Triangle.h
Vertex.o: Vertex.cpp Vertex.h Vec3D.h
