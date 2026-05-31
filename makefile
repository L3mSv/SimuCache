objects = cache_simulator.o cache.o config.o utils.o


all: $(objects)
	cc -o all $(objects)

cache_simulator.o: config/config.h cache/cache.h utils/utils.h
cache.o: config/config.h cache/cache.h 
config.o: config/config.h


clean:
	rm all $(objects)\
	//del /f /q *.o *.exe