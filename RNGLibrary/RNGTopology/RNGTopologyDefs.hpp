#ifndef RNGTOPOLOGY_DEFS_HPP
#define RNGTOPOLOGY_DEFS_HPP


struct RNGState {
    U32 initialSeed;
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