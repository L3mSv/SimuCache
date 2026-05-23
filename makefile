objects = cache_simulator.o cache.o config.o


all: $(objects)
	cc -o simucache $(objects)

cache_simulator.o: cache_simulator.c  src/config.h src/cache.h 
	cc -c cache_simulator.c 

cache.o: functions/cache.c src/config.h src/cache.h 
	cc -c functions/cache.c 

config.o: functions/config.c src/config.h
	cc -c functions/config.c

clean:
	rm all $(objects)\
	//del /f /q *.o *.exe