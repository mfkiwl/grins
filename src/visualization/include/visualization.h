//-----------------------------------------------------------------------bl-
//-----------------------------------------------------------------------el-
//
// $Id$
//
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

#ifndef GRINS_VISUALIZATION_H
#define GRINS_VISUALIZATION_H

#include <string>
#include <vector>

// libMesh
#include "getpot.h"
#include "gmv_io.h"
#include "tecplot_io.h"
#include "exodusII_io.h"
#include "vtk_io.h"

namespace GRINS
{
  class Visualization
  {
  public:

    Visualization( const GetPot& input );
    ~Visualization();

    void output();
    void output( unsigned int time_step );

    void output_residual( libMesh::EquationSystems* equation_system,
			  GRINS::MultiphysicsSystem* system );

    virtual void output_residual( libMesh::EquationSystems* equation_system,
				  GRINS::MultiphysicsSystem* system,
				  const unsigned int time_step ) =0;

  protected:

    void dump_visualization( const std::string filename_prefix, const int time_step );

    // Visualization options
    std::string _vis_output_file_prefix;
    std::vector<std::string> _output_format;
  };
}// namespace GRINS
#endif // GRINS_VISUALIZATION_H