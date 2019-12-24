/* runsa.c - Runs Test Up and Down, eegl64 generator  Version 0.1.0 */
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

/* Initialize the eegl64 random number generator */
/* See the eegl64 repository for more information about */
/* this generator. */

void start_rng(xxfmt *xx)
   {
   xx->ee = (eefmt *) eeglinit();
   } /* start_rng */

/* Generate one uniform sample from zero to one */

double gen_dbl(xxfmt *xx)
   {
   double num;
   num = eeglunif(xx->ee);
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
   start_rng(xx);  /* initialize the RNG */
   bldsmpls(xx);   /* create ten million random samples */
   calc_zedzero(xx);   /* compute Z-score */
   calcchi_up(xx);     /* run chi square test */
   freeall(xx);        /* free all allocated memory */
   return(0);          /* end of job */
   } /* main */
