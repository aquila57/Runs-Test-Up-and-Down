#  runsdie.mak - Compile runsdie.c Version 0.1.0
#  Copyright (C) 2019 aquila57 at github.com

#  This program is free software; you can redistribute it and/or
#  modify it under the terms of the GNU General Public License as
#  published by the Free Software Foundation; either version 2 of
#  the License, or (at your option) any later version.

#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU General Public License for more details.

#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to:

   #  Free Software Foundation, Inc.
   #  59 Temple Place - Suite 330
   #  Boston, MA 02111-1307, USA.

#--------------------------------------------------------
# The LFSR in this generator comes from the following
# http://courses.cse.tamu.edu/walker/csce680/
# lfsr_table.pdf
# 64 bit LFSR is 64,63,61,60 with low order bit equal
# to 64
#--------------------------------------------------------

OBJ=runsdie.o \
	bld_rngtbl.o \
	bld_maxint.o \
	getbyte.o \
	getdie.o \
	gen_curr_smpl.o \
	bld_frst_run.o \
	bld_curr_smpl.o \
	add_both_tallies.o \
	bldsmpls.o \
	calc_zedzero.o \
	calcchi_up.o \
	calc_exp_up.o \
	permute.o \
	freeall.o \
	eeglinit.o \
	eegl.o \
	eeglunif.o

CC=gcc

CFLAGS=-c -Wall -O2

LDFLAGS=-lgsl -lgslcblas -lm

runsdie:			$(OBJ)
		$(CC) -Wall -O2 $(OBJ) -o runsdie $(LDFLAGS)

runsdie.o:			runsdie.c
		$(CC) $(CFLAGS) runsdie.c

bld_rngtbl.o:			bld_rngtbl.c
		$(CC) $(CFLAGS) bld_rngtbl.c

bld_maxint.o:			bld_maxint.c
		$(CC) $(CFLAGS) bld_maxint.c

getbyte.o:			getbyte.c
		$(CC) $(CFLAGS) getbyte.c

getdie.o:			getdie.c
		$(CC) $(CFLAGS) getdie.c

gen_curr_smpl.o:		gen_curr_smpl.c
		$(CC) $(CFLAGS) gen_curr_smpl.c

bld_frst_run.o:			bld_frst_run.c
		$(CC) $(CFLAGS) bld_frst_run.c

bld_curr_smpl.o:		bld_curr_smpl.c
		$(CC) $(CFLAGS) bld_curr_smpl.c

add_both_tallies.o:		add_both_tallies.c
		$(CC) $(CFLAGS) add_both_tallies.c

bldsmpls.o:			bldsmpls.c
		$(CC) $(CFLAGS) bldsmpls.c

calc_zedzero.o:			calc_zedzero.c
		$(CC) $(CFLAGS) calc_zedzero.c

calcchi_up.o:			calcchi_up.c
		$(CC) $(CFLAGS) calcchi_up.c

calc_exp_up.o:			calc_exp_up.c
		$(CC) $(CFLAGS) calc_exp_up.c

permute.o:			permute.c
		$(CC) $(CFLAGS) permute.c

freeall.o:			freeall.c
		$(CC) $(CFLAGS) freeall.c

eeglinit.o:			eeglinit.c
		$(CC) $(CFLAGS) eeglinit.c

eegl.o:				eegl.c
		$(CC) $(CFLAGS) eegl.c

eeglunif.o:			eeglunif.c
		$(CC) $(CFLAGS) eeglunif.c

clean:
		rm -f $(OBJ) runsdie