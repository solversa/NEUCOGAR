/*
 *  exp_randomdev.cpp
 *
 *  This file is part of NEST.
 *
 *  Copyright (C) 2004 The NEST Initiative
 *
 *  NEST is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  NEST is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with NEST.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "exp_randomdev.h"
#include "sliexceptions.h"
#include "dictutils.h"

void
librandom::ExpRandomDev::set_status( const DictionaryDatum& d )
{
  double new_lambda = lambda_;

  updateValue< double >( d, "lambda", new_lambda );

  if ( new_lambda <= 0. )
    throw BadParameterValue( "Exponential RDV: lambda > 0 required." );

  lambda_ = new_lambda;
}

void
librandom::ExpRandomDev::get_status( DictionaryDatum& d ) const
{
  def< double >( d, "lambda", lambda_ );
}
