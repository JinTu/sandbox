# Copyright 2012 lynix <lynix47@gmail.com>
#
# This file is part of aerotools-ng.
#
# aerotools-ng is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# aerotools-ng is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with aerotools-ng. If not, see <http://www.gnu.org/licenses/>.

CC = gcc
CFLAGS = -Wall -ansi -std=gnu99 -pedantic -I /usr/include -O2

ifdef DEBUG  
	CFLAGS += -g
endif


all : hiddev/bin/test hidraw/bin/hid-example

hiddev/bin/test: hiddev/obj/test.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	
hiddev/obj/test.o: hiddev/src/test.c hiddev/src/test.h
	$(CC) $(CFLAGS) -o $@ -c $<

hidraw/bin/hid-example: hidraw/obj/hid-example.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	
hidraw/obj/hid-example.o: hidraw/src/hid-example.c
	$(CC) $(CFLAGS) -o $@ -c $<
	

clean :
	rm -f hidraw/bin/hid-example hiddev/bin/test hiddev/obj/*.o hidraw/obj/*.o
