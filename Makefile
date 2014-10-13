BINARY=BlowUpTheBalloons
GCC=g++
CXX=$(GCC)
CXXFLAGS=-Wall
LINK=$(GCC)
LINKFLAGS=-lm -lalleg

SRCS = \
 Allegro.cpp\
 Balloon.cpp\
 Bitmap.cpp\
 BlowUpTheBalloons.cpp\
 Circle.cpp\
 Color.cpp\
 CompositeBitmap.cpp\
 CompositeSprite.cpp\
 Drawable.cpp\
 DrawablePointer.cpp\
 Ellipse.cpp\
 Font.cpp\
 GameOver.cpp\
 Kaboom.cpp\
 Keyboard.cpp\
 LevelUp.cpp\
 Line.cpp\
 Mouse.cpp\
 Pixel.cpp\
 Point.cpp\
 Polygon.cpp\
 Rectangle.cpp\
 SampleSound.cpp\
 Text.cpp\
 Triangle.cpp\
 Viewfinder.cpp\
 main.cpp\
 

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(BINARY) 
	
%.d: %.cpp
	$(CXX) $(CXXFLAGS) -M $< >$@
	
$(BINARY): $(OBJS)
	$(LINK) $(LINKFLAGS) $(LIBS) $(OBJS) -o $(BINARY)

static: $(OBJS)
	$(LINK) $(LINKFLAGS) $(LIBS) $(OBJS) -static -o $(BINARY)

########## Clean

clean:
	rm -f *.o a.out
	rm -f gmon.out

distclean: clean
	rm -f $(BINARY)
	rm -f *.d

-include $(DEPS)

