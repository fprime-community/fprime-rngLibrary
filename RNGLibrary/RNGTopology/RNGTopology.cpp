#include <Fw/Logger/Logger.hpp>
#include <RNGLibrary/RNGTopology/RNGTopology.hpp>
#include <Svc/ActiveRateGroup/ActiveRateGroup.hpp>
#include <Svc/RateGroupDriver/RateGroupDriver.hpp>
#include <RNGLibrary/RNGTopology/RNGTopologyTopologyAc.hpp>

// Rate groups may supply a context token to each of the attached children whose purpose is set by the project. The
// reference topology sets each token to zero as these contexts are unused in this project.
NATIVE_INT_TYPE rateGroupContext[Svc::ActiveRateGroup::CONNECTION_COUNT_MAX] = {};

namespace RNGTopology
{

    void configureTopology(const TopologyState &state)
    {
        // The reference topology divides the incoming clock signal (10Hz) into sub-signals: 1Hz
        RNGTopology_rateGroup.configure(rateGroupContext, FW_NUM_ARRAY_ELEMENTS(rateGroupContext));
    }

    void startTopology(const TopologyState &state)
    {
        Fw::Logger::logMsg("[RNG Topology] Topology has been started.");
    }

    void teardownTopology(const TopologyState &state)
    {
        Fw::Logger::logMsg("[RNG Topology] Topology has been cleaned up.");
    }

}