#include <linux/bpf.h>
#include <linux/in.h>
#include <linux/if_ether.h>
#include <linux/ip.h>

#define __section(NAME) __attribute__((section(NAME), used))

__section("prog")
int drop_tcp(struct xdp_md *ctx)
{
    int ipsize = 0;

    void *data = (void *)(long)ctx->data;
    struct iphdr *ip;

    ip = data + sizeof(struct ethhdr);

    if (ip->protocol == IPPROTO_TCP) {
        return XDP_DROP;
    }

    return XDP_PASS;
}
