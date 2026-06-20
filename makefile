CC = gcc
CFLAGS = -I. -lm
objects = cache_simulator.o cache/cache.o config/config.o utils/utils.o
all: cache_simulator

cache_simulator: $(objects)
	$(CC) -o $@ $(objects) $(CFLAGS)

cache_simulator.o: cache_simulator.c config/config.h cache/cache.h utils/utils.h
	$(CC) -c cache_simulator.c $(CFLAGS)
cache/cache.o: cache/cache.c cache/cache.h
	$(CC) -c cache/cache.c -o $@ $(CFLAGS)
config/config.o: config/config.c config/config.h
	$(CC) -c config/config.c -o $@ $(CFLAGS)
utils/utils.o: utils/utils.c utils/utils.h 
	$(CC) -c utils/utils.c -o $@ $(CFLAGS)


clean:
	rm -f cache_simulator $(objects)