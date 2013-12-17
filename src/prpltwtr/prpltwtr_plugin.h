#ifndef _TWITTER_PLUGIN_H_
#define _TWITTER_PLUGIN_H_

typedef struct _TwitterEndpoint {
    int             rate_limit_total;
    int             rate_limit_remaining;
	time_t          rate_limit_reset;
	const gchar *url;
} TwitterEndpoint;
typedef struct {
    TwitterEndpoint get_rate_limit_status;
    TwitterEndpoint get_friends;
    TwitterEndpoint get_home_timeline;
    TwitterEndpoint get_mentions;
    TwitterEndpoint get_dms;
    TwitterEndpoint update_status;
    TwitterEndpoint new_dm;
    TwitterEndpoint get_saved_searches;
    TwitterEndpoint get_subscribed_lists;
    TwitterEndpoint get_personal_lists;
    TwitterEndpoint get_search_results;
    TwitterEndpoint verify_credentials;
    TwitterEndpoint report_spammer;
    TwitterEndpoint add_favorite;
    TwitterEndpoint delete_favorite;
    TwitterEndpoint get_user_info;
} TwitterUrls;

void            twitter_destroy(PurplePlugin * plugin);
void            twitter_tooltip_text(PurpleBuddy * buddy, PurpleNotifyUserInfo * info, gboolean full);
GList          *twitter_actions(PurplePlugin * plugin, gpointer context);
GHashTable     *prpltwtr_get_account_text_table_statusnet(PurpleAccount * account);
const char     *twitter_list_icon(PurpleAccount * account, PurpleBuddy * buddy);
char           *twitter_status_text(PurpleBuddy * buddy);
GList          *twitter_status_types(PurpleAccount * account);
GList          *twitter_blist_node_menu(PurpleBlistNode * node);
GList          *twitter_chat_info(PurpleConnection * gc);
GHashTable     *twitter_chat_info_defaults(PurpleConnection * gc, const char *chat_name);
void            twitter_close(PurpleConnection * gc);
int             twitter_send_im(PurpleConnection * gc, const char *conv_name, const char *message, PurpleMessageFlags flags);
void            twitter_set_info(PurpleConnection * gc, const char *info);
void            twitter_set_status(PurpleAccount * account, PurpleStatus * status);
void            twitter_add_buddy(PurpleConnection * gc, PurpleBuddy * buddy, PurpleGroup * group);
void            twitter_add_buddies(PurpleConnection * gc, GList * buddies, GList * groups);
void            twitter_remove_buddy(PurpleConnection * gc, PurpleBuddy * buddy, PurpleGroup * group);
void            twitter_remove_buddies(PurpleConnection * gc, GList * buddies, GList * groups);
void            twitter_chat_join(PurpleConnection * gc, GHashTable * components);
void            twitter_chat_leave(PurpleConnection * gc, int id);
int             twitter_chat_send(PurpleConnection * gc, int id, const char *message, PurpleMessageFlags flags);
void            twitter_get_cb_info(PurpleConnection * gc, int id, const char *who);
char           *twitter_chat_get_name(GHashTable * components);
void            twitter_convo_closed(PurpleConnection * gc, const gchar * conv_name);
void            twitter_set_buddy_icon(PurpleConnection * gc, PurpleStoredImage * img);
void            prpltwtr_plugin_init(PurplePlugin * plugin);

#endif
