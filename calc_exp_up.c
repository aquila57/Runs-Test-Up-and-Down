/* calc_exp_up.c - Runs test  Version 0.1.0 */
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

#include "runs.h"

double calc_exp_up(int indx, double N)
   {
   double permut;   /* permutations */
   double mult;     /* multiplier */
   double dbli;     /* run length */
   double quad;     /* quadratic expression */
   double tripl;    /* cubic expression */
   double expected;   /* expected count */
   dbli = (double) indx;
   if (dbli > (N - 1.0))
      {
      fprintf(stderr,"exp_up: indx %d is too large\n", indx);
      exit(1);
      } /* if indx is too large */
   if (dbli == (N - 1.0))
      {
      /* permutations of run length */
      permut = permute(indx);
      return(2.0 / permut);
      } /* if i == N-1 */
   /*******************************************************/
   /* For this calculation, see                           */
   /* https://www.eg.bucknell.edu/~xmeng/Course/CS6337/   */
   /* Note/master/node44.html                             */
   /* Section 3. Runs test: length of runs.               */
   /* The formulas in the Bucknell document are in the    */
   /* formulas directory of this repository.              */
   /*******************************************************/
   permut = permute(indx + 3);
   mult = 2.0 / permut;
   quad = (dbli * dbli) + (3.0 * dbli) + 1.0;
   tripl = (dbli * dbli * dbli) + (3.0 * dbli * dbli) - dbli - 4.0;
   expected = mult * ((N * quad) - tripl);
   return(expected);
   } /* calc_exp_up */
