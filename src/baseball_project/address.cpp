#include "address.h"


Address::Address():street(""), city(""), state(""), zip_code("")
{
    //intentionally left empty
}


Address::Address(string init_street,
                 string init_city,
                 string init_state,
                 string init_zip_code){
    street = init_street;
    city = init_city;
    state = init_state;
    zip_code = init_zip_code;
}
