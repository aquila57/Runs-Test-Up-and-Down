#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_sf_erf.h>
#include <gsl/gsl_rng.h>
#include "eegl.h"

#define SMPLS (10000000)

#define UP 1
#define DOWN 0

typedef struct xxstruct {
   char *rngname;
   int run_direction;
   int run_len;
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
   double *smpl_p;
   double *smpl_q;
   double *smpls;
   double *up_tally;
   double *down_tally;
   double *len_tally;
   eefmt *ee;
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
