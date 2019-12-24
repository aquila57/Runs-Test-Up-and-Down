/* runsc.c - Runs test with eegl64 generator  Version 0.1.0 */
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

/* calculate the value of Z0 */

void calc_zedzero(xxfmt *xx)
   {
   double alpha;
   double dblsz;
   double meana;
   double variance;
   double zedzero;
   double pvalue;
   dblsz = (double) SMPLS;
   /*******************************************************/
   /* For this calculation, see                           */
   /* https://www.eg.bucknell.edu/~xmeng/Course/CS6337/   */
   /* Note/master/node44.html                             */
   /* Section 1. Runs up and down                         */
   /* The formulas in the Bucknell document are in the    */
   /* formulas directory of this repository.              */
   /*******************************************************/
   alpha = (double) xx->tot_up_runs + xx->tot_down_runs;
   meana = ((2.0 * dblsz) - 1.0) / 3.0;
   variance = ((16.0 * dblsz) - 29.0) / 90.0;
   zedzero = (alpha - meana) / sqrt(variance);
   printf("\tTest for Runs Up and Down\n");
   printf("\n");
   printf("Samples   %15d\n", SMPLS);
   printf("Runs Up   %15.0f\n", xx->tot_up_runs);
   printf("Runs Down %15.0f\n", xx->tot_down_runs);
   printf("Z0        %15.5f\n", zedzero);
   pvalue = gsl_sf_erf_Q(zedzero);
   printf("P-value   %15.5f\n", pvalue);
   printf("\n");
   printf("At 95%c probability,\n", '%');
   printf("P-value ranges from -1.96 to +1.96\n");
   printf("\n");
   } /* calc_zedzero */
