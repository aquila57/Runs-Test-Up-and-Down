#  libruns.mak - Compile runsa subroutine library  Version 0.1.0
#  Copyright (C) 2020 aquila57 at github.com

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

# Compile subroutine library for the runs up and down test

OBJ=add_both_tallies.o \
	bld_curr_smpl.o \
	bld_frst_run.o \
	bld_maxint.o \
	bld_rngtbl.o \
	bldsmpls.o \
	calcchi_up.o \
	calc_exp_up.o \
	calc_zedzero.o \
	eeglabt.o \
	eeglbit.o \
	eegl.o \
	eeglcrc.o \
	eegldspl.o \
	eeglfrac.o \
	eeglinit.o \
	eeglint.o \
	eeglpwr.o \
	eeglsd.o \
	eeglstrt.o \
	eeglunif.o \
	etausabt.o \
	etausbit.o \
	etaus.o \
	etausdspl.o \
	etausfrac.o \
	etausinit.o \
	etausint.o \
	etauspwr.o \
	etausstrt.o \
	etausunif.o \
	freeall.o \
	gen_curr_smpl.o \
	getbyte.o \
	getdie.o \
	permute.o \
	shwsmpls.o

CC=gcc

CFLAGS=-c -Wall -O2

LDFLAGS=-lgsl -lgslcblas -lm

libruns.a:			$(OBJ)
		rm -f libruns.a
		ar r libruns.a $(OBJ)

add_both_tallies.o:			add_both_tallies.c
		$(CC) $(CFLAGS) add_both_tallies.c

bld_curr_smpl.o:		bld_curr_smpl.c
		$(CC) $(CFLAGS) bld_curr_smpl.c

bld_frst_run.o:			bld_frst_run.c
		$(CC) $(CFLAGS) bld_frst_run.c

bld_maxint.o:			bld_maxint.c
		$(CC) $(CFLAGS) bld_maxint.c

bld_rngtbl.o:			bld_rngtbl.c
		$(CC) $(CFLAGS) bld_rngtbl.c

bldsmpls.o:			bldsmpls.c
		$(CC) $(CFLAGS) bldsmpls.c

calcchi_up.o:			calcchi_up.c
		$(CC) $(CFLAGS) calcchi_up.c

calc_exp_up.o:			calc_exp_up.c
		$(CC) $(CFLAGS) calc_exp_up.c

calc_zedzero.o:			calc_zedzero.c
		$(CC) $(CFLAGS) calc_zedzero.c

eeglabt.o:			eeglabt.c
		$(CC) $(CFLAGS) eeglabt.c

eeglbit.o:			eeglbit.c
		$(CC) $(CFLAGS) eeglbit.c

eegl.o:				eegl.c
		$(CC) $(CFLAGS) eegl.c

eeglcrc.o:			eeglcrc.c
		$(CC) $(CFLAGS) eeglcrc.c

eegldspl.o:			eegldspl.c
		$(CC) $(CFLAGS) eegldspl.c

eeglfrac.o:			eeglfrac.c
		$(CC) $(CFLAGS) eeglfrac.c

eeglinit.o:			eeglinit.c
		$(CC) $(CFLAGS) eeglinit.c

eeglint.o:			eeglint.c
		$(CC) $(CFLAGS) eeglint.c

eeglpwr.o:			eeglpwr.c
		$(CC) $(CFLAGS) eeglpwr.c

eeglsd.o:			eeglsd.c
		$(CC) $(CFLAGS) eeglsd.c

eeglstrt.o:			eeglstrt.c
		$(CC) $(CFLAGS) eeglstrt.c

eeglunif.o:			eeglunif.c
		$(CC) $(CFLAGS) eeglunif.c

etausabt.o:			etausabt.c
		$(CC) $(CFLAGS) etausabt.c

etausbit.o:			etausbit.c
		$(CC) $(CFLAGS) etausbit.c

etaus.o:			etaus.c
		$(CC) $(CFLAGS) etaus.c

etausdspl.o:			etausdspl.c
		$(CC) $(CFLAGS) etausdspl.c

etausfrac.o:			etausfrac.c
		$(CC) $(CFLAGS) etausfrac.c

etausinit.o:			etausinit.c
		$(CC) $(CFLAGS) etausinit.c

etausint.o:			etausint.c
		$(CC) $(CFLAGS) etausint.c

etauspwr.o:			etauspwr.c
		$(CC) $(CFLAGS) etauspwr.c

etausstrt.o:			etausstrt.c
		$(CC) $(CFLAGS) etausstrt.c

etausunif.o:			etausunif.c
		$(CC) $(CFLAGS) etausunif.c

freeall.o:			freeall.c
		$(CC) $(CFLAGS) freeall.c

gen_curr_smpl.o:		gen_curr_smpl.c
		$(CC) $(CFLAGS) gen_curr_smpl.c

getbyte.o:			getbyte.c
		$(CC) $(CFLAGS) getbyte.c

getdie.o:			getdie.c
		$(CC) $(CFLAGS) getdie.c

permute.o:			permute.c
		$(CC) $(CFLAGS) permute.c

shwsmpls.o:			shwsmpls.c
		$(CC) $(CFLAGS) shwsmpls.c

clean:
		rm -f $(OBJ) libruns.a
