/* runsfibo.c - Fibonacci Runs Up and Down Test  Version 0.1.0 */
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

/* initialize the fibonacci random number generator */

void start_rng(xxfmt *xx)
   {
   xx->ee = (eefmt *) eeglinit();
   xx->fibonum1 = eegl(xx->ee);
   xx->fibonum2 = eegl(xx->ee);
   xx->fibonum3 = xx->fibonum1 + xx->fibonum2;
   xx->modulus = 65536.0 * 65536.0;
   } /* start_rng */

/* generator one sample for  the fibonacci */
/* random number generator */

double gen_dbl(xxfmt *xx)
   {
   double num;
   xx->fibonum1 = xx->fibonum2;
   xx->fibonum2 = xx->fibonum3;
   xx->fibonum3 = xx->fibonum1 + xx->fibonum2;
   num = (double) xx->fibonum3 / xx->modulus;
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
   printf("\t    Fibonacci Generator\n");
   calc_zedzero(xx);   /* compute Z-score */
   calcchi_up(xx);     /* run chi square test */
   freeall(xx);        /* free all allocated memory */
   return(0);          /* end of job */
   } /* main */
