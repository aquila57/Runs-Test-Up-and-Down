/* bld_curr_smpl.c - Build current sample  Version 0.1.0 */
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

/*********************************************************************/
/* generate a new random sample.                                     */
/* determine if a new run has started.                               */
/* if a new run has started,                                         */
/* add run lengths to run length arrays                              */
/* increase the run count by one                                     */
/*********************************************************************/

void bld_curr_smpl(xxfmt *xx)
   {
   gen_curr_smpl(xx);
   if (xx->curr_smpl > xx->prev_smpl)          /* run UP */
      {
      if (xx->run_direction == DOWN)
         {
	 xx->down_tally[xx->run_len] += 1.0;
	 xx->tot_down_runs += 1.0;
	 xx->tot_down_len += (double) xx->run_len;;
	 xx->run_direction = UP;
	 xx->run_len = 1;
	 } /* if switching direction */
      else /* else same direction as before */
         {
	 xx->run_len++;
	 } /* else same direction as before */
      } /* if run up */
   else /* else run DOWN */
      {
      if (xx->run_direction == UP)
         {
	 xx->up_tally[xx->run_len] += 1.0;
	 xx->tot_up_runs += 1.0;
	 xx->tot_up_len += (double) xx->run_len;;
	 xx->run_direction = DOWN;
	 xx->run_len = 1;
	 } /* if switching direction */
      else /* else same direction as before */
         {
	 xx->run_len++;
	 } /* else same direction as before */
      } /* else run down */
   } /* bld_curr_smpl */
