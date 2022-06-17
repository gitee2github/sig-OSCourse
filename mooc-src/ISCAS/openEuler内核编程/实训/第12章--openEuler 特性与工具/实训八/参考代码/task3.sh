#include "mpam.h"
DEFINE_MPAM_RESOURCE_USAGE(pool_1) =    \
{       \
        [RESOURCE_L3] = {       \
                .type = RESOURCE_L3,    \
                .name = "myL3",         \
                .strategy = strategy_1, \
        },      \
        [RESOURCE_MB] = {       \
                .type = RESOURCE_MB,    \
                .name = "myMB", \
                .strategy = strategy_1, \
        }       \
}
DEFINE_MPAM_RESOURCE_USAGE_STRATEGY(strategy_1) =       \
{       \
        .l3Pbm = 0x7f,  \
        .mbMax = 20,    \
        .mbMin = 10     \
}
DEFINE_MPAM_RESOURCE_POOL(stream_1_pool) =      \
        MPAM_RESOURCE_POOL_INITIALIZER(pool_1, strategy_1)      \
int main()
{
        int mon_data_ca = mpam_get_mon_data(stream_1_pool, RESOURCE_L3);
        int mon_data_mb = mpam_get_mon_data(stream_1_pool, RESOURCE_MB);
        return 0;
}
