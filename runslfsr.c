/* runslfsr.c - Fibonacci Runs Up and Down Test  Version 0.1.0 */
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

#include "runsa.h"

#define MYLFSROUT (xx->out = (((xx->lfsr >> 4) \
   ^ (xx->lfsr >> 3) \
   ^ (xx->lfsr >> 1) \
   ^ (xx->lfsr >> 0)) & 1))

#define MYLFSRLOWBIT (xx->lowbit = xx->major & 1)

#define MYLFSRROLL (xx->lfsr0 = xx->major = \
(xx->major >> 1) | (xx->out << 31))

#define MYLFSRCARRY (xx->lfsr = xx->minor = \
(xx->minor >> 1) | (xx->lowbit << 31))

#define MYLFSR (MYLFSROUT,MYLFSRLOWBIT,MYLFSRROLL,MYLFSRCARRY)

/********************************************************/
/* Initialize the LFSR random number generator          */
/* The LFSR in this generator comes from the following  */
/* http://courses.cse.tamu.edu/walker/csce680/          */
/* lfsr_table.pdf                                       */
/* 64 bit LFSR is 64,63,61,60 with low order bit equal  */
/* to 64                                                */
/********************************************************/

void start_rng(xxfmt *xx)
   {
   xx->ee = (eefmt *) eeglinit();
   xx->lfsr0 = xx->major = eegl(xx->ee);
   xx->lfsr  = xx->minor = eegl(xx->ee);
   xx->lowbit = xx->out = 0;
   xx->modulus = 65536.0 * 65536.0;
   } /* start_rng */

/* Generate one uniform sample from zero to one */

double gen_dbl(xxfmt *xx)
   {
   double num;
   /* generate the next state in the 64 bit LFSR */
   MYLFSR;
   /* convert the LFSR to a fraction from zero to one */
   num = (double) xx->lfsr / xx->modulus;
   return(num);
   } /* gen_dbl */

int main(void)
   {
   xxfmt *xx;

   /*************************************************************/
   /* Allocate memory for the global structure.                 */
   /* This is a re-entrant program.                             */
   /*************************************************************/

   xx = (xxfmt *) malloc(sizeof(xxfmt));
   if (xx == NULL)
      {
      fprintf(stderr,"main: out of memory "
         "allocating xx\n");
      exit(1);
      } /* out of memory */

   /*************************************************************/
   /* Allocate memory for ten million samples.                  */
   /*************************************************************/

   xx->smpls = (double *) malloc (128 + (sizeof(double) * SMPLS));
   if (xx == NULL)
      {
      fprintf(stderr,"main: out of memory "
         "allocating xx->smpls\n");
      exit(1);
      } /* out of memory */

   /*************************************************************/
   /* Allocate memory for runs up counts.                       */
   /*************************************************************/

   xx->up_tally = (double *) malloc (sizeof(double) * 1024);
   if (xx == NULL)
      {
      fprintf(stderr,"main: out of memory "
         "allocating xx->up_tally\n");
      exit(1);
      } /* out of memory */

   /*************************************************************/
   /* Allocate memory for runs down counts.                     */
   /*************************************************************/

   xx->down_tally = (double *) malloc (sizeof(double) * 1024);
   if (xx == NULL)
      {
      fprintf(stderr,"main: out of memory "
         "allocating xx->down_tally\n");
      exit(1);
      } /* out of memory */

   /*************************************************************/
   /* Allocate memory for runs lengths used in the chi          */
   /* square test.                                              */
   /*************************************************************/

   xx->len_tally = (double *) malloc (sizeof(double) * 1024);
   if (xx == NULL)
      {
      fprintf(stderr,"main: out of memory "
         "allocating xx->len_tally\n");
      exit(1);
      } /* out of memory */
   /*************************************************************/
   /* initialize global data                                    */
   /*************************************************************/
   xx->dieharder_rngname[0] = '\0';
   xx->rngname = (char *) NULL;
   xx->generator = -1;
   xx->eofsw     = 0;
   /*************************************************************/
   start_rng(xx);  /* initialize the RNG */
   bldsmpls(xx);   /* create ten million random samples */
   printf("\t      LFSR Generator\n");
   calc_zedzero(xx);   /* compute Z-score */
   calcchi_up(xx);     /* run chi square test */
   freeall(xx);        /* free all allocated memory */
   return(0);          /* end of job */
   } /* main */
