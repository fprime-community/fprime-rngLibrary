#ifndef RNGTOPOLOGY_DEFS_HPP
#define RNGTOPOLOGY_DEFS_HPP

namespace RNGTopology
{

    struct TopologyState
    {
        U32 clockRate;
    };

    namespace GlobalDefs
    {
        namespace PingEntries
        {
            namespace RNGTopology_rateGroup
            {
                enum
                {
                    WARN = 3,
                    FATAL = 5
                };
            }
        }
    }
}

#endif