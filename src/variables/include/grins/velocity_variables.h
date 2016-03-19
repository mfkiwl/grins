//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
//
// GRINS - General Reacting Incompressible Navier-Stokes
//
// Copyright (C) 2014-2015 Paul T. Bauman, Roy H. Stogner
// Copyright (C) 2010-2013 The PECOS Development Team
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the Version 2.1 GNU Lesser General
// Public License as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor,
// Boston, MA  02110-1301  USA
//
//-----------------------------------------------------------------------el-


#ifndef GRINS_VELOCITY_VARIABLES_H
#define GRINS_VELOCITY_VARIABLES_H

// libMesh forward declarations
class GetPot;
namespace libMesh
{
  class FEMSystem;
}

// GRINS
#include "grins/variables_base.h"

namespace GRINS
{

  class VelocityVariables : public VariablesBase
  {
  public:

    VelocityVariables( const GetPot& input );
    ~VelocityVariables(){};

    virtual void init( libMesh::FEMSystem* system );

    VariableIndex u() const;
    VariableIndex v() const;
    VariableIndex w() const;

  protected:

    std::string subsection() const
    { return "Velocity"; }

    unsigned int _u_idx, _v_idx, _w_idx;

  private:

    VelocityVariables();

  };

  inline
  VariableIndex VelocityVariables::u() const
  {
    return this->_vars[_u_idx];
  }

  inline
  VariableIndex VelocityVariables::v() const
  {
    return this->_vars[_v_idx];
  }

  inline
  VariableIndex VelocityVariables::w() const
  {
    return this->_vars[_w_idx];
  }

} // end namespace GRINS

#endif //GRINS_VELOCITY_VARIABLES_H