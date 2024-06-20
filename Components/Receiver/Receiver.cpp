// ======================================================================
// \title  Receiver.cpp
// \author amosalla
// \brief  cpp file for Receiver component implementation class
// ======================================================================

#include "Components/Receiver/Receiver.hpp"
#include "FpConfig.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  Receiver ::
    Receiver(const char* const compName) :
      ReceiverComponentBase(compName)
  {

  }

  Receiver ::
    ~Receiver()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void Receiver ::
    received_handler(
        FwIndexType portNum,
        U32 m_message
    )
  {
    this->log_ACTIVITY_HI_ReceivedData(m_message);
  }

}
