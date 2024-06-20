// ======================================================================
// \title  RNG.hpp
// \author amosalla
// \brief  hpp file for RNG component implementation class
// ======================================================================

#ifndef RNGLibrary_RNG_HPP
#define RNGLibrary_RNG_HPP

#include "RNGLibrary/RNG/RNGComponentAc.hpp"

namespace RNGLibrary {

  class RNG :
    public RNGComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct RNG object
      RNG(
          const char* const compName //!< The component name
      );

      //! Destroy RNG object
      ~RNG();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for data
      void data_handler(
          FwIndexType portNum, //!< The port number
          U32 m_message
      ) override;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command SET_RNG_SEED
      void SET_RNG_SEED_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          U32 seed
      ) override;

    public:
      void set_initial_seed(U32 seed);

  };

}

#endif
