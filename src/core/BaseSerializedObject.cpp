//
// Created by ns on 7/20/20.
//

#include "../GameConfig.h"
#include "BaseSerializedObject.h"

bool BaseSerializedObject::Save()
{
    // TODO: serialize and save object to storage method from config

    // const auto& storage_conf = game_config.get_storage_config();
    // GameStorage gs(storage_conf.get_type());

    // std::istream in = gs.getWriteStream();

    // SerializeMe(in);

    return true;
}

bool BaseSerializedObject::Load()
{
    // TODO: deserialize and load object from storage method from config

    // const auto& storage_conf = game_config.get_storage_config();
    // GameStorage gs(storage_conf.get_type());

    // std::ostream out = gs.getReadStream();

    // SerializeMe(out);

    return true;
}
