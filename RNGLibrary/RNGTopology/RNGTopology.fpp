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

    instance receiver: Components.Receiver base id 0x5555 \
        queue size RNGTopologyConfig.Defaults.QUEUE_SIZE \
        stack size RNGTopologyConfig.Defaults.STACK_SIZE \
        priority 100
    
    instance hardware: Components.Hardware base id 0x6666 \
        queue size RNGTopologyConfig.Defaults.QUEUE_SIZE \
        stack size RNGTopologyConfig.Defaults.STACK_SIZE \
        priority 100

    instance Input: RNGTopologyInterface.Input base id 0x7777

    topology RNG {
        @! is local
        instance RNGTopology.rng

        instance receiver
        instance hardware

        @! is interface input
        instance RNGTopology.Input

        connections Topology {
            RNGTopology.rng.processed -> receiver.received
            hardware.data -> RNGTopology.rng.data
        }

        connections Interface {
            RNGTopology.Input.clock_in -> RNGTopology.rng.run
        }
    } # end topology
} # end RNGTopology