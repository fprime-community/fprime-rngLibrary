// ======================================================================
// \title  Hardware.hpp
// \author amosalla
// \brief  hpp file for Hardware component implementation class
// ======================================================================

#ifndef Components_Hardware_HPP
#define Components_Hardware_HPP

#include "Components/Hardware/HardwareComponentAc.hpp"

namespace Components {

  class Hardware :
    public HardwareComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct Hardware object
      Hardware(
          const char* const compName //!< The component name
      );

      //! Destroy Hardware object
      ~Hardware();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for run
      void run_handler(
          FwIndexType portNum, //!< The port number
          U32 context //!< The call order
      ) override;

  };

}

#endif
