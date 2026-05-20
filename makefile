objects = main.o cache.o config.o


all: $(objects)
	cc -o all $(objects)

main.o: main.c  config.h cache.h 
	cc -c main.c 

cache.o: cache.c config.h cache.h 
	cc -c cache.c 

config.o: config.c config.h
	cc -c config.c

clean:
	rm all $(objects)\
	del /f /q *.o *.exe
