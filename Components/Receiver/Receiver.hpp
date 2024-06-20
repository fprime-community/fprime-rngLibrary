// ======================================================================
// \title  Receiver.hpp
// \author amosalla
// \brief  hpp file for Receiver component implementation class
// ======================================================================

#ifndef Components_Receiver_HPP
#define Components_Receiver_HPP

#include "Components/Receiver/ReceiverComponentAc.hpp"

namespace Components {

  class Receiver :
    public ReceiverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct Receiver object
      Receiver(
          const char* const compName //!< The component name
      );

      //! Destroy Receiver object
      ~Receiver();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for received
      void received_handler(
          FwIndexType portNum, //!< The port number
          U32 m_message
      ) override;

  };

}

#endif
