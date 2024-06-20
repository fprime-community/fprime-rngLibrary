// ======================================================================
// \title  Hardware.cpp
// \author amosalla
// \brief  cpp file for Hardware component implementation class
// ======================================================================

#include "Components/Hardware/Hardware.hpp"
#include "FpConfig.hpp"
#include "random"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  Hardware ::
    Hardware(const char* const compName) :
      HardwareComponentBase(compName)
  {

  }

  Hardware ::
    ~Hardware()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void Hardware ::
    run_handler(
        FwIndexType portNum,
        U32 context
    )
  {
    U32 randomData = rand() % 150000;
    this->tlmWrite_HardwareData(randomData);
    this->data_out(0, randomData);
  }

}
