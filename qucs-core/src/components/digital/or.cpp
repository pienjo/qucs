/*
 * or.cpp - logical or class implementation
 *
 * Copyright (C) 2005 Stefan Jahn <stefan@lkcc.org>
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this package; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor,
 * Boston, MA 02110-1301, USA.  
 *
 * $Id: or.cpp,v 1.4 2005-12-12 07:46:53 raimi Exp $
 *
 */

#if HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>

#include "complex.h"
#include "object.h"
#include "circuit.h"
#include "component_id.h"
#include "constants.h"
#include "digital.h"
#include "or.h"

logicor::logicor () : digital () {
  type = CIR_OR;
  setVariableSized (true);
}

void logicor::calcOutput (void) {
  nr_double_t v = getPropertyDouble ("V");
  nr_double_t n = getSize () - 1;
  nr_double_t x;
  for (x = 0, i = 0; i < n; i++) {
    x += 2 / (1 - calcTransfer (i));
  }
  Vout = v * (1 - n / x);
}

void logicor::calcDerivatives (void) {
  nr_double_t n = getSize () - 1;
  nr_double_t x;
  for (int k = 0; k < n; k++) {
    for (x = 0, i = 0; i < n; i++) {
      x += 2 / (1 - calcTransfer (i));
    }
    x *= (1 - calcTransfer (k));
    g[k] = n * calcDerivative (k) / x / x;
  }
}
