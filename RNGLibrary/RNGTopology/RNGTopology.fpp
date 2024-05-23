module RNGTopology {
    module Defaults {
        constant QUEUE_SIZE = 10
        constant STACK_SIZE = 64 * 1024
    }

    instance rng: RNGLibrary.RNG base id 0xFF2FF \
        queue size Defaults.QUEUE_SIZE \
        stack size Defaults.STACK_SIZE \
        priority 100

    instance rateGroup: Svc.ActiveRateGroup base id 0xFF4FF \
        queue size Defaults.QUEUE_SIZE \
        stack size Defaults.STACK_SIZE \
        priority 150

    instance rateGroupDriver: Svc.RateGroupDriver base id 0xFF8FF # to drive the 1Hz rate group

    topology RNGTopology {
        instance rng # RNG component instance
        instance rateGroup # rate group instance
        instance rateGroupDriver # driving the rate group

        connections MyWiring {
            rateGroupDriver.CycleOut[0] -> rateGroup.CycleIn # to send the 1Hz configurable signal to our rate group
            rateGroup.RateGroupMemberOut[0] -> rng.run
        }
    } # end topology
} # end MySubtopology