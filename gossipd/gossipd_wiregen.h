/* This file was generated by generate-wire.py */
/* Do not modify this file! Modify the _csv file it was generated from. */
/* Original template can be found at tools/gen/header_template */

#ifndef LIGHTNING_GOSSIPD_GOSSIPD_WIREGEN_H
#define LIGHTNING_GOSSIPD_GOSSIPD_WIREGEN_H
#include <ccan/tal/tal.h>
#include <wire/tlvstream.h>
#include <wire/wire.h>
#include <common/cryptomsg.h>
#include <common/features.h>
#include <common/wireaddr.h>
#include <wire/peer_wire.h>
#include <wire/onion_wire.h>

enum gossipd_wire {
        /*  Initialize the gossip daemon. */
        WIRE_GOSSIPD_INIT = 3000,
        WIRE_GOSSIPD_INIT_REPLY = 3100,
        /*  In developer mode */
        WIRE_GOSSIPD_DEV_SET_TIME = 3001,
        /*  Ping/pong test.  Waits for a reply if it expects one. */
        WIRE_GOSSIPD_PING = 3008,
        WIRE_GOSSIPD_PING_REPLY = 3108,
        /*  Set artificial maximum reply_channel_range size.  Master->gossipd */
        WIRE_GOSSIPD_DEV_SET_MAX_SCIDS_ENCODE_SIZE = 3030,
        /*  Given a short_channel_id */
        WIRE_GOSSIPD_GET_STRIPPED_CUPDATE = 3010,
        WIRE_GOSSIPD_GET_STRIPPED_CUPDATE_REPLY = 3110,
        /*  gossipd->master: we're closing this channel. */
        WIRE_GOSSIPD_LOCAL_CHANNEL_CLOSE = 3027,
        /*  Gossipd->master get this tx output please. */
        WIRE_GOSSIPD_GET_TXOUT = 3018,
        /*  master->gossipd here is the output */
        WIRE_GOSSIPD_GET_TXOUT_REPLY = 3118,
        /*  master -> gossipd: a potential funding outpoint was spent */
        WIRE_GOSSIPD_OUTPOINT_SPENT = 3024,
        /*  master -> gossipd: stop gossip timers. */
        WIRE_GOSSIPD_DEV_SUPPRESS = 3032,
        /*  master -> gossipd: do you have a memleak? */
        WIRE_GOSSIPD_DEV_MEMLEAK = 3033,
        WIRE_GOSSIPD_DEV_MEMLEAK_REPLY = 3133,
        /*  master -> gossipd: please rewrite the gossip_store */
        WIRE_GOSSIPD_DEV_COMPACT_STORE = 3034,
        /*  gossipd -> master: ok */
        WIRE_GOSSIPD_DEV_COMPACT_STORE_REPLY = 3134,
        /*  master -> gossipd: blockheight increased. */
        WIRE_GOSSIPD_NEW_BLOCKHEIGHT = 3026,
        /*  Tell lightningd we got an obsolete onion message (for us */
        WIRE_GOSSIPD_GOT_OBS_ONIONMSG_TO_US = 3142,
        WIRE_GOSSIPD_GOT_OBS_ONIONMSG_FORWARD = 3143,
        /*  Lightningd tells us to send a onion message. */
        WIRE_GOSSIPD_SEND_OBS_ONIONMSG = 3040,
        /*  Lightningd tells us to inject a gossip message (for addgossip RPC) */
        WIRE_GOSSIPD_ADDGOSSIP = 3044,
        /*  Empty string means no problem. */
        WIRE_GOSSIPD_ADDGOSSIP_REPLY = 3144,
        /*  Updated lease rates available */
        WIRE_GOSSIPD_NEW_LEASE_RATES = 3046,
};

const char *gossipd_wire_name(int e);

/**
 * Determine whether a given message type is defined as a message.
 *
 * Returns true if the message type is part of the message definitions we have
 * generated parsers for, false if it is a custom message that cannot be
 * handled internally.
 */
bool gossipd_wire_is_defined(u16 type);


/* WIRE: GOSSIPD_INIT */
/*  Initialize the gossip daemon. */
u8 *towire_gossipd_init(const tal_t *ctx, const struct chainparams *chainparams, const struct feature_set *our_features, const struct node_id *id, const u8 rgb[3], const u8 alias[32], const struct wireaddr *announcable, u32 *dev_gossip_time, bool dev_fast_gossip, bool dev_fast_gossip_prune);
bool fromwire_gossipd_init(const tal_t *ctx, const void *p, const struct chainparams **chainparams, struct feature_set **our_features, struct node_id *id, u8 rgb[3], u8 alias[32], struct wireaddr **announcable, u32 **dev_gossip_time, bool *dev_fast_gossip, bool *dev_fast_gossip_prune);

/* WIRE: GOSSIPD_INIT_REPLY */
u8 *towire_gossipd_init_reply(const tal_t *ctx);
bool fromwire_gossipd_init_reply(const void *p);

/* WIRE: GOSSIPD_DEV_SET_TIME */
/*  In developer mode */
u8 *towire_gossipd_dev_set_time(const tal_t *ctx, u32 dev_gossip_time);
bool fromwire_gossipd_dev_set_time(const void *p, u32 *dev_gossip_time);

/* WIRE: GOSSIPD_PING */
/*  Ping/pong test.  Waits for a reply if it expects one. */
u8 *towire_gossipd_ping(const tal_t *ctx, const struct node_id *id, u16 num_pong_bytes, u16 len);
bool fromwire_gossipd_ping(const void *p, struct node_id *id, u16 *num_pong_bytes, u16 *len);

/* WIRE: GOSSIPD_PING_REPLY */
u8 *towire_gossipd_ping_reply(const tal_t *ctx, const struct node_id *id, bool sent, u16 totlen);
bool fromwire_gossipd_ping_reply(const void *p, struct node_id *id, bool *sent, u16 *totlen);

/* WIRE: GOSSIPD_DEV_SET_MAX_SCIDS_ENCODE_SIZE */
/*  Set artificial maximum reply_channel_range size.  Master->gossipd */
u8 *towire_gossipd_dev_set_max_scids_encode_size(const tal_t *ctx, u32 max);
bool fromwire_gossipd_dev_set_max_scids_encode_size(const void *p, u32 *max);

/* WIRE: GOSSIPD_GET_STRIPPED_CUPDATE */
/*  Given a short_channel_id */
u8 *towire_gossipd_get_stripped_cupdate(const tal_t *ctx, const struct short_channel_id *channel_id);
bool fromwire_gossipd_get_stripped_cupdate(const void *p, struct short_channel_id *channel_id);

/* WIRE: GOSSIPD_GET_STRIPPED_CUPDATE_REPLY */
u8 *towire_gossipd_get_stripped_cupdate_reply(const tal_t *ctx, const u8 *stripped_update);
bool fromwire_gossipd_get_stripped_cupdate_reply(const tal_t *ctx, const void *p, u8 **stripped_update);

/* WIRE: GOSSIPD_LOCAL_CHANNEL_CLOSE */
/*  gossipd->master: we're closing this channel. */
u8 *towire_gossipd_local_channel_close(const tal_t *ctx, const struct short_channel_id *short_channel_id);
bool fromwire_gossipd_local_channel_close(const void *p, struct short_channel_id *short_channel_id);

/* WIRE: GOSSIPD_GET_TXOUT */
/*  Gossipd->master get this tx output please. */
u8 *towire_gossipd_get_txout(const tal_t *ctx, const struct short_channel_id *short_channel_id);
bool fromwire_gossipd_get_txout(const void *p, struct short_channel_id *short_channel_id);

/* WIRE: GOSSIPD_GET_TXOUT_REPLY */
/*  master->gossipd here is the output */
u8 *towire_gossipd_get_txout_reply(const tal_t *ctx, const struct short_channel_id *short_channel_id, struct amount_sat satoshis, const u8 *outscript);
bool fromwire_gossipd_get_txout_reply(const tal_t *ctx, const void *p, struct short_channel_id *short_channel_id, struct amount_sat *satoshis, u8 **outscript);

/* WIRE: GOSSIPD_OUTPOINT_SPENT */
/*  master -> gossipd: a potential funding outpoint was spent */
u8 *towire_gossipd_outpoint_spent(const tal_t *ctx, const struct short_channel_id *short_channel_id);
bool fromwire_gossipd_outpoint_spent(const void *p, struct short_channel_id *short_channel_id);

/* WIRE: GOSSIPD_DEV_SUPPRESS */
/*  master -> gossipd: stop gossip timers. */
u8 *towire_gossipd_dev_suppress(const tal_t *ctx);
bool fromwire_gossipd_dev_suppress(const void *p);

/* WIRE: GOSSIPD_DEV_MEMLEAK */
/*  master -> gossipd: do you have a memleak? */
u8 *towire_gossipd_dev_memleak(const tal_t *ctx);
bool fromwire_gossipd_dev_memleak(const void *p);

/* WIRE: GOSSIPD_DEV_MEMLEAK_REPLY */
u8 *towire_gossipd_dev_memleak_reply(const tal_t *ctx, bool leak);
bool fromwire_gossipd_dev_memleak_reply(const void *p, bool *leak);

/* WIRE: GOSSIPD_DEV_COMPACT_STORE */
/*  master -> gossipd: please rewrite the gossip_store */
u8 *towire_gossipd_dev_compact_store(const tal_t *ctx);
bool fromwire_gossipd_dev_compact_store(const void *p);

/* WIRE: GOSSIPD_DEV_COMPACT_STORE_REPLY */
/*  gossipd -> master: ok */
u8 *towire_gossipd_dev_compact_store_reply(const tal_t *ctx, bool success);
bool fromwire_gossipd_dev_compact_store_reply(const void *p, bool *success);

/* WIRE: GOSSIPD_NEW_BLOCKHEIGHT */
/*  master -> gossipd: blockheight increased. */
u8 *towire_gossipd_new_blockheight(const tal_t *ctx, u32 blockheight);
bool fromwire_gossipd_new_blockheight(const void *p, u32 *blockheight);

/* WIRE: GOSSIPD_GOT_OBS_ONIONMSG_TO_US */
/*  Tell lightningd we got an obsolete onion message (for us */
u8 *towire_gossipd_got_obs_onionmsg_to_us(const tal_t *ctx, const struct pubkey *blinding_in, const struct pubkey *reply_blinding, const struct onionmsg_path **reply_path, const u8 *rawmsg);
bool fromwire_gossipd_got_obs_onionmsg_to_us(const tal_t *ctx, const void *p, struct pubkey **blinding_in, struct pubkey **reply_blinding, struct onionmsg_path ***reply_path, u8 **rawmsg);

/* WIRE: GOSSIPD_GOT_OBS_ONIONMSG_FORWARD */
u8 *towire_gossipd_got_obs_onionmsg_forward(const tal_t *ctx, const struct short_channel_id *next_scid, const struct node_id *next_node_id, const struct pubkey *next_blinding, const u8 *next_onion);
bool fromwire_gossipd_got_obs_onionmsg_forward(const tal_t *ctx, const void *p, struct short_channel_id **next_scid, struct node_id **next_node_id, struct pubkey **next_blinding, u8 **next_onion);

/* WIRE: GOSSIPD_SEND_OBS_ONIONMSG */
/*  Lightningd tells us to send a onion message. */
u8 *towire_gossipd_send_obs_onionmsg(const tal_t *ctx, const struct node_id *id, const u8 *onion, const struct pubkey *blinding);
bool fromwire_gossipd_send_obs_onionmsg(const tal_t *ctx, const void *p, struct node_id *id, u8 **onion, struct pubkey **blinding);

/* WIRE: GOSSIPD_ADDGOSSIP */
/*  Lightningd tells us to inject a gossip message (for addgossip RPC) */
u8 *towire_gossipd_addgossip(const tal_t *ctx, const u8 *msg);
bool fromwire_gossipd_addgossip(const tal_t *ctx, const void *p, u8 **msg);

/* WIRE: GOSSIPD_ADDGOSSIP_REPLY */
/*  Empty string means no problem. */
u8 *towire_gossipd_addgossip_reply(const tal_t *ctx, const wirestring *err);
bool fromwire_gossipd_addgossip_reply(const tal_t *ctx, const void *p, wirestring **err);

/* WIRE: GOSSIPD_NEW_LEASE_RATES */
/*  Updated lease rates available */
u8 *towire_gossipd_new_lease_rates(const tal_t *ctx, const struct lease_rates *rates);
bool fromwire_gossipd_new_lease_rates(const void *p, struct lease_rates *rates);


#endif /* LIGHTNING_GOSSIPD_GOSSIPD_WIREGEN_H */
// SHA256STAMP:d06e71483fdad04048e15d46b823420747d5f79efc97fa968752fa04b033d551
