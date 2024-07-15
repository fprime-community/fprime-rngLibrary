#ifndef RNGTOPOLOGY_DEFS_HPP
#define RNGTOPOLOGY_DEFS_HPP

struct RNGTopologyState {
    U32 initialSeed;
};

struct TopologyState {
    RNGTopologyState RNGTopology_state;
};

namespace Globals
{
    namespace PingEntries
    {
        namespace RNGTopology_rng
        {
            enum
            {
                WARN = 3,
                FATAL = 5
            };
        }
    }
}

#endif