module RNGTopologyConfig {
    module Defaults {
        constant QUEUE_SIZE = 10
        constant STACK_SIZE = 64 * 1024
    }

    port MessagePort(
        m_message: U32
    )
}