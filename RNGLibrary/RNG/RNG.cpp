// ======================================================================
// \title  RNG.cpp
// \author amosalla
// \brief  cpp file for RNG component implementation class
// ======================================================================

#include "FpConfig.hpp"
#include "Fw/Logger/Logger.hpp"
#include "RNGLibrary/RNG/RNG.hpp"
#include "random"

namespace RNGLibrary
{

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  RNG ::
      RNG(const char *const compName) : RNGComponentBase(compName)
  {
  }

  RNG ::
      ~RNG()
  {
  }

  void RNG ::
      run_handler(
          NATIVE_INT_TYPE portNum,
          NATIVE_UINT_TYPE context)
  {
    this->tlmWrite_RNGValue(rand());
  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void RNG ::
      SET_RNG_SEED_cmdHandler(
          FwOpcodeType opCode,
          U32 cmdSeq,
          U32 seed)
  {
    srand(seed);
    Fw::Logger::logMsg("[RNG]: Seed set to %d\n", seed);
    this->tlmWrite_RNGSeed(seed)
  }
}
