// ======================================================================
// \title  RNG.cpp
// \author amosalla
// \brief  cpp file for RNG component implementation class
// ======================================================================

#include "FpConfig.hpp"
#include "RNGLibrary/RNG/RNG.hpp"
#include "random"

namespace RNGLibrary {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  RNG ::
    RNG(const char* const compName) :
      RNGComponentBase(compName)
  {

  }

  RNG ::
    ~RNG()
  {

  }

  void RNG :: 
    set_initial_seed(U32 seed)
  {
    std::srand(seed);
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void RNG ::
    data_handler(
        FwIndexType portNum,
        U32 m_message
    )
  {
    this->tlmWrite_DataIn(m_message);

    U32 message_p1 = m_message / 2 - 1;
    U32 message_p2 = message_p1 + 2;

    U32 message_final = message_p1 * message_p2;

    this->processed_out(0, message_final);
  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void RNG ::
    SET_RNG_SEED_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        U32 seed
    )
  {
    this->set_initial_seed(seed);
    this->tlmWrite_RNGSeed(seed);

    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
