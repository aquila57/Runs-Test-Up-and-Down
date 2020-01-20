/* runsa.h - Runs Test Up and Down, header file  Version 0.1.0 */
/* Copyright (C) 2019 aquila57 at github.com */

/* This program is free software; you can redistribute it and/or     */
/* modify it under the terms of the GNU General Public License as    */
/* published by the Free Software Foundation; either version 2 of    */
/* the License, or (at your option) any later version.               */

/* This program is distributed in the hope that it will be useful,   */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of    */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the      */
/* GNU General Public License for more details.                      */

/* You should have received a copy of the GNU General Public License */
/* along with this program; if not, write to:                        */

   /* Free Software Foundation, Inc.                                 */
   /* 59 Temple Place - Suite 330                                    */
   /* Boston, MA 02111-1307, USA.                                    */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_sf_erf.h>
#include <gsl/gsl_rng.h>
#include "eegl.h"
#include "etaus.h"

#define SMPLS (10000000)

#define BITS (32)

/* getdie() end of file return code */

#define EOFDIE (-999999999.0)

#define UP 1
#define DOWN 0

typedef struct xxstruct {
   char *rngname;
   char dieharder_rngname[128];
   char rngtbl[1000][64];
   int run_direction;
   int run_len;
   int generator;
   int eofsw;
   unsigned int fibonum1;
   unsigned int fibonum2;
   unsigned int fibonum3;
   unsigned int lfsr0;
   unsigned int lfsr;
   unsigned int major;
   unsigned int minor;
   unsigned int lowbit;
   unsigned int out;
   unsigned int seed;
   unsigned int maxint;
   unsigned int int_slots;
   double slots;
   double count;
   double dblsmpls;
   double modulus;
   double prev_smpl;
   double curr_smpl;
   double tot_up_len;
   double tot_down_len;
   double tot_len;
   double tot_up_runs;
   double tot_down_runs;
   double tot_runs;
   double avg_up_len;
   double avg_down_len;
   double avg_len;
   double maxint_tbl[2048];
   double *smpl_p;
   double *smpl_q;
   double *smpls;
   double *tally;
   double *up_tally;
   double *down_tally;
   double *len_tally;
   eefmt *ee;
   etfmt *et;
   gsl_rng_type *gsltype;
   gsl_rng *rng;
   } xxfmt;

void start_rng(xxfmt *xx);

double gen_dbl(xxfmt *xx);

void gen_curr_smpl(xxfmt *xx);

void bld_frst_run(xxfmt *xx);

void bld_curr_smpl(xxfmt *xx);

void add_both_tallies(xxfmt *xx);

void bldsmpls(xxfmt *xx);

void calc_zedzero(xxfmt *xx);

void calcchi_up(xxfmt *xx);

double calc_exp_up(int indx, double N);

double permute(int index);

void freeall(xxfmt *xx);
