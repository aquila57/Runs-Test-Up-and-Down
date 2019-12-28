/* gen_curr_smpl.c - Generate current sample  Version 0.1.0 */
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

/* Generate current sample */

void gen_curr_smpl(xxfmt *xx)
   {
   xx->prev_smpl = xx->curr_smpl;
   while (1)
      {
      double num;
      num = gen_dbl(xx);
      if (xx->eofsw) break;
      else xx->curr_smpl = num;
      if (xx->curr_smpl != xx->prev_smpl) break;
      } /* gen loop */
   } /* gen_curr_smpl */
