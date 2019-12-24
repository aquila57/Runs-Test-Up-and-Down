/* bld_frst_run.c - Build First Run  Version 0.1.0 */
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

void bld_frst_run(xxfmt *xx)
   {
   double *p,*q;
   p = (double *) xx->up_tally;
   q = (double *) xx->up_tally + 1024;
   while (p < q) *p++ = 0.0;
   p = (double *) xx->down_tally;
   q = (double *) xx->down_tally + 1024;
   while (p < q) *p++ = 0.0;
   p = (double *) xx->len_tally;
   q = (double *) xx->len_tally + 1024;
   while (p < q) *p++ = 0.0;
   xx->tot_up_runs = xx->tot_down_runs = 0.0;
   xx->tot_up_len  = xx->tot_down_len  = 0.0;
   xx->run_direction = -1;
   xx->run_len = 0;
   xx->curr_smpl = -999999999.0;
   gen_curr_smpl(xx);
   *xx->smpl_p++ = xx->curr_smpl;
   if (xx->curr_smpl < 0.5)
      {
      xx->tot_down_len = 1.0;
      xx->tot_down_runs = 1.0;
      xx->run_direction = DOWN;
      } /* if less than 0.5 */
   else
      {
      xx->tot_up_len = 1.0;
      xx->tot_up_runs = 1.0;
      xx->run_direction = UP;
      } /* if less than 0.5 */
   gen_curr_smpl(xx);
   *xx->smpl_p++ = xx->curr_smpl;
   if (xx->curr_smpl > xx->prev_smpl)
      {
      xx->run_len = 1;
      xx->run_direction = UP;
      } /* if run up */
   else if (xx->curr_smpl < xx->prev_smpl)
      {
      xx->run_len = 1;
      xx->run_direction = DOWN;
      } /* else run down */
   } /* bld_frst_run */
