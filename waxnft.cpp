#include <eosio/eosio.hpp>

using namespace eosio;

CONTRACT waxnft : public eosio::contract{
public:
    using contract::contract;

    ACTION createnft() {

        //assign asset attributes
        name author = get_self();
        name category = "sticker"_n;
        name owner = "waxnftowner1"_n;
        std::string idata = R"json({"name": "WAX Developer Hive", "desc" : "WAX Developer Hive Sticker" })json";
        std::string mdata = R"json({"color": "black", "img" : "https://developer.wax.io/img/wax_sticker.png" })json";
        bool requireClaim = false;

        //call the simpleassets create action
        action(
            { author, "active"_n },
            "simpleassets"_n,
            "create"_n,
            std::tuple(author, category, owner, idata, mdata, requireClaim)
        )
        .send();

    }
};

EOSIO_DISPATCH(waxnft, (createnft))