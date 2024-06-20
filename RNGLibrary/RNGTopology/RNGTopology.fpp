module RNGTopology {
    instance rng: RNGLibrary.RNG base id 0x4444 \
        queue size RNGTopologyConfig.Defaults.QUEUE_SIZE \
        stack size RNGTopologyConfig.Defaults.STACK_SIZE \
        priority 100 \
        {
            phase Fpp.ToCpp.Phases.configComponents """
                RNGTopology_rng.set_initial_seed(state.RNGTopology_state.initialSeed);
            """
        }

    topology RNG {
        @! is local
        instance RNGTopology.rng

        instance receiver
        instance hardware

        connections Topology {
            RNGTopology.rng.processed -> receiver.received
            hardware.data -> RNGTopology.rng.data
        }
    } # end topology
} # end RNGTopology