/* add_both_tallies.c - Add Both Tally Arrays  Version 0.1.0 */
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

/********************************************************************/
/* Add the runs up and runs down counts into a single               */
/* array of run lengths.                                            */
/********************************************************************/

void add_both_tallies(xxfmt *xx)
   {
   double *p,*q,*r,*s;
   p = (double *) xx->up_tally;
   q = (double *) xx->up_tally + 1024;
   r = (double *) xx->down_tally;
   s = (double *) xx->len_tally;
   while (p < q) *s++ = *p++ + *r++;
   } /* add_both_tallies */
