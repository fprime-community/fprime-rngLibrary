#ifndef RNGTopology_HPP
#define RNGTopology_HPP

#include "RNGTopologyTopologyDefs.hpp"
#include <TopologyConfig.hpp>


namespace RNGTopology {
    void configureTopology(const TopologyState& state);
    void startTopology(const TopologyState& state);
    void teardownTopology(const TopologyState& state);
}

#endif