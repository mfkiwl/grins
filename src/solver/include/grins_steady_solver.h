//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
// 
// GRINS - General Reacting Incompressible Navier-Stokes 
//
// Copyright (C) 2010-2012 The PECOS Development Team
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the Version 2 GNU General
// Public License as published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor, Boston, MA
// 02110-1301 USA
//
//-----------------------------------------------------------------------el-
//
// $Id$
//
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

#ifndef GRINS_STEADY_SOLVER_H
#define GRINS_STEADY_SOLVER_H

//GRINS
#include "grins_solver.h"
#include "visualization.h"

//libMesh
#include "auto_ptr.h"
#include "equation_systems.h"

namespace GRINS
{
  class SteadySolver : public Solver
  {
  public:

    SteadySolver( const GetPot& input );
    virtual ~SteadySolver();

    virtual void solve( GRINS::MultiphysicsSystem* system,
			std::tr1::shared_ptr<libMesh::EquationSystems> equation_system = 
			std::tr1::shared_ptr<libMesh::EquationSystems>(),
			std::tr1::shared_ptr<GRINS::Visualization> vis = 
			std::tr1::shared_ptr<GRINS::Visualization>(),
			bool output_vis = false,
			bool output_residual = false );

  protected:

    virtual void init_time_solver(GRINS::MultiphysicsSystem* system);

  };
} // namespace GRINS
#endif // GRINS_STEADY_SOLVER_H
