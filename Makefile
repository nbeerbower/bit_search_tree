# Included needed libraries
LIBS = 

# Language features (C99 etc.)
#CFLAGS += -std=c99 -D_DEFAULT_SOURCE

# Warning and error settings
#CFLAGS += -Wall -Wextra
#CFLAGS += -Werror -Wno-error=sign-compare -Wno-error=unused-function -Wno-error=unused-label -Wno-error=unused-parameter -Wno-error=unused-variable

# Debugging information
#CFLAGS += -g

### File lists
BINS = bit_search_tree
OBJS = bit_search_tree.o


### Phony targets all/clean
.PHONY: all clean

all: $(BINS)

clean:
	$(RM) $(BINS) $(OBJS)


### Build rules

# Be sure to link in the library
$(BINS): $(OBJS) $(LIBS)

# Add header file dependencies
bit_search_tree.o: bit_search_tree.h
