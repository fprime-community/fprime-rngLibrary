module RNGTopologyInterface {
    passive component Input {
        sync input port clock: Svc.Sched
        output port clock_in: Svc.Sched
    }
}