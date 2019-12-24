/* calcchi_up.c - Runs test chi square test  Version 0.1.0 */
/* Copyright (C) 2019 aquila57 at github.com                    */

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

/*********************************************************************/
/* perform the chi square test based on run lengths                  */
/*********************************************************************/

void calcchi_up(xxfmt *xx)
   {
   int i;
   double *p,*q;    /* pointers to run lengths */
   double N;        /* total number of samples */
   double diff;     /* difference between actual and expected */
   double diffsq;   /* difference squared */
   double chisq;    /* chi square */
   double expected;  /* expected count */
   double df;        /* degrees of freedom */
   /* at 95% confidence level */
   double minchi;    /* minimum chi square value */
   double maxchi;    /* maximum chi square value */
   double pvalue;    /* chi square P-value */
   /* print headers */
   printf("\t\tChi Square Test\n");
   printf("Length      Actual           "
      "Expected        Difference\n");
   chisq = 0.0;       /* initialize chi square */
   i = 0;             /* initialize run length */
   p = (double *) xx->len_tally + 1;
   q = (double *) xx->len_tally + 1024;
   N = (double) SMPLS;   /* set total samples */
   while (p < q)
      {
      double dbli;
      if (*p < 10.0) break;   /* minimum run length count is 10 */
      i++;       /* next run length */
      dbli = (double) i;
      /* if a run length is greater than 1023 */
      /* the chi test will fail, anyway */
      if (dbli > (N-1.0)) break;
      /* calculate the expected count */
      expected = calc_exp_up(i, N);
      /* difference between actual and expected */
      diff = expected - *p;
      /* difference squared */
      diffsq = diff * diff;
      /* accumulate the chi square value */
      chisq += (diffsq / expected);
      /* display counts by run length */
      printf("%4d  %12.0f  %18.5f  %15.0f\n",
         i, *p, expected, diff);
      p++;
      } /* for each actual tally */
   df = (double) (i-1);    /* degreees of freedom */
   /* 95% confidence level, calculate range */
   minchi = gsl_cdf_chisq_Pinv(0.025,df);
   maxchi = gsl_cdf_chisq_Pinv(0.975,df);
   /* calculate chi square P-value */
   pvalue = gsl_cdf_chisq_P(chisq,df);
   /* print results of chi square test */
   printf("\n");
   printf("Chi square %f  P-value %f\n", chisq, pvalue);
   printf("\n");
   printf("At 95%c probability and %.0f degrees of freedom,\n"
      "Chi square ranges from %f to %f\n",
      '%', df, minchi, maxchi);
   } /* calcchi_up */
