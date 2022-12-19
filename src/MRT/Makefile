CC = gcc
FILE = mrtest.c

all: mrtest

mrtest: mrtest.o
	$(CC) -o mrtest mrtest.o

mrtest.o: $(FILE)
	$(CC) -c $(FILE)

smallprimes: mrtest
	./mrtest 3
	./mrtest 5
	./mrtest 7
	./mrtest 11
	./mrtest 13
	./mrtest 17
	./mrtest 19
	./mrtest 23
	./mrtest 29
	./mrtest 31
	./mrtest 37
	./mrtest 41
	./mrtest 43
	./mrtest 47
	./mrtest 53
	./mrtest 59
	./mrtest 61
	./mrtest 67
	./mrtest 71
	./mrtest 73
	./mrtest 79
	./mrtest 83
	./mrtest 89
	./mrtest 97
	./mrtest 101
	./mrtest 103
	./mrtest 107
	./mrtest 109
	./mrtest 113
	./mrtest 127
	./mrtest 131
	./mrtest 137
	./mrtest 139
	./mrtest 149
	./mrtest 151
	./mrtest 157
	./mrtest 163
	./mrtest 167
	./mrtest 173
	./mrtest 179
	./mrtest 181
	./mrtest 191
	./mrtest 193
	./mrtest 197
	./mrtest 199
	./mrtest 211
	./mrtest 223
	./mrtest 227
	./mrtest 229

largerprimes: mrtest
	./mrtest 1117
	./mrtest 1567
	./mrtest 1979
	./mrtest 2039

smallcomposites: mrtest
	./mrtest 9
	./mrtest 15
	./mrtest 21
	./mrtest 25
	./mrtest 27
	./mrtest 33
	./mrtest 35
	./mrtest 39
	./mrtest 45
	./mrtest 49

largercomposites: mrtest
	./mrtest 555
	./mrtest 999
	./mrtest 1111
	./mrtest 2001

clean:
	rm mrtest mrtest.o
