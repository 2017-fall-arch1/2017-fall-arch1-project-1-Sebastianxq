all: llDemo

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

lab1: llist.o lab1.o
	cc -o $@ $^

llDemo: llist.o llDemo.o
	cc -o $@ $^

llist.o: llist.c llist.h
	cc -c $(CFLAGS) llist.c

llDemo.o: llDemo.c llist.h
	cc -c $(CFLAGS) llDemo.c

clean:
	rm -f *.o llDemo

demo: llDemo
	(echo first; echo "second line"; echo "third and last") | ./llDemo

lab: lab1
	#(echo "test") | ./lab1
	./lab1
