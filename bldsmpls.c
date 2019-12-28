/* bldsmpls.c - Build Samples and Tally  Version 0.1.0 */
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

/****************************************************************/
/* build a list of ten million samples                          */
/* count the last sample as part of the last run                */
/****************************************************************/

void bldsmpls(xxfmt *xx)
   {
   xx->smpl_p = (double *) xx->smpls;
   xx->smpl_q = (double *) xx->smpls + SMPLS;
   /* determine if the first run is up or down */
   bld_frst_run(xx);
   if (xx->eofsw)
      {
      fprintf(stderr,"bldsmpls: end of file "
         "reading first sample\n");
      exit(1);
      } /* if end of file */
   while (!xx->eofsw)
      {
      if (xx->smpl_p >= xx->smpl_q) break;
      bld_curr_smpl(xx);
      if (xx->eofsw)
         {
         fprintf(stderr,"bldsmpls: end of file\n");
	 break;
         } /* if end of file */
      else *xx->smpl_p++ = xx->curr_smpl;
      } /* for each sample */
   /* tally the final run */
   if (xx->run_direction == UP)
      {
      xx->tot_up_len += (double) xx->run_len;
      xx->tot_up_runs += 1.0;
      } /* if ending in up run */
   else if (xx->run_direction == DOWN)
      {
      xx->tot_down_len += (double) xx->run_len;
      xx->tot_down_runs += 1.0;
      } /* if ending in down run */
   else
      {
      fprintf(stderr,"bldsmpls: direction error\n");
      exit(1);
      } /* direction error */
   /* combine run lengths into a single array */
   add_both_tallies(xx);
   xx->tot_len = xx->tot_up_len + xx->tot_down_len;
   xx->tot_runs = xx->tot_up_runs + xx->tot_down_runs;
   xx->avg_up_len = xx->tot_up_len / xx->tot_up_runs;
   xx->avg_down_len = xx->tot_down_len / xx->tot_down_runs;
   xx->avg_len = xx->tot_len / xx->tot_runs;
   } /* bldsmpls */
