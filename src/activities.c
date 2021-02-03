#include "activities.h"

GDCALLINGCONV void *activity_timestamps_constructor(godot_object *p_instance, Library *p_lib)
{
    INIT_OBJECT(timestamps,
                ActivityTimestamps, struct DiscordActivityTimestamps,
                p_lib, p_instance);

    return timestamps;
}

GDCALLINGCONV void activity_timestamps_destructor(godot_object *p_instance, Library *p_lib,
                                                  ActivityTimestamps *p_timestamps)
{
    p_lib->api->godot_free(p_timestamps->internal);
    p_lib->api->godot_free(p_timestamps);
}

godot_variant activity_timestamps_get_start(godot_object *p_instance, Library *p_lib,
                                            ActivityTimestamps *p_timestamps)
{
    godot_variant start;

    p_lib->api->godot_variant_new_int(&start, p_timestamps->internal->start);

    return start;
}

GDCALLINGCONV void activity_timestamps_set_start(godot_object *p_instance, Library *p_lib,
                                                 ActivityTimestamps *p_timestamps,
                                                 godot_variant *p_start)
{
    p_timestamps->internal->start = p_lib->api->godot_variant_as_int(p_start);
}

godot_variant activity_timestamps_get_end(godot_object *p_instance, Library *p_lib,
                                          ActivityTimestamps *p_timestamps)
{
    godot_variant end;

    p_lib->api->godot_variant_new_int(&end, p_timestamps->internal->end);

    return end;
}

GDCALLINGCONV void activity_timestamps_set_end(godot_object *p_instance, Library *p_lib,
                                               ActivityTimestamps *p_timestamps,
                                               godot_variant *p_end)
{
    p_timestamps->internal->end = p_lib->api->godot_variant_as_int(p_end);
}

void register_activity_timestamps(void *p_handle, Library *p_lib)
{
    godot_instance_create_func constructor;
    memset(&constructor, 0, sizeof(godot_instance_create_func));
    constructor.create_func = activity_timestamps_constructor;
    constructor.method_data = p_lib;

    godot_instance_destroy_func destructor;
    memset(&destructor, 0, sizeof(godot_instance_destroy_func));
    destructor.destroy_func = activity_timestamps_destructor;
    destructor.method_data = p_lib;

    p_lib->nativescript_api->godot_nativescript_register_class(p_handle,
                                                               "ActivityTimestamps", "Resource",
                                                               constructor, destructor);

    // Attributes
    {
        godot_property_attributes attributes;
        godot_variant default_value;
        godot_property_get_func get;
        godot_property_set_func set;

        // Start
        {
            memset(&attributes, 0, sizeof(godot_property_attributes));
            attributes.type = GODOT_VARIANT_TYPE_INT;
            attributes.usage = GODOT_PROPERTY_USAGE_DEFAULT;
            attributes.rset_type = GODOT_METHOD_RPC_MODE_DISABLED;

            attributes.hint = GODOT_PROPERTY_HINT_NONE;
            attributes.hint_string = p_lib->api->godot_string_chars_to_utf8("");

            p_lib->api->godot_variant_new_int(&default_value, 0);
            attributes.default_value = default_value;

            memset(&get, 0, sizeof(godot_property_get_func));
            get.get_func = activity_timestamps_get_start;
            get.method_data = p_lib;

            memset(&set, 0, sizeof(godot_property_set_func));
            set.set_func = activity_timestamps_set_start;
            set.method_data = p_lib;

            p_lib->nativescript_api->godot_nativescript_register_property(p_handle,
                                                                          "ActivityTimestamps", "start",
                                                                          &attributes,
                                                                          set, get);
        }
        // End
        {
            memset(&attributes, 0, sizeof(godot_property_attributes));
            attributes.type = GODOT_VARIANT_TYPE_INT;
            attributes.usage = GODOT_PROPERTY_USAGE_DEFAULT;
            attributes.rset_type = GODOT_METHOD_RPC_MODE_DISABLED;

            attributes.hint = GODOT_PROPERTY_HINT_NONE;
            attributes.hint_string = p_lib->api->godot_string_chars_to_utf8("");

            p_lib->api->godot_variant_new_int(&default_value, 0);
            attributes.default_value = default_value;

            memset(&get, 0, sizeof(godot_property_get_func));
            get.get_func = activity_timestamps_get_end;
            get.method_data = p_lib;

            memset(&set, 0, sizeof(godot_property_set_func));
            set.set_func = activity_timestamps_set_end;
            set.method_data = p_lib;

            p_lib->nativescript_api->godot_nativescript_register_property(p_handle,
                                                                          "ActivityTimestamps", "end",
                                                                          &attributes,
                                                                          set, get);
        }
    }
}

GDCALLINGCONV void *activity_assets_constructor(godot_object *p_instance, Library *p_lib)
{
    INIT_OBJECT(assets,
                ActivityAssets, struct DiscordActivityAssets,
                p_lib, p_instance);

    return assets;
}

GDCALLINGCONV void activity_assets_destructor(godot_object *p_instance, Library *p_lib,
                                              ActivityAssets *p_assets)
{
    p_lib->api->godot_free(p_assets->internal);
    p_lib->api->godot_free(p_assets);
}

godot_variant activity_assets_get_large_image(godot_object *p_instance, Library *p_lib,
                                              ActivityAssets *p_assets)
{
    godot_variant large_image;

    godot_string string = p_lib->api->godot_string_chars_to_utf8(p_assets->internal->large_image);
    p_lib->api->godot_variant_new_string(&large_image, &string);
    p_lib->api->godot_string_destroy(&string);

    return large_image;
}

GDCALLINGCONV void activity_assets_set_large_image(godot_object *p_instance, Library *p_lib,
                                                   ActivityAssets *p_assets,
                                                   godot_variant *p_large_image)
{
    godot_string string = p_lib->api->godot_variant_as_string(p_large_image);
    godot_char_string char_string = p_lib->api->godot_string_utf8(&string);
    const char *large_image = p_lib->api->godot_char_string_get_data(&char_string);

    int size = p_lib->api->godot_char_string_length(&char_string);

    memset(p_assets->internal->large_image, 0, sizeof(char) * 128);
    memcpy(p_assets->internal->large_image, large_image, sizeof(char) * MIN(size, 127));
}

godot_variant activity_assets_get_large_text(godot_object *p_instance, Library *p_lib,
                                             ActivityAssets *p_assets)
{
    godot_variant large_text;

    godot_string string = p_lib->api->godot_string_chars_to_utf8(p_assets->internal->large_text);
    p_lib->api->godot_variant_new_string(&large_text, &string);
    p_lib->api->godot_string_destroy(&string);

    return large_text;
}

GDCALLINGCONV void activity_assets_set_large_text(godot_object *p_instance, Library *p_lib,
                                                  ActivityAssets *p_assets,
                                                  godot_variant *p_large_text)
{
    godot_string string = p_lib->api->godot_variant_as_string(p_large_text);
    godot_char_string char_string = p_lib->api->godot_string_utf8(&string);
    const char *large_text = p_lib->api->godot_char_string_get_data(&char_string);

    int size = p_lib->api->godot_char_string_length(&char_string);

    memset(p_assets->internal->large_text, 0, sizeof(char) * 128);
    memcpy(p_assets->internal->large_text, large_text, sizeof(char) * MIN(size, 127));
}

godot_variant activity_assets_get_small_image(godot_object *p_instance, Library *p_lib,
                                              ActivityAssets *p_assets)
{
    godot_variant small_image;

    godot_string string = p_lib->api->godot_string_chars_to_utf8(p_assets->internal->small_image);
    p_lib->api->godot_variant_new_string(&small_image, &string);
    p_lib->api->godot_string_destroy(&string);

    return small_image;
}

GDCALLINGCONV void activity_assets_set_small_image(godot_object *p_instance, Library *p_lib,
                                                   ActivityAssets *p_assets,
                                                   godot_variant *p_small_image)
{
    godot_string string = p_lib->api->godot_variant_as_string(p_small_image);
    godot_char_string char_string = p_lib->api->godot_string_utf8(&string);
    const char *small_image = p_lib->api->godot_char_string_get_data(&char_string);

    int size = p_lib->api->godot_char_string_length(&char_string);

    memset(p_assets->internal->small_image, 0, sizeof(char) * 128);
    memcpy(p_assets->internal->small_image, small_image, sizeof(char) * MIN(size, 127));
}

godot_variant activity_assets_get_small_text(godot_object *p_instance, Library *p_lib,
                                             ActivityAssets *p_assets)
{
    godot_variant small_text;

    godot_string string = p_lib->api->godot_string_chars_to_utf8(p_assets->internal->small_text);
    p_lib->api->godot_variant_new_string(&small_text, &string);
    p_lib->api->godot_string_destroy(&string);

    return small_text;
}

GDCALLINGCONV void activity_assets_set_small_text(godot_object *p_instance, Library *p_lib,
                                                  ActivityAssets *p_assets,
                                                  godot_variant *p_small_text)
{
    godot_string string = p_lib->api->godot_variant_as_string(p_small_text);
    godot_char_string char_string = p_lib->api->godot_string_utf8(&string);
    const char *small_text = p_lib->api->godot_char_string_get_data(&char_string);

    int size = p_lib->api->godot_char_string_length(&char_string);

    memset(p_assets->internal->small_text, 0, sizeof(char) * 128);
    memcpy(p_assets->internal->small_text, small_text, sizeof(char) * MIN(size, 127));
}

void register_activity_assets(void *p_handle, Library *p_lib)
{
    godot_instance_create_func constructor;
    memset(&constructor, 0, sizeof(godot_instance_create_func));
    constructor.create_func = activity_assets_constructor;
    constructor.method_data = p_lib;

    godot_instance_destroy_func destructor;
    memset(&destructor, 0, sizeof(godot_instance_destroy_func));
    destructor.destroy_func = activity_assets_destructor;
    destructor.method_data = p_lib;

    p_lib->nativescript_api->godot_nativescript_register_class(p_handle,
                                                               "ActivityAssets", "Resource",
                                                               constructor, destructor);

    // Attributes
    {
        godot_property_attributes attributes;
        godot_variant default_value;
        godot_property_get_func get;
        godot_property_set_func set;

        // Large Image
        {
            memset(&attributes, 0, sizeof(godot_property_attributes));
            attributes.type = GODOT_VARIANT_TYPE_STRING;
            attributes.usage = GODOT_PROPERTY_USAGE_DEFAULT;
            attributes.rset_type = GODOT_METHOD_RPC_MODE_DISABLED;

            attributes.hint = GODOT_PROPERTY_HINT_NONE;
            attributes.hint_string = p_lib->api->godot_string_chars_to_utf8("");

            godot_string string = p_lib->api->godot_string_chars_to_utf8("");
            p_lib->api->godot_variant_new_string(&default_value, &string);
            attributes.default_value = default_value;

            memset(&get, 0, sizeof(godot_property_get_func));
            get.get_func = activity_assets_get_large_image;
            get.method_data = p_lib;

            memset(&set, 0, sizeof(godot_property_set_func));
            set.set_func = activity_assets_set_large_image;
            set.method_data = p_lib;

            p_lib->nativescript_api->godot_nativescript_register_property(p_handle,
                                                                          "ActivityAssets", "large_image",
                                                                          &attributes,
                                                                          set, get);
        }
        // Large Text
        {
            memset(&attributes, 0, sizeof(godot_property_attributes));
            attributes.type = GODOT_VARIANT_TYPE_STRING;
            attributes.usage = GODOT_PROPERTY_USAGE_DEFAULT;
            attributes.rset_type = GODOT_METHOD_RPC_MODE_DISABLED;

            attributes.hint = GODOT_PROPERTY_HINT_NONE;
            attributes.hint_string = p_lib->api->godot_string_chars_to_utf8("");

            godot_string string = p_lib->api->godot_string_chars_to_utf8("");
            p_lib->api->godot_variant_new_string(&default_value, &string);
            attributes.default_value = default_value;

            memset(&get, 0, sizeof(godot_property_get_func));
            get.get_func = activity_assets_get_large_text;
            get.method_data = p_lib;

            memset(&set, 0, sizeof(godot_property_set_func));
            set.set_func = activity_assets_set_large_text;
            set.method_data = p_lib;

            p_lib->nativescript_api->godot_nativescript_register_property(p_handle,
                                                                          "ActivityAssets", "large_text",
                                                                          &attributes,
                                                                          set, get);
        }
        // Small Image
        {
            memset(&attributes, 0, sizeof(godot_property_attributes));
            attributes.type = GODOT_VARIANT_TYPE_STRING;
            attributes.usage = GODOT_PROPERTY_USAGE_DEFAULT;
            attributes.rset_type = GODOT_METHOD_RPC_MODE_DISABLED;

            attributes.hint = GODOT_PROPERTY_HINT_NONE;
            attributes.hint_string = p_lib->api->godot_string_chars_to_utf8("");

            godot_string string = p_lib->api->godot_string_chars_to_utf8("");
            p_lib->api->godot_variant_new_string(&default_value, &string);
            attributes.default_value = default_value;

            memset(&get, 0, sizeof(godot_property_get_func));
            get.get_func = activity_assets_get_small_image;
            get.method_data = p_lib;

            memset(&set, 0, sizeof(godot_property_set_func));
            set.set_func = activity_assets_set_small_image;
            set.method_data = p_lib;

            p_lib->nativescript_api->godot_nativescript_register_property(p_handle,
                                                                          "ActivityAssets", "small_image",
                                                                          &attributes,
                                                                          set, get);
        }
        // Small Text
        {
            memset(&attributes, 0, sizeof(godot_property_attributes));
            attributes.type = GODOT_VARIANT_TYPE_STRING;
            attributes.usage = GODOT_PROPERTY_USAGE_DEFAULT;
            attributes.rset_type = GODOT_METHOD_RPC_MODE_DISABLED;

            attributes.hint = GODOT_PROPERTY_HINT_NONE;
            attributes.hint_string = p_lib->api->godot_string_chars_to_utf8("");

            godot_string string = p_lib->api->godot_string_chars_to_utf8("");
            p_lib->api->godot_variant_new_string(&default_value, &string);
            attributes.default_value = default_value;

            memset(&get, 0, sizeof(godot_property_get_func));
            get.get_func = activity_assets_get_small_text;
            get.method_data = p_lib;

            memset(&set, 0, sizeof(godot_property_set_func));
            set.set_func = activity_assets_set_small_text;
            set.method_data = p_lib;

            p_lib->nativescript_api->godot_nativescript_register_property(p_handle,
                                                                          "ActivityAssets", "small_text",
                                                                          &attributes,
                                                                          set, get);
        }
    }
}

GDCALLINGCONV void *party_size_constructor(godot_object *p_instance, Library *p_lib)
{
    INIT_OBJECT(party_size,
                PartySize, struct DiscordPartySize,
                p_lib, p_instance);

    return party_size;
}

GDCALLINGCONV void party_size_destructor(godot_object *p_instance, Library *p_lib,
                                         PartySize *p_party_size)
{
    p_lib->api->godot_free(p_party_size->internal);
    p_lib->api->godot_free(p_party_size);
}

godot_variant party_size_get_current_size(godot_object *p_instance, Library *p_lib,
                                          PartySize *p_party_size)
{
    godot_variant current_size;

    p_lib->api->godot_variant_new_int(&current_size, p_party_size->internal->current_size);

    return current_size;
}

GDCALLINGCONV void party_size_set_current_size(godot_object *p_instance, Library *p_lib,
                                               PartySize *p_party_size,
                                               godot_variant *p_current_size)
{
    p_party_size->internal->current_size = (int32_t)p_lib->api->godot_variant_as_int(p_current_size);
}

godot_variant party_size_get_max_size(godot_object *p_instance, Library *p_lib,
                                      PartySize *p_party_size)
{
    godot_variant max_size;

    p_lib->api->godot_variant_new_int(&max_size, p_party_size->internal->max_size);

    return max_size;
}

GDCALLINGCONV void party_size_set_max_size(godot_object *p_instance, Library *p_lib,
                                           PartySize *p_party_size,
                                           godot_variant *p_max_size)
{
    p_party_size->internal->max_size = (int32_t)p_lib->api->godot_variant_as_int(p_max_size);
}

void register_party_size(void *p_handle, Library *p_lib)
{
    godot_instance_create_func constructor;
    memset(&constructor, 0, sizeof(godot_instance_create_func));
    constructor.create_func = party_size_constructor;
    constructor.method_data = p_lib;

    godot_instance_destroy_func destructor;
    memset(&destructor, 0, sizeof(godot_instance_destroy_func));
    destructor.destroy_func = party_size_destructor;
    destructor.method_data = p_lib;

    p_lib->nativescript_api->godot_nativescript_register_class(p_handle,
                                                               "PartySize", "Resource",
                                                               constructor, destructor);

    // Attributes
    {
        godot_property_attributes attributes;
        godot_variant default_value;
        godot_property_get_func get;
        godot_property_set_func set;

        // Current Size
        {
            memset(&attributes, 0, sizeof(godot_property_attributes));
            attributes.type = GODOT_VARIANT_TYPE_INT;
            attributes.usage = GODOT_PROPERTY_USAGE_DEFAULT;
            attributes.rset_type = GODOT_METHOD_RPC_MODE_DISABLED;

            attributes.hint = GODOT_PROPERTY_HINT_NONE;
            attributes.hint_string = p_lib->api->godot_string_chars_to_utf8("");

            p_lib->api->godot_variant_new_int(&default_value, 0);
            attributes.default_value = default_value;

            memset(&get, 0, sizeof(godot_property_get_func));
            get.get_func = party_size_get_current_size;
            get.method_data = p_lib;

            memset(&set, 0, sizeof(godot_property_set_func));
            set.set_func = party_size_set_current_size;
            set.method_data = p_lib;

            p_lib->nativescript_api->godot_nativescript_register_property(p_handle,
                                                                          "PartySize", "current_size",
                                                                          &attributes,
                                                                          set, get);
        }
        // Max Size
        {
            memset(&attributes, 0, sizeof(godot_property_attributes));
            attributes.type = GODOT_VARIANT_TYPE_INT;
            attributes.usage = GODOT_PROPERTY_USAGE_DEFAULT;
            attributes.rset_type = GODOT_METHOD_RPC_MODE_DISABLED;

            attributes.hint = GODOT_PROPERTY_HINT_NONE;
            attributes.hint_string = p_lib->api->godot_string_chars_to_utf8("");

            p_lib->api->godot_variant_new_int(&default_value, 0);
            attributes.default_value = default_value;

            memset(&get, 0, sizeof(godot_property_get_func));
            get.get_func = party_size_get_max_size;
            get.method_data = p_lib;

            memset(&set, 0, sizeof(godot_property_set_func));
            set.set_func = party_size_set_max_size;
            set.method_data = p_lib;

            p_lib->nativescript_api->godot_nativescript_register_property(p_handle,
                                                                          "PartySize", "max_size",
                                                                          &attributes,
                                                                          set, get);
        }
    }
}

GDCALLINGCONV void *activity_party_constructor(godot_object *p_instance, Library *p_lib)
{
    INIT_OBJECT(party,
                ActivityParty, struct DiscordActivityParty,
                p_lib, p_instance);

    party->size = instantiate_custom_class("PartySize", "Resource", p_lib);
    godot_reference(party->size, p_lib);

    PartySize *size_data = p_lib->nativescript_api->godot_nativescript_get_userdata(party->size);
    p_lib->api->godot_free(size_data->internal);

    size_data->internal = &party->internal->size;
    size_data->bound = true;

    return party;
}

GDCALLINGCONV void activity_party_destructor(godot_object *p_instance, Library *p_lib,
                                             ActivityParty *p_activity_party)
{
    if (p_activity_party->size)
    {
        PartySize *size_data = p_lib->nativescript_api->godot_nativescript_get_userdata(p_activity_party->size);
        size_data->internal = p_lib->api->godot_alloc(sizeof(struct DiscordPartySize));
        memcpy(size_data->internal, &p_activity_party->internal->size, sizeof(struct DiscordPartySize));

        size_data->bound = false;

        godot_unreference(p_activity_party->size, p_lib);
    }

    p_lib->api->godot_free(p_activity_party->internal);
    p_lib->api->godot_free(p_activity_party);
}

godot_variant activity_party_get_id(godot_object *p_instance, Library *p_lib,
                                    ActivityParty *p_activity_party)
{
    godot_variant id;

    godot_string string = p_lib->api->godot_string_chars_to_utf8(p_activity_party->internal->id);
    p_lib->api->godot_variant_new_string(&id, &string);
    p_lib->api->godot_string_destroy(&string);

    return id;
}

GDCALLINGCONV void activity_party_set_id(godot_object *p_instance, Library *p_lib,
                                         ActivityParty *p_activity_party,
                                         godot_variant *p_id)
{
    godot_string string = p_lib->api->godot_variant_as_string(p_id);
    godot_char_string char_string = p_lib->api->godot_string_utf8(&string);
    const char *id = p_lib->api->godot_char_string_get_data(&char_string);

    int size = p_lib->api->godot_char_string_length(&char_string);

    memset(p_activity_party->internal->id, 0, sizeof(char) * 128);
    memcpy(p_activity_party->internal->id, id, sizeof(char) * MIN(size, 127));
}

godot_variant activity_party_get_privacy(godot_object *p_instance, Library *p_lib,
                                         ActivityParty *p_activity_party)
{
    godot_variant privacy;

    p_lib->api->godot_variant_new_int(&privacy, p_activity_party->internal->privacy);

    return privacy;
}

GDCALLINGCONV void activity_party_set_privacy(godot_object *p_instance, Library *p_lib,
                                              ActivityParty *p_activity_party,
                                              godot_variant *p_privacy)
{
    p_activity_party->internal->privacy = p_lib->api->godot_variant_as_int(p_privacy);
}

godot_variant activity_party_get_size(godot_object *p_instance, Library *p_lib,
                                      ActivityParty *p_activity_party)
{
    godot_variant size;

    p_lib->api->godot_variant_new_object(&size, p_activity_party->size);

    return size;
}

GDCALLINGCONV void activity_party_set_size(godot_object *p_instance, Library *p_lib,
                                           ActivityParty *p_activity_party,
                                           godot_variant *p_size)
{
    if (p_activity_party->size)
    {
        godot_unreference(p_activity_party->size, p_lib);

        PartySize *size_data = p_lib->nativescript_api->godot_nativescript_get_userdata(p_activity_party->size);
        size_data->internal = p_lib->api->godot_alloc(sizeof(struct DiscordPartySize));
        memcpy(size_data->internal, &p_activity_party->internal->size, sizeof(struct DiscordPartySize));

        size_data->bound = false;
    }

    p_activity_party->size = p_lib->api->godot_variant_as_object(p_size);

    if (p_activity_party->size)
    {
        godot_reference(p_activity_party->size, p_lib);

        PartySize *size_data = p_lib->nativescript_api->godot_nativescript_get_userdata(p_activity_party->size);
        memcpy(&p_activity_party->internal->size, size_data->internal, sizeof(struct DiscordPartySize));

        if (!size_data->bound)
            p_lib->api->godot_free(size_data->internal);
        size_data->internal = &p_activity_party->internal->size;

        size_data->bound = true;
    }
}

void register_activity_party(void *p_handle, Library *p_lib)
{
    godot_instance_create_func constructor;
    memset(&constructor, 0, sizeof(godot_instance_create_func));
    constructor.create_func = activity_party_constructor;
    constructor.method_data = p_lib;

    godot_instance_destroy_func destructor;
    memset(&destructor, 0, sizeof(godot_instance_destroy_func));
    destructor.destroy_func = activity_party_destructor;
    destructor.method_data = p_lib;

    p_lib->nativescript_api->godot_nativescript_register_class(p_handle,
                                                               "ActivityParty", "Resource",
                                                               constructor, destructor);

    // Attributes
    {
        godot_property_attributes attributes;
        godot_variant default_value;
        godot_property_get_func get;
        godot_property_set_func set;

        // ID
        {
            memset(&attributes, 0, sizeof(godot_property_attributes));
            attributes.type = GODOT_VARIANT_TYPE_STRING;
            attributes.usage = GODOT_PROPERTY_USAGE_DEFAULT;
            attributes.rset_type = GODOT_METHOD_RPC_MODE_DISABLED;

            attributes.hint = GODOT_PROPERTY_HINT_NONE;
            attributes.hint_string = p_lib->api->godot_string_chars_to_utf8("");

            godot_string string = p_lib->api->godot_string_chars_to_utf8("");
            p_lib->api->godot_variant_new_string(&default_value, &string);
            attributes.default_value = default_value;

            memset(&get, 0, sizeof(godot_property_get_func));
            get.get_func = activity_party_get_id;
            get.method_data = p_lib;

            memset(&set, 0, sizeof(godot_property_set_func));
            set.set_func = activity_party_set_id;
            set.method_data = p_lib;

            p_lib->nativescript_api->godot_nativescript_register_property(p_handle,
                                                                          "ActivityParty", "id",
                                                                          &attributes,
                                                                          set, get);
        }
        // Privacy
        {
            memset(&attributes, 0, sizeof(godot_property_attributes));
            attributes.type = GODOT_VARIANT_TYPE_INT;
            attributes.usage = GODOT_PROPERTY_USAGE_DEFAULT;
            attributes.rset_type = GODOT_METHOD_RPC_MODE_DISABLED;

            attributes.hint = GODOT_PROPERTY_HINT_ENUM;
            attributes.hint_string = p_lib->api->godot_string_chars_to_utf8("Private,Public");

            p_lib->api->godot_variant_new_int(&default_value, DiscordActivityPartyPrivacy_Private);
            attributes.default_value = default_value;

            memset(&get, 0, sizeof(godot_property_get_func));
            get.get_func = activity_party_get_privacy;
            get.method_data = p_lib;

            memset(&set, 0, sizeof(godot_property_set_func));
            set.set_func = activity_party_set_privacy;
            set.method_data = p_lib;

            p_lib->nativescript_api->godot_nativescript_register_property(p_handle,
                                                                          "ActivityParty", "privacy",
                                                                          &attributes,
                                                                          set, get);
        }
        // Size
        {
            memset(&attributes, 0, sizeof(godot_property_attributes));
            attributes.type = GODOT_VARIANT_TYPE_OBJECT;
            attributes.usage = GODOT_PROPERTY_USAGE_DEFAULT;
            attributes.rset_type = GODOT_METHOD_RPC_MODE_DISABLED;

            attributes.hint = GODOT_PROPERTY_HINT_NONE;
            attributes.hint_string = p_lib->api->godot_string_chars_to_utf8("");

            p_lib->api->godot_variant_new_nil(&default_value);
            attributes.default_value = default_value;

            memset(&get, 0, sizeof(godot_property_get_func));
            get.get_func = activity_party_get_size;
            get.method_data = p_lib;

            memset(&set, 0, sizeof(godot_property_set_func));
            set.set_func = activity_party_set_size;
            set.method_data = p_lib;

            p_lib->nativescript_api->godot_nativescript_register_property(p_handle,
                                                                          "ActivityParty", "size",
                                                                          &attributes,
                                                                          set, get);
        }
    }
}
