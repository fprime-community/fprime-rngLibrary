#include <Fw/Logger/Logger.hpp>
#include <RNGLibrary/RNGTopology/RNGTopology.hpp>
#include <Svc/ActiveRateGroup/ActiveRateGroup.hpp>
#include <Svc/RateGroupDriver/RateGroupDriver.hpp>
#include <RNGLibrary/RNGTopology/RNGTopologyTopologyAc.hpp>

// Rate groups may supply a context token to each of the attached children whose purpose is set by the project. The
// reference topology sets each token to zero as these contexts are unused in this project.
NATIVE_INT_TYPE rateGroupContext[Svc::ActiveRateGroup::CONNECTION_COUNT_MAX] = {};

void configureTopology(const TopologyState& state){
    NATIVE_INT_TYPE clockDivisor = 10; // default 1Hz
    if(state.clockRate){
        if(state.clockRate > 10 || 10 % state.clockRate != 0){
            Fw::Logger::logMsg("[RNG Topology] Warning: Clock rate is not a divisor of 10Hz. Defaulting to 1Hz.");
        } else {
            clockDivisor = 10/state.clockRate; // assuming the input frequency is 10Hz
        }
    }

    // The reference topology divides the incoming clock signal (10Hz) into sub-signals: 1Hz
    Svc::RateGroupDriver::DividerSet rateGroupDivisors = {{{clockDivisor, 0}}};
    RNGTopology_rateGroupDriver.configure(rateGroupDivisors);
    // RNGTopology_rateGroup.configure(rateGroupContext, Fw_NUM_ARRAY_ELEMENTS(rateGroupContext));
}

void startTopology(const TopologyState& state){
    Fw::Logger::logMsg("[RNG Topology] Topology has been started.");
}

void teardownTopology(const TopologyState& state){
    Fw::Logger::logMsg("[RNG Topology] Topology has been cleaned up.");
}