objects = main.o cache.o config.o


all: $(objects)
	cc -o simucache $(objects)

main.o: main.c  src/config.h src/cache.h 
	cc -c main.c 

cache.o: functions/cache.c src/config.h src/cache.h 
	cc -c functions/cache.c 

config.o: functions/config.c src/config.h
	cc -c functions/config.c

clean:
	rm all $(objects)\
	//del /f /q *.o *.exe